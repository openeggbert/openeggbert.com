#!/usr/bin/env python3
"""
html2md.py — One-time converter: existing index.html pages → src/**/*.md

Run once to populate src/ from the current HTML files.
After that, edit only the .md files and run build.py to regenerate HTML.

Usage:
    python html2md.py
"""
import re
import sys
import html as html_lib
import yaml
from pathlib import Path
from bs4 import BeautifulSoup, Tag, NavigableString, Comment

ROOT = Path(__file__).parent
SRC  = ROOT / 'src'

# Pages that use a completely different layout — skip
SKIP_FILES = {'tree.html', 'tags.html'}

# ── PAGE_CONFIG extractor ─────────────────────────────────────────────────────

def _extract_config(html_text):
    """Return (breadcrumb, subpages) lists from inline PAGE_CONFIG script."""
    script_m = re.search(r'PAGE_CONFIG\s*=\s*\{(.*?)\};', html_text, re.DOTALL)
    if not script_m:
        return [], []
    cfg = script_m.group(1)

    def _links(key):
        sec_m = re.search(rf'{key}\s*:\s*\[(.*?)\]', cfg, re.DOTALL)
        if not sec_m:
            return []
        return [
            {'label': m.group(1), 'href': m.group(2)}
            for m in re.finditer(r'\{label:\s*"([^"]*)",\s*href:\s*"([^"]*)"\}',
                                 sec_m.group(1))
        ]

    return _links('breadcrumb'), _links('subpages')


# ── HTML → Markdown converter ─────────────────────────────────────────────────

def _is_complex_table(tag):
    """Tables that cannot be expressed as Markdown pipe syntax."""
    if 'infobox' in (tag.get('class') or []):
        return True
    if tag.find(attrs={'colspan': True}) or tag.find(attrs={'rowspan': True}):
        return True
    return False


def _raw(el):
    """Return the element as a raw HTML string (stripped of excess whitespace)."""
    return str(el).strip()


# ── Inline-run grouping ───────────────────────────────────────────────────────

_INLINE_TAGS = frozenset({
    'a', 'abbr', 'b', 'br', 'cite', 'code', 'em', 'i', 'img',
    'kbd', 'mark', 'q', 's', 'samp', 'small', 'span', 'strong',
    'sub', 'sup', 'u', 'var',
})


def _is_inline_node(node):
    """True for text nodes and inline HTML elements."""
    if isinstance(node, Comment):
        return False
    if isinstance(node, NavigableString):
        return True
    return isinstance(node, Tag) and node.name in _INLINE_TAGS


def _block_children_md(children, skip_fn=None):
    """Convert block-container children to a list of Markdown strings.
    Consecutive inline nodes (text + inline tags) are grouped into one paragraph
    so un-wrapped inline content in <section>/<div> is not split up."""
    parts = []
    buf = []

    def flush():
        if buf:
            raw = ''.join(_inline(n) for n in buf)
            # Collapse whitespace runs (incl. newlines) to single space so that
            # indented continuation lines don't become Markdown code blocks.
            text = re.sub(r'\s+', ' ', raw).strip()
            if text:
                parts.append(text)
            buf.clear()

    for child in children:
        if skip_fn is not None and skip_fn(child):
            flush()
            continue
        if _is_inline_node(child):
            buf.append(child)
        else:
            flush()
            md = _block(child)
            if md and md.strip():
                parts.append(md.strip())

    flush()
    return parts


# ── Inline conversion ─────────────────────────────────────────────────────────

def _inline(node):
    """Convert an inline node (text or inline HTML) to Markdown string."""
    if isinstance(node, Comment):
        return ''
    if isinstance(node, NavigableString):
        return str(node)

    tag = node.name

    children = ''.join(_inline(c) for c in node.children)

    if tag in ('b', 'strong'):
        if node.get('style') or node.get('class'):
            return _raw(node)
        s = children.strip()
        if not s:
            return children
        # preserve surrounding whitespace
        pre  = children[: len(children) - len(children.lstrip())]
        post = children[len(children.rstrip()):]
        return f'{pre}**{s}**{post}'

    if tag in ('i', 'em'):
        if node.get('style') or node.get('class'):
            return _raw(node)
        s = children.strip()
        if not s:
            return children
        pre  = children[: len(children) - len(children.lstrip())]
        post = children[len(children.rstrip()):]
        return f'{pre}*{s}*{post}'

    if tag == 's':
        return f'~~{children}~~'

    if tag == 'code':
        text = node.get_text()
        return f'`{text}`'

    if tag == 'a':
        href  = node.get('href', '')
        cls   = node.get('class') or []
        title = node.get('title', '')
        # keep <a class="ref"> as raw HTML — it has special CSS styling
        if 'ref' in cls:
            return _raw(node)
        # external links with target=_blank: plain Markdown link is fine
        t_part = f' "{title}"' if title else ''
        return f'[{children}]({href}{t_part})'

    if tag == 'br':
        return '<br>\n'

    if tag in ('span', 'sub', 'sup'):
        # span with style: keep as HTML
        if node.get('style') or node.get('class'):
            return _raw(node)
        return children

    if tag == 'img':
        src   = node.get('src', '')
        alt   = node.get('alt', '')
        style = node.get('style', '')
        width = node.get('width', '')
        extra = ''
        if style:
            extra += f' style="{style}"'
        if width:
            extra += f' width="{width}"'
        if extra:
            return f'<img src="{src}" alt="{alt}"{extra}>'
        return f'![{alt}]({src})'

    # Any other inline tag: keep as raw HTML
    return _raw(node)


