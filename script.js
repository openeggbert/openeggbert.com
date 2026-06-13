// Site-wide constants injected into every page by buildPage()
const NAV_LINKS = [
    {label: "Home",         href: "index.html"},
    {label: "About",        href: "About/index.html"},
    {label: "Blupi",        href: "Blupi/index.html"},
    {label: "Projects",     href: "Projects/index.html"},
    {label: "Technologies", href: "Technologies/index.html"}
];

const SITE_META = {
    description: "Open Eggbert, a free and open-source game, reimagines the Speedy Blupi experience with modern design using C++ and SDL 3. Explore OpenEggbert.com, the ultimate fan site packed with Speedy Blupi resources, including websites, files, GitHub links, and YouTube videos.",
    keywords: "Blupi, Speedy Blupi, Speedy Eggbert, Decompilation, C++, DirextX 3, SDL 3, CNA, XNA",
    author: "Robert Vokáč"
};

const FOOTER_INNER =
    'Content is available under ' +
    '<a href="https://creativecommons.org/licenses/by-sa/4.0/" target="_blank" rel="noopener noreferrer">' +
    'Creative Commons Attribution-ShareAlike 4.0 International License' +
    '</a> unless otherwise noted.';

function escHtml(s) {
    return String(s)
        .replace(/&/g, '&amp;')
        .replace(/</g, '&lt;')
        .replace(/>/g, '&gt;')
        .replace(/"/g, '&quot;');
}

function buildPage() {
    const head = document.querySelector('head');
    const cfg = (typeof PAGE_CONFIG !== 'undefined') ? PAGE_CONFIG : {};

    // Inject meta tags
    const addMeta = (name, content) => {
        const m = document.createElement('meta');
        m.name = name;
        m.content = content;
        head.appendChild(m);
    };
    addMeta('description', cfg.description || SITE_META.description);
    addMeta('keywords',    SITE_META.keywords);
    addMeta('author',      SITE_META.author);

    // Build and inject <header>
    const navItems = NAV_LINKS
        .map(n => `<li><a href="${n.href}">${n.label}</a></li>`)
        .join('');
    const headerHtml =
        `<header>` +
        `<div id="main_banner"><a href="index.html">Open Eggbert</a></div>` +
        `<nav><ul>${navItems}</ul></nav>` +
        `</header>`;
    document.body.insertAdjacentHTML('afterbegin', headerHtml);

    // Build and inject breadcrumb + hierarchy panel from PAGE_CONFIG
    const bc = cfg.breadcrumb || [];
    const sp = cfg.subpages   || [];
    if (bc.length > 0 || sp.length > 0) {
        const bcHtml = bc
            .map(b => `<a href="${b.href}">${escHtml(b.label)}</a>`)
            .join(' /\n        ');
        const spHtml = sp
            .map(s => `<a href="${s.href}">${escHtml(s.label)}</a>`)
            .join('\n        ');
        const panelHtml =
            `<div id="breadcrumb_hierarchy_panel">` +
            `<div id="breadcrumb">${bcHtml}</div>` +
            `<div id="hierarchy_panel">${spHtml}</div>` +
            `</div>`;
        const mainEl = document.querySelector('main');
        if (mainEl) {
            mainEl.insertAdjacentHTML('beforebegin', panelHtml);
        }
    }

    // Inject <footer>
    document.body.insertAdjacentHTML('beforeend',
        `<footer><p>${FOOTER_INNER}</p></footer>`);
}

// ── existing helpers (unchanged) ────────────────────────────────────────────

function getCurrentRelativePath() {
    const url = window.location.pathname;
    return url.startsWith('/') ? url.substring(1) : url;
}

function setCookie(name, value, days) {
    const expires = new Date();
    expires.setDate(expires.getDate() + days);
    document.cookie = `${name}=${value}; expires=${expires.toUTCString()}; path=/`;
}

function getCookie(name) {
    const cookies = document.cookie.split(';').map(cookie => cookie.trim().split('='));
    const cookie = cookies.find(([key]) => key === name);
    return cookie ? cookie[1] : null;
}

function loadContent() {
    const toc = document.getElementById('toc');
    const tocButton = document.getElementById('tocButton');
    const headings = document.querySelectorAll('h2, h3, h4');

    const toggleButton = document.createElement('button');
    toggleButton.textContent = getCookie('tocShown') === 'true' ? 'Hide Content' : 'Show Content';
    toggleButton.style.padding = "5px";
    toggleButton.style.margin = "0px";
    toggleButton.id= "toggleButton";

    toggleButton.onclick = () => {
        const isShown = toc.style.display === 'block';
        toc.style.display = isShown ? 'none' : 'block';
        setCookie('tocShown', !isShown, 30);
        toggleButton.textContent = isShown ? 'Show Content' : 'Hide Content';
    };

    if (getCookie('tocShown') === 'true') {
        toc.style.display = 'block';
    } else {
        toc.style.display = 'none';
    }

    toc.innerHTML = '<h2 class="ignore-counter">Content:</h2><ul></ul>';
    const tocList = toc.querySelector('ul');
    let lastH2 = null, lastH3 = null;

    let someHeaders = false;

    headings.forEach((heading, index) => {
        if(!someHeaders) someHeaders = true;
        const listItem = document.createElement('li');
        const link = document.createElement('a');

        heading.id = `heading-${index}`;
        link.href = `/${getCurrentRelativePath()}#heading-${index}`;
        link.textContent = heading.textContent;

        listItem.appendChild(link);

        if (heading.tagName === 'H2') {
            tocList.appendChild(listItem);
            lastH2 = document.createElement('ul');
            listItem.appendChild(lastH2);
            lastH3 = null;
        } else if (heading.tagName === 'H3' && lastH2) {
            lastH2.appendChild(listItem);
            lastH3 = document.createElement('ul');
            listItem.appendChild(lastH3);
        } else if (heading.tagName === 'H4' && lastH3) {
            lastH3.appendChild(listItem);
        }
    });

    if(someHeaders) {
        tocButton.appendChild(toggleButton);
    } else {
        toc.style.display = 'none';
    }

    document.querySelectorAll('a.ref').forEach(function(link) {
        link.setAttribute('target', '_blank');
    });
}

// ── initialisation ───────────────────────────────────────────────────────────
document.addEventListener('DOMContentLoaded', function() {
    buildPage();
    loadContent();
});
