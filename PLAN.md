# OpenEggbert.com — Refactoring Plan

## 1. Current State Analysis

### What the site is
A static HTML fan-community website for the Speedy Blupi / Open Eggbert game series, hosted (likely via GitHub Pages) without any build toolchain. There are no frameworks, no bundlers — just raw HTML files, one shared `styles.css`, and one shared `script.js`, all residing at the repository root.

### Size
- **127 HTML files** spread across approximately **129 directories**
- Maximum directory depth: **6 levels** (e.g. `Blupi/Games/Speedy_Blupi_(Windows)/Levels/I/060/index.html`)
- One `Template/index.html` used as a copy-paste starting point for new pages
- One special `tree.html` at root (full article tree, no shared boilerplate — standalone page)

### URL / directory convention
Every article lives at `<Category>/<Subcategory>/.../index.html`. All asset references (CSS, JS, favicon) are resolved via `<base href="…">` pointing back to the site root, so all links inside a page are written as absolute-from-root paths regardless of how deep the file sits.

---

## 2. Identified Duplications

Every single `index.html` (except `tree.html`) contains the following **identical blocks**:

### 2a. `<head>` block (~16 lines, mostly static)
```html
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta name="description" content="Open Eggbert, a free and open-source game…"/>
<meta name="keywords" content="Blupi, Speedy Blupi, Speedy Eggbert, …"/>
<meta name="author" content="Robert Vokáč">
<link rel="stylesheet" href="styles.css">
<link rel="icon" href="favicon.ico" type="image/x-icon" sizes="32x32">
<script type="text/javascript" src="script.js"></script>
```
**Only two things differ:** `<title>` text and `<base href="…">` depth.

### 2b. `<header>` + `<nav>` block (~12 lines, 100% identical)
```html
<header>
  <div id="main_banner"><a href="index.html">Open Eggbert</a></div>
  <nav>
    <ul>
      <li><a href="index.html">Home</a></li>
      <li><a href="About/index.html">About</a></li>
      <li><a href="Blupi/index.html">Blupi</a></li>
      <li><a href="Projects/index.html">Projects</a></li>
      <li><a href="Technologies/index.html">Technologies</a></li>
    </ul>
  </nav>
</header>
```
Repeated in all 126 article pages.

### 2c. `<footer>` block (~5 lines, 100% identical)
```html
<footer>
  <p>Content is available under <a href="https://creativecommons.org/licenses/by-sa/4.0/" …>
    Creative Commons Attribution-ShareAlike 4.0 International License</a> unless otherwise noted.</p>
</footer>
```
Repeated in all 126 article pages.

### 2d. `<body onload="loadContent()">` + TOC placeholders
```html
<body onload="loadContent()">
…
<div id="tocButton"></div>
<div id="toc"></div>
```
The TOC div pair appears inside `<main>` on every article page.

### 2e. `#breadcrumb_hierarchy_panel` structure
The outer HTML structure is always the same:
```html
<div id="breadcrumb_hierarchy_panel">
  <div id="breadcrumb"> … </div>
  <div id="hierarchy_panel"> … </div>
</div>
```
Only the inner links differ (breadcrumb chain and list of child pages).

### Summary of per-file uniqueness
| Element | Unique per page? |
|---|---|
| `<title>` | Yes |
| `<base href>` | Yes (depth varies) |
| `<header>` / `<nav>` | No — identical everywhere |
| `<footer>` | No — identical everywhere |
| Breadcrumb links | Yes |
| Hierarchy panel links | Yes |
| `<main>` content | Yes — all article text |

---

## 3. Proposed Refactoring Approach

### Strategy: JavaScript-injected shell + data-driven navigation

No build step is introduced. All pages remain plain `.html` files. The shared boilerplate (header, nav, footer) is removed from every page and instead injected by `script.js` at page-load time.

Each article page is reduced to a **minimal shell**:

```
DOCTYPE + <html>
  <head>               ← only title, base href, CSS/JS refs
  <body>               ← NO header/footer markup
    <script>           ← small inline config object (breadcrumb + subpages)
    PAGE_CONFIG = { … };
    </script>
    <main>
      <section>
        <h1>…</h1>
        <!-- article content only -->
      </section>
    </main>
```

`script.js` is extended to:
1. Read `PAGE_CONFIG` before injecting.
2. `document.body.insertAdjacentHTML('afterbegin', headerHTML)` — inject `<header>` + `<nav>` at top.
3. Build `#breadcrumb_hierarchy_panel` from `PAGE_CONFIG.breadcrumb` and `PAGE_CONFIG.subpages`.
4. `document.body.insertAdjacentHTML('beforeend', footerHTML)` — inject `<footer>`.
5. Run the existing TOC logic (already in `loadContent()`).

### What the minimal page shell looks like (new Template)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Open Eggbert - ARTICLE_TITLE</title>
  <base href="RELATIVE_PATH_TO_ROOT" target="_self">
  <link rel="stylesheet" href="styles.css">
  <link rel="icon" href="favicon.ico" type="image/x-icon" sizes="32x32">
  <script src="script.js"></script>
</head>
<body>
<script>
PAGE_CONFIG = {
  title: "ARTICLE_TITLE",
  breadcrumb: [
    { label: "ParentA", href: "ParentA/index.html" },
    { label: "ParentB", href: "ParentA/ParentB/index.html" }
  ],
  subpages: [
    { label: "Go Up",   href: "ParentA/ParentB/index.html" },
    { label: "Child 1", href: "ParentA/ParentB/ARTICLE_TITLE/Child1/index.html" },
    { label: "Child 2", href: "ParentA/ParentB/ARTICLE_TITLE/Child2/index.html" }
  ]
};
</script>