# ── Block conversion ──────────────────────────────────────────────────────────

def _list_to_md(tag, depth=0):
    is_ol = tag.name == 'ol'
    lines  = []
    num    = 1
    for item in tag.find_all('li', recursive=False):
        prefix = f'{num}. ' if is_ol else '- '
        inline_parts = []
        nested_lists = []
        nested_others = []
        for child in item.children:
            if isinstance(child, Tag) and child.name in ('ul', 'ol'):
                nested_lists.append(child)
            elif isinstance(child, Tag) and child.name in ('p', 'div'):
                nested_others.append(child)
            else:
                inline_parts.append(_inline(child))
        raw = ''.join(inline_parts)
        text = re.sub(r'\s+', ' ', raw).strip()
        indent = '  ' * depth
        lines.append(f'{indent}{prefix}{text}')
        for n in nested_lists:
            lines.append(_list_to_md(n, depth + 1))
        for b in nested_others:
            # nested block inside li
            lines.append(_block(b, depth + 1))
        num += 1
    return '\n'.join(lines)


def _table_to_md(tag):
    """Convert a simple table (no colspan/rowspan) to Markdown."""
    rows = tag.find_all('tr')
    if not rows:
        return _raw(tag)
    md_rows = []
    for i, row in enumerate(rows):
        cells  = row.find_all(['th', 'td'])
        values = []
        for cell in cells:
            raw = ''.join(_inline(c) for c in cell.children)
            # Pipe-table cells cannot contain newlines — collapse all whitespace
            cell_text = re.sub(r'\s+', ' ', raw).strip()
            values.append(cell_text)
        md_rows.append('| ' + ' | '.join(values) + ' |')
        if i == 0:
            md_rows.append('|' + ' --- |' * len(values))
    return '\n'.join(md_rows)


def _block(el, _depth=0):
    """Convert a block-level element to a Markdown string (may contain raw HTML)."""
    if isinstance(el, Comment):
        return ''
    if isinstance(el, NavigableString):
        text = str(el)
        return text if text.strip() else ''

    tag = el.name

    # ── Headings ──
    if tag in ('h2', 'h3', 'h4', 'h5', 'h6'):
        level = int(tag[1])
        text = re.sub(r'\s+', ' ', el.get_text()).strip()
        return '#' * level + ' ' + text

    # ── Paragraphs ──
    if tag == 'p':
        raw = ''.join(_inline(c) for c in el.children)
        # Collapse internal whitespace to prevent indented Markdown code blocks
        return re.sub(r'\s+', ' ', raw).strip()

    # ── Lists ──
    if tag in ('ul', 'ol'):
        if el.get('id') == 'tags':
            return ''          # handled separately via front-matter
        return _list_to_md(el)

    # ── Tables ──
    if tag == 'table':
        if _is_complex_table(el):
            return _raw(el)    # keep infobox / colspan tables verbatim
        return _table_to_md(el)

    # ── Code ──
    if tag == 'pre':
        code = el.find('code')
        src  = code or el
        lang = ''
        if src.get('class'):
            for c in src.get('class'):
                if c.startswith('language-'):
                    lang = c[9:]
        text = src.get_text()
        return f'```{lang}\n{text}\n```'

    # ── Blockquote ──
    if tag == 'blockquote':
        inner = '\n\n'.join(_block_children_md(el.children))
        return '\n'.join('> ' + line for line in inner.splitlines())

    # ── HR ──
    if tag == 'hr':
        return '---'

    # ── Figure ──
    if tag == 'figure':
        return _raw(el)

    # ── BR at block level ──
    if tag == 'br':
        return '<br>'

    # ── Images at block level ──
    if tag == 'img':
        return _inline(el)

    # ── DIV ──
    if tag == 'div':
        div_id    = el.get('id', '')
        div_style = el.get('style', '')
        # Skip TOC placeholders — they are re-added by the template
        if div_id in ('tocButton', 'toc'):
            return ''
        # Styled divs: keep as raw HTML
        if div_style:
            return _raw(el)
        # Generic div: group inline runs into paragraphs, then block elements
        return '\n\n'.join(_block_children_md(el.children))

    # ── Section wrapper ──
    if tag == 'section':
        return '\n\n'.join(_block_children_md(el.children))

    # ── Inline tags appearing at block level ──
    if tag in ('b', 'strong', 'i', 'em', 'a', 's', 'span', 'code', 'u'):
        return _inline(el)

    # ── Any unknown tag: keep as raw HTML ──
    return _raw(el)


