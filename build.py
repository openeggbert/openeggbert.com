#!/usr/bin/env python3
"""
build.py — Generate HTML pages from Markdown sources in src/

Usage:
    python build.py            # build all pages
    python build.py --check    # dry-run: show what would be built

Each src/**/*.md file is converted to the corresponding **/*.html at the
repo root, using the shared styles.css / script.js / favicon.ico.
"""
import re
import sys
import yaml
import markdown
from pathlib import Path

ROOT = Path(__file__).parent
SRC  = ROOT / 'src'

# ── HTML page template ────────────────────────────────────────────────────────

def _page(title, base_href, page_config_js, content, tags_html, main_attrs=''):
    main_open = f'<main{main_attrs}>' if main_attrs else '<main>'
    return f"""\
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Open Eggbert - {title}</title>
    <base href="{base_href}" target="_self">
    <link rel="stylesheet" href="styles.css">
    <link rel="icon" href="favicon.ico" type="image/x-icon" sizes="32x32">
    <script type="text/javascript" src="script.js"></script>
</head>
<body>
{page_config_js}{main_open}
<section>
<h1>{title}</h1>
<div id="tocButton"></div>
<div id="toc"></div>
{content}{tags_html}
</section>
</main>

</body>
</html>"""


def _page_config_js(breadcrumb, subpages):
    if not breadcrumb and not subpages:
        return ''

    def fmt(link):
        label = str(link.get('label', '')).replace('\\', '\\\\').replace('"', '\\"')
        href  = str(link.get('href', ''))
        return f'    {{label: "{label}", href: "{href}"}}'

    bc = ',\n'.join(fmt(l) for l in breadcrumb)
    sp = ',\n'.join(fmt(l) for l in subpages)
    return (
        '<script>\n'
        'PAGE_CONFIG = {\n'
        '  breadcrumb: [\n'
        + (bc + '\n' if bc else '') +
        '  ],\n'
        '  subpages: [\n'
        + (sp + '\n' if sp else '') +
        '  ]\n'
        '};\n'
        '</script>\n'
    )


def _tags_html(tags):
    if not tags:
        return ''
    items = ''.join(f'\n            <li>{t}</li>' for t in tags)
    return f'\n        <ul id="tags">{items}\n        </ul>\n'


def _base_href(md_path):
    depth = len(md_path.relative_to(SRC).parts) - 1  # subtract filename
    return '.' if depth == 0 else '/'.join(['..'] * depth)


# ── Front-matter parser ───────────────────────────────────────────────────────

_FM_RE = re.compile(r'^---[ \t]*\r?\n(.*?)\r?\n---[ \t]*\r?\n', re.DOTALL)


def _parse(md_path):
    raw = md_path.read_text(encoding='utf-8')
    m = _FM_RE.match(raw)
    if m:
        front = yaml.safe_load(m.group(1)) or {}
        body  = raw[m.end():]
    else:
        front = {}
        body  = raw
    return front, body


# ── Markdown → HTML ───────────────────────────────────────────────────────────

_MD_EXT = ['tables', 'fenced_code', 'attr_list', 'sane_lists', 'md_in_html']


def _md_to_html(body):
    proc = markdown.Markdown(extensions=_MD_EXT)
    return proc.convert(body)


# ── Build one file ────────────────────────────────────────────────────────────

def build(md_path, dry_run=False):
    front, body = _parse(md_path)

    title      = front.get('title', md_path.parent.name)
    breadcrumb = front.get('breadcrumb', [])
    subpages   = front.get('subpages',   [])
    tags       = front.get('tags',       [])
    main_style = front.get('main_style', '')
    main_attrs = f' style="{main_style}"' if main_style else ''

    content    = _md_to_html(body)
    cfg_js     = _page_config_js(breadcrumb, subpages)
    t_html     = _tags_html(tags)
    base_href  = _base_href(md_path)

    html = _page(title, base_href, cfg_js, content, t_html, main_attrs)

    # Output path mirrors src/ structure under ROOT
    rel     = md_path.relative_to(SRC)
    out     = ROOT / rel.with_suffix('.html')
    out.parent.mkdir(parents=True, exist_ok=True)

    if not dry_run:
        out.write_text(html, encoding='utf-8')
    return out


# ── Entry point ───────────────────────────────────────────────────────────────

def main():
    dry_run = '--check' in sys.argv
    if not SRC.is_dir():
        print(f'ERROR: src/ directory not found at {SRC}', file=sys.stderr)
        sys.exit(1)

    errors  = []
    changed = 0
    for f in sorted(SRC.rglob('*.md')):
        try:
            out = build(f, dry_run=dry_run)
            action = 'CHECK' if dry_run else 'OK   '
            print(f'{action} {f.relative_to(SRC)} → {out.relative_to(ROOT)}')
            changed += 1
        except Exception as e:
            errors.append((f, e))
            print(f'ERR  {f.relative_to(SRC)}: {e}', file=sys.stderr)

    verb = 'Would build' if dry_run else 'Built'
    print(f'\n{verb} {changed} pages, {len(errors)} errors')
    sys.exit(1 if errors else 0)


if __name__ == '__main__':
    main()