<main>
  <section>
    <h1>ARTICLE_TITLE</h1>
    <div id="tocButton"></div>
    <div id="toc"></div>

    <!-- article content here -->

  </section>
</main>
</body>
</html>
```

Lines saved per page: approximately **35–40 lines** of boilerplate → down to ~10 lines of shell.

### Changes to `script.js`

Add a `buildPage()` function that runs before `loadContent()`:

```javascript
const NAV_LINKS = [
  { label: "Home",         href: "index.html" },
  { label: "About",        href: "About/index.html" },
  { label: "Blupi",        href: "Blupi/index.html" },
  { label: "Projects",     href: "Projects/index.html" },
  { label: "Technologies", href: "Technologies/index.html" }
];

const FOOTER_HTML =
  `<footer><p>Content is available under ` +
  `<a href="https://creativecommons.org/licenses/by-sa/4.0/" target="_blank" rel="noopener noreferrer">` +
  `Creative Commons Attribution-ShareAlike 4.0 International License</a> unless otherwise noted.</p></footer>`;

function buildPage() {
  // Build <header>
  const navItems = NAV_LINKS.map(n => `<li><a href="${n.href}">${n.label}</a></li>`).join('');
  const headerHTML =
    `<header>` +
    `<div id="main_banner"><a href="index.html">Open Eggbert</a></div>` +
    `<nav><ul>${navItems}</ul></nav>` +
    `</header>`;
  document.body.insertAdjacentHTML('afterbegin', headerHTML);

  // Build breadcrumb + hierarchy panel from PAGE_CONFIG
  if (typeof PAGE_CONFIG !== 'undefined') {
    const breadcrumbLinks = (PAGE_CONFIG.breadcrumb || [])
      .map(b => `<a href="${b.href}">${b.label}</a>`)
      .join(' / ');
    const subpageLinks = (PAGE_CONFIG.subpages || [])
      .map(s => `<a href="${s.href}">${s.label}</a>`)
      .join('');
    const panelHTML =
      `<div id="breadcrumb_hierarchy_panel">` +
      `<div id="breadcrumb">${breadcrumbLinks}</div>` +
      `<div id="hierarchy_panel">${subpageLinks}</div>` +
      `</div>`;
    document.querySelector('main').insertAdjacentHTML('beforebegin', panelHTML);
  }

  // Inject <footer>
  document.body.insertAdjacentHTML('beforeend', FOOTER_HTML);
}
```

`<body>` changes from `<body onload="loadContent()">` to just `<body>`, and both `buildPage()` and `loadContent()` are called via:

```javascript
document.addEventListener('DOMContentLoaded', () => { buildPage(); loadContent(); });
```

### Meta tags: shared vs. per-page

The current `<meta name="description">` and `<meta name="keywords">` tags are **identical on every page** (they always describe the site, not the article). Two options:

- **Option A (simplest):** Move these into `script.js` / `buildPage()` and inject them into `<head>` dynamically — they disappear from every page file.
- **Option B (per-page SEO):** Keep them in the page `<head>` so each page can have a unique description in the future.

Recommendation: **Option A** for now (they are already identical everywhere, so no per-page value is lost), but make `PAGE_CONFIG.description` an optional override that, if present, replaces the default.

---

## 4. Benefits

| Benefit | Detail |
|---|---|
| **Adding a new page** | Copy minimal template (~25 lines), fill `PAGE_CONFIG` + `<main>` content. No boilerplate copying. |
| **Updating nav** | Change `NAV_LINKS` in `script.js` — propagates to all 127 pages instantly. |
| **Updating footer license** | Change `FOOTER_HTML` in `script.js` — done. Currently requires editing 127 files. |
| **Updating meta description** | Same — one place instead of 127. |
| **Fewer merge conflicts** | Articles only contain content, not structural HTML. |
| **No build toolchain needed** | Pure browser-side JS; works with GitHub Pages as-is. |

---

## 5. What Does NOT Change

- The URL structure (`Category/Subcategory/index.html`) stays identical.
- The `styles.css` is untouched.
- The `<base href>` trick for depth-relative asset loading is kept.
- The visual appearance is **pixel-identical** to the current site (same CSS, same HTML output after JS runs).
- The `tree.html` page is standalone and needs no changes (it already has its own inline styles).
- SEO: Google and most modern crawlers execute JavaScript, so injected content is indexed. For the rare crawler that does not execute JS, the page title and article `<h1>` content are still in the static HTML.

---

## 6. Migration Strategy

Migration can be done in small, safe batches:

1. **Update `script.js`** — add `buildPage()` and change the init call. No page breaks yet (existing pages still have their own header/footer).
2. **Convert pages one section at a time** — start with a low-traffic section (e.g. `About/`), verify visually, then proceed.
3. **Remove old boilerplate** from converted pages only after verifying the injected version looks correct.
4. **Update `Template/index.html`** to the new minimal format so all future pages start slim.
5. **Remove `<meta name="description/keywords/author">` from all pages** once `buildPage()` handles them.

A simple shell script can verify each converted page still contains the expected `PAGE_CONFIG` variable and `<main>` tag.

---

## 7. Optional Future Improvement: Markdown content

Once the JS injection is in place, a further step (not required) would be to write article content in Markdown and convert it with a minimal build script (e.g. `pandoc` or a Node.js script) that:
- Reads each `content.md` file
- Wraps it in the minimal HTML shell with appropriate `PAGE_CONFIG`
- Outputs `index.html`

This would allow article authors to write plain Markdown without touching any HTML at all.
This step is entirely **optional** and should only be considered after the JS injection refactor is complete and working.