def _section_to_md(container):
    """
    Convert the contents of <main> (or <main><section>) to Markdown.
    Skips h1 (becomes front-matter title), tocButton/toc divs, and tags ul.
    """
    def _skip(child):
        if not isinstance(child, Tag):
            return False
        if child.name == 'h1':
            return True
        if child.get('id') in ('tocButton', 'toc'):
            return True
        if child.name == 'ul' and child.get('id') == 'tags':
            return True
        return False

    return '\n\n'.join(_block_children_md(container.children, skip_fn=_skip))


# ── Convert one HTML file ─────────────────────────────────────────────────────

def convert_file(html_path):
    raw_html = html_path.read_text(encoding='utf-8')

    # Only process pages that use our shared template
    if 'script.js' not in raw_html:
        return None

    soup = BeautifulSoup(raw_html, 'html.parser')

    # ── Title ──────────────────────────────────────────────────────────────
    title_tag = soup.find('title')
    title = ''
    if title_tag:
        raw_title = title_tag.get_text()
        title = re.sub(r'^Open Eggbert\s*[-–]\s*', '', raw_title).strip()

    # ── Navigation data ─────────────────────────────────────────────────────
    breadcrumb, subpages = _extract_config(raw_html)

    # ── Tags ────────────────────────────────────────────────────────────────
    tags_ul = soup.find('ul', id='tags')
    tags = [li.get_text(strip=True) for li in tags_ul.find_all('li')] \
        if tags_ul else []

    # ── Main content ─────────────────────────────────────────────────────────
    main_el = soup.find('main')
    if not main_el:
        return None

    main_style = main_el.get('style', '')

    section = main_el.find('section')
    content_container = section if section else main_el
    md_body = _section_to_md(content_container)

    # ── Build YAML front-matter ───────────────────────────────────────────────
    front = {'title': title}
    if breadcrumb:
        front['breadcrumb'] = breadcrumb
    if subpages:
        front['subpages'] = subpages
    if tags:
        front['tags'] = tags
    if main_style:
        front['main_style'] = main_style

    front_str = yaml.dump(front, allow_unicode=True, sort_keys=False,
                          default_flow_style=False)

    md_out = f'---\n{front_str}---\n\n{md_body}\n'

    # ── Output path ───────────────────────────────────────────────────────────
    rel     = html_path.relative_to(ROOT)
    md_rel  = rel.with_suffix('.md')   # About/index.html → About/index.md
    out     = SRC / md_rel
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(md_out, encoding='utf-8')
    return out


# ── Main ──────────────────────────────────────────────────────────────────────

def main():
    SRC.mkdir(exist_ok=True)
    errors    = []
    converted = 0

    for html_file in sorted(ROOT.rglob('*.html')):
        if '.git' in html_file.parts:
            continue
        if 'src' in html_file.parts:          # skip already-generated files
            continue
        if html_file.name in SKIP_FILES:
            print(f'SKIP {html_file.relative_to(ROOT)}')
            continue

        try:
            out = convert_file(html_file)
            if out:
                print(f'OK   {html_file.relative_to(ROOT)} → {out.relative_to(ROOT)}')
                converted += 1
            else:
                print(f'--   {html_file.relative_to(ROOT)} (no template, skipped)')
        except Exception as e:
            errors.append((html_file, e))
            import traceback
            print(f'ERR  {html_file.relative_to(ROOT)}: {e}', file=sys.stderr)
            traceback.print_exc(file=sys.stderr)

    print(f'\nConverted {converted} files, {len(errors)} errors')
    for f, e in errors:
        print(f'  {f.relative_to(ROOT)}: {e}', file=sys.stderr)
    sys.exit(1 if errors else 0)


if __name__ == '__main__':
    main()
