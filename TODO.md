# TODO — openeggbert.com content improvements

This file tracks proposed improvements to the `src/` content of openeggbert.com.
Items are grouped by area. Within each group, items are roughly priority-ordered (high → low).

---

## 1. Create missing articles (broken link stubs)

These pages are linked from existing content via `Article_does_not_yet_exist_or_link_is_broken`
but have no real article yet.

### Games & companies
- [ ] `src/Blupi/Games/Speedy_Blupi_(Windows)/eGames/index.md` — eGames company (US publisher of Speedy Eggbert)
- [ ] `src/Blupi/Games/Speedy_Eggbert/Dada_Games/index.md` — link exists in breadcrumb of Speedy_Eggbert but directory is missing
- [ ] `src/Blupi/Games/Speedy_Blupi_(Windows)/Sequel/index.md` — article about the concept of sequel
- [ ] `src/Blupi/Games/Speedy_Blupi_(Windows)/Comparison_SB_vs_SE/index.md` — comparison of Speedy Blupi and Speedy Eggbert (referenced from Speedy_Eggbert page)

### People & community
- [ ] `src/Blupi/Community/HMVocaloid/index.md` — started the SB2 decompilation project
- [ ] `src/Blupi/Community/jummy0/index.md` — contributed to sb2-decomp, lost files
- [ ] `src/Blupi/Community/Mathieu_Schroeter/index.md` — exists as directory but needs content check

### Technologies — programming languages
- [ ] `src/Technologies/Programming_languages/C/index.md` — C language (used by Wine)
- [ ] `src/Technologies/Programming_languages/Java/index.md` — Java (used by Sprite Utils)

### Technologies — libraries / frameworks
- [ ] `src/Technologies/Libraries/MonoGame/index.md` — MonoGame (XNA alternative, used by Mobile Eggbert C#)
- [ ] `src/Technologies/Libraries/FNA/index.md` — FNA (XNA alternative)
- [ ] `src/Technologies/Libraries/KNI/index.md` — KNI (MonoGame fork, used for web port)
- [ ] `src/Technologies/Libraries/ILSpy/index.md` — decompiler used for Mobile Eggbert
- [ ] `src/Technologies/Libraries/Ghidra/index.md` — decompiler used for Free Eggbert
- [ ] `src/Technologies/Libraries/IDA/index.md` — decompiler used for Free Eggbert
- [ ] `src/Technologies/Libraries/OpenGL/index.md` — OpenGL (used by EasyGL/MetaGL/CNA)
- [ ] `src/Technologies/Libraries/Vulkan/index.md` — Vulkan (planned CNA backend)
- [ ] `src/Technologies/Libraries/WebGL/index.md` — WebGL
- [ ] `src/Technologies/Libraries/WebGPU/index.md` — WebGPU
- [ ] `src/Technologies/Libraries/LibGDX/index.md` — LibGDX (mentioned in Mobile Eggbert)
- [ ] `src/Technologies/Libraries/TinySoundFont/index.md` — used in Free API for MIDI

### Technologies — tools & applications
- [ ] `src/Technologies/Applications/Audacity/index.md` — audio editor for creating sounds
- [ ] `src/Technologies/Applications/RayDreamStudio/index.md` — 3D tool used to create Speedy Blupi sprites
- [ ] `src/Technologies/Applications/GIMP/index.md`
- [ ] `src/Technologies/Applications/Inkscape/index.md`
- [ ] `src/Technologies/Applications/CLion/index.md` — IDE used by Robert Vokac
- [ ] `src/Technologies/Applications/VisualStudio/index.md` — Visual Studio (used to build Speedy Blupi)
- [ ] `src/Technologies/Applications/WPInternals/index.md` — tool for unlocking Windows Phone bootloader

### Technologies — platforms
- [ ] `src/Technologies/Platforms/iOS/index.md` — mentioned as not supported by Blupi is Back
- [ ] `src/Technologies/Platforms/ReactOS/index.md` — mentioned as alternative to run Speedy Blupi

### Technologies — other
- [ ] `src/Technologies/Other/Emulators/VirtualBox/index.md`
- [ ] `src/Technologies/Other/Emulators/VMware/index.md`
- [ ] `src/Technologies/Other/Emulators/Qemu/index.md`
- [ ] `src/Technologies/Other/Emulators/ExaGear/index.md` — run Speedy Blupi on Android
- [ ] `src/Technologies/Other/Emulators/Winlator/index.md` — run Speedy Blupi on Android
- [ ] `src/Technologies/Other/Emulators/LimboX86/index.md` — x86 PC emulator for Android
- [ ] `src/Technologies/Other/Emulators/index.md` — emulators overview page
- [ ] `src/Technologies/Other/WebAssembly/index.md` — exists but check if has content
- [ ] `src/Technologies/Other/Asm.js/index.md` — exists but check if has content
- [ ] `src/Technologies/Other/OpenSource/index.md` — open-source concept
- [ ] `src/Technologies/Other/ClosedSource/index.md`
- [ ] `src/Technologies/Other/Proprietary/index.md`
- [ ] `src/Technologies/Other/DropInReplacement/index.md`
- [ ] `src/Technologies/Other/XAP/index.md` — XAP file format (Windows Phone executable)
- [ ] `src/Technologies/Other/FluidSynth/index.md` — MIDI player for Linux

### File formats
- [ ] `src/Technologies/FileFormats/index.md` — new section overview
- [ ] `src/Technologies/FileFormats/BMP/index.md` — bitmap format used by Speedy Blupi
- [ ] `src/Technologies/FileFormats/MIDI/index.md` — MIDI music format
- [ ] `src/Technologies/FileFormats/WAV/index.md` — WAV sound format
- [ ] `src/Technologies/FileFormats/OGG/index.md`
- [ ] `src/Technologies/FileFormats/BLP/index.md` — custom Speedy Blupi format (save, user info, demo)
- [ ] `src/Technologies/FileFormats/XCH/index.md` — Speedy Blupi level format
- [ ] `src/Technologies/FileFormats/glTF/index.md` — used as export from MeshCraft

### Dates / years as articles
- [ ] Consider whether year articles (1998, 2001, 2013, ...) should be stub pages or removed in favour of Wikipedia links

---

## 2. Content improvements on existing pages

### `src/index.md` (main page)
- [ ] Introduction text still references `Free Eggbert` with a broken link (`Article_does_not_yet_exist_or_link_is_broken`) — link to `Projects/Free_Eggbert/index.html` instead
- [ ] Add a short description / tagline for each project listed in the infobox
- [ ] Screenshots section only has 2 images — consider adding Galaxy Eggbert screenshot and Mobile Eggbert screenshots
- [ ] Update "Current status: To do" for Free Eggbert if status has changed

### `src/About/Contribute/index.md`
- [ ] "Documentation: openeggbert.com (a MediaWiki-powered encyclopedia)" — the site is no longer MediaWiki; update description
- [ ] Issue tracker link points to GitHub org root, not to specific issue tracker
- [ ] Add link to `src/Projects/` for code contribution context
- [ ] Add section about contributing content to this wiki-style website (src/ markdown files, PR workflow)

### `src/About/Future/index.md`
- [ ] "What programming languages and libraries to use for the next decades" section is now outdated — CNA/SDL 3/C++ choice has already been made; update to reflect current decisions
- [ ] X86S paragraph about Intel cancellation needs date clarification (it says "December 2024" which is now past)
- [ ] Add section about Galaxy Eggbert as the planned 3D remake

### `src/About/Goals/index.md`
- [ ] The TODO code block (Projects A–O) is raw text inside a code fence — convert to a proper table or list with links to project pages
- [ ] Add links to CNA, Free Direct, Free API, Galaxy Eggbert in relevant sections
- [ ] Archive section references `https://archive.openeggbert.com/main` — verify if this URL is correct/active

### `src/About/History/index.md`
- [ ] Very sparse — add more milestones:
  - When openeggbert.com domain was purchased (18th June 2024)
  - Release of Mobile Eggbert (25th November 2024)
  - Galaxy Eggbert first build
  - Start of CNA, Free Direct, Free API development
  - Start of sharpruntime development
- [ ] "Autumn 2024 - Speedy Blupi for Windows Phone was decompiled" — add exact date (November 23–25, 2024)
- [ ] "playeble" typo → "playable"

### `src/About/Hall_of_Fame/index.md`
- [ ] "MediaWiki" entry is incorrect — the site no longer runs on MediaWiki; remove or update
- [ ] Free Direct and Free Api entries have no description — add short descriptions
- [ ] Add entries for new projects: Galaxy Eggbert, Sharp Runtime, EasyGL, MetaGL, MeshCraft
- [ ] Add entry for SDL 3 (currently only SDL without version)
- [ ] Update CNA entry (now a real project, not just an idea)
- [ ] Add entry for TinySoundFont (used in Free API)

### `src/About/Abbreviations/index.md`
- [ ] Add new abbreviations:
  - GE = Galaxy Eggbert
  - FD = Free Direct
  - FA = Free API (or FAPI)
  - CNA = CNA (explain the acronym origin if known)
  - SR = Sharp Runtime

### `src/Blupi/Community/Daniel_Roux/index.md`
- [ ] Breadcrumb has a space in path: `Blupi/Community/Daniel Roux/index.html` → should be `Daniel_Roux` (bug)
- [ ] Page has almost no text content beyond the infobox and photos — add biography, list of games he created, links to his projects

### `src/Blupi/Community/Robert_Vokac/index.md`
- [ ] External links section at the bottom is empty — add actual external links
- [ ] Nokia Lumia table: add "OS version" column is already there, but some rows have empty OS field
- [ ] Consider adding section about contributions to Open Eggbert

### `src/Blupi/Community/Mathieu_Schroeter/index.md`
- [ ] Check/add content (maintainer of Planet Blupi open-source release)

### `src/Blupi/Games/Speedy_Eggbert/index.md`
- [ ] `Dada_Games` is listed as a subpage but that directory likely doesn't exist — check and remove if broken
- [ ] Troubleshooting section exists in the file — add actual troubleshooting content

### `src/Blupi/Games/Blupi_is_Back/index.md`
- [ ] "Blupi is Back is a new Blupi game to be released in 20 year" — broken sentence, should say "in 20 years" or similar; actually the game was released in 2024 so rephrase
- [ ] Add description of gameplay, screenshots, and external review links

### `src/Blupi/Games/Planet_Blupi/index.md`
- [ ] Add open-source release information (source code published in 2017 by Epsitec/Mathieu Schroeter)
- [ ] Add GitHub repository link: https://github.com/blupi-games/planetblupi
- [ ] Add download links

### `src/Blupi/Fan_projects/` pages
- [ ] `BlupiEdit/index.md` — add more content (screenshots, download, description)
- [ ] `Eggbert_3/index.md` — check if has content
- [ ] `Tiled-blupi/index.md` — check if has content
- [ ] `X-Edit/index.md` — check if has content
- [ ] `X-Edit-Mapper/index.md` — check if has content
- [ ] `Blupi-Bouncers/index.md` — check if has content

### `src/Projects/Free_Eggbert/index.md`
- [ ] The broken link `[Free Eggbert: ](Article_does_not_yet_exist_or_link_is_broken/index.html)` exists on the main `src/index.md` — should point to `Projects/Free_Eggbert/index.html`
- [ ] Add current GitHub repository link for the main openeggbert fork
- [ ] Add section about the Free Direct and Free API dependency relationship

### `src/Projects/Mobile_Eggbert/index.md`
- [ ] "If the C# version will be kept, then..." — update: clarify current decision (C++ rewrite in progress)
- [ ] Add status update: Android touch controls / scaling fixes as of 2025

### `src/Projects/Sprite_Utils/index.md`
- [ ] "How to use" section still has `CONFIG.DEF` content that looks misplaced (belongs in Speedy Blupi docs, not Sprite Utils)
- [ ] Add GitHub link to the repository prominently in infobox

### `src/Technologies/Libraries/XNA/index.md`
- [ ] Check and expand content about XNA 4.0 and its alternatives

### `src/Technologies/Other/Wine/index.md`
- [ ] Check and expand content

### `src/Technologies/Platforms/Windows_Phone/index.md`
- [ ] Check and expand content (links to hardware, WPInternals, XAP format)

---

## 3. New sections / pages to add

### New top-level section: `src/Projects/Planet_Blupi/` (fork)
- [x] Already created — add more content: how to build, how it differs from the Epsitec open-source release

### New page: `src/Projects/Youtube_Frontend/index.md`
- [ ] Expand existing stub with more detail about how the tool works

### New page: `src/Blupi/Blupi_videos/index.md`
- [ ] List of important Speedy Blupi YouTube videos with links, descriptions

### New page: `src/Blupi/Blupi.com/index.md`
- [ ] History and content of the official blupi.com and blupi.org websites

### New page: `src/Blupi/Images/index.md`
- [ ] Gallery or index of Blupi-related images archived at drive.openeggbert.com

### New section: `src/Technologies/FileFormats/`
- [ ] BMP, MIDI, WAV, BLP, XCH, XAP — see section 1 above

### New section: `src/Technologies/Other/Emulators/`
- [ ] VirtualBox, VMware, QEMU, ExaGear, Winlator, Limbo — see section 1 above

### New page: `src/About/Downloads/index.md`
- [ ] The downloads list currently lives in `src/About/index.md` — move it to a dedicated Downloads page and link from About

### New page: `src/About/FAQ/index.md`
- [ ] Frequently asked questions: Can I play Speedy Blupi on Linux? On Android? What is the difference between Speedy Blupi and Speedy Eggbert? What is Open Eggbert? etc.

### New page: `src/Blupi/Games/Speedy_Blupi_(Windows)/Save_format/index.md`
- [ ] Document the BLP save/user info/demo file format (referenced in Goals as a TODO)

### New page: `src/Blupi/Games/Speedy_Blupi_(Windows)/Music/index.md`
- [ ] Document the MIDI music tracks

### New page: `src/Blupi/Games/Speedy_Blupi_(Windows)/Sounds/index.md`
- [ ] Document the WAV sound effects

### New page: `src/Blupi/Games/Speedy_Blupi_(Windows)/Screens/index.md`
- [ ] Identify all screens (main menu, options, game, score) and their buttons (referenced in Goals)
- [ ] Note: `Screens/index.md` already exists under `Speedy_Blupi_(Windows)` but may be empty or for screenshots only

### New page: `src/Blupi/Games/Speedy_Eggbert/Comparison_SB_SE/index.md`
- [ ] Detailed comparison of Speedy Blupi vs Speedy Eggbert (referenced from Speedy_Eggbert page)

---

## 4. Structural / navigation issues

- [ ] `src/Blupi/Community/Daniel_Roux/index.md` — breadcrumb has space in path (`Daniel Roux`) instead of underscore — needs fix
- [ ] `src/Projects/index.md` — `Youtube_Frontend` is listed in subpages but is arguably not an active project in the same sense as the games/libraries; consider moving to a separate section or adding a "Tools" section
- [ ] `src/Technologies/index.md` — page body is completely empty (only frontmatter); add at least a short introduction paragraph
- [ ] `src/Blupi/Games/index.md` — check if body content exists; if empty, add introduction
- [ ] `src/Blupi/Fan_projects/index.md` — check if body content exists
- [ ] `src/About/index.md` — Downloads section belongs in a separate dedicated page; the page mixes "About the site" with a big download list
- [ ] `src/Blupi/Games/Speedy_Eggbert/index.md` — subpage `Dada_Games` is listed but that subdirectory probably doesn't exist (Dada Games is under `Speedy_Blupi_(Windows_Phone)`, not `Speedy_Eggbert`) — verify and remove if broken
- [ ] Many `Article_does_not_yet_exist_or_link_is_broken` links for years (1998, 2001, 2013, etc.) — these could simply be removed or replaced with Wikipedia links instead of creating stub articles

---

## 5. Consistency and correctness issues

- [ ] `src/About/Contribute/index.md` says "openeggbert.com (a MediaWiki-powered encyclopedia)" — the site is a custom static site generator, not MediaWiki; update wording
- [ ] `src/Projects/Mobile_Eggbert/index.md` "Cancelled projects" now describes them as cancelled but the KNI Web port was working — already partially fixed in Projects/index.md but the Mobile Eggbert page itself still has outdated info
- [ ] `src/Blupi/Games/Blupi_is_Back/index.md` — "to be released in 20 year" is a broken sentence; the game was released on 23rd July 2024, fix the sentence
- [ ] `src/Projects/Sprite_Utils/index.md` — "How to use" section references `CONFIG.DEF` and Speedy Blupi game settings; this content seems to belong in `Speedy_Blupi_(Windows)/CONFIG.DEF/index.md`, not in Sprite_Utils
- [ ] `src/About/Hall_of_Fame/index.md` — "MediaWiki" listed as 2-star item "software which openeggbert runs on" — this is wrong; update
- [ ] `src/Projects/Free_Eggbert/index.md` links to `Technologies/Other/Reverse_engineering/index.html` with a relative path that looks correct, but verify all relative paths in project pages are consistent
- [ ] `src/Blupi/Games/Speedy_Blupi_(Windows_Phone)/Dada_Games/index.md` — check if this subpage has content

---

## 6. Links and references to verify / fix

- [ ] `src/About/Goals/index.md` references `https://archive.openeggbert.com/main` — verify this URL is correct
- [ ] `src/About/Useful_websites/index.md` has many `[?](?)` placeholder rows (numbers 12, 14–18, 21–23, 25–29, 32, 34–37, 40–42, 46, 56, 63) — fill in or remove
- [ ] `src/Blupi/Epsitec/index.md` — verify content and links
- [ ] `src/Blupi/index.md` — X (Twitter) link for `@BlupiGames` is struck through (deleted account?) — verify and update or remove
- [ ] `src/Blupi/Community/Daniel_Roux/index.md` — email address `danielroux33@gmail.com` is personal; consider whether it should be publicly listed
- [ ] Hall of Fame links for `Speedy-Eggbert-2-Source-Code-Decomp` use `<nowiki>` tag which is MediaWiki syntax — convert to plain Markdown link

---

## 7. Quality of writing / presentation

- [ ] Many pages use `<br>` for paragraph separation instead of blank lines — convert to proper Markdown paragraphs where possible
- [ ] Inconsistent use of `**bold**` vs `<strong>` across pages — standardize to Markdown bold
- [ ] `src/Projects/Sprite_Utils/index.md` example table row data is still compressed on one long line (line 81 content was removed but verify cleanup is complete)
- [ ] `src/About/Goals/Sound/index.md` — the content is AI-generated generic advice (numbered steps, tool suggestions); consider replacing with more specific information about the actual sounds in Speedy Blupi and the specific workflow used/planned
- [ ] `src/Projects/Mobile_Eggbert/index.md` — "Reasons to Rewrite" and "Reasons not to Rewrite" sections are now historical (decision already made); consider converting to a past-tense note or removing
- [ ] `src/Blupi/Games/Speedy_Blupi_(Windows)/index.md` — verify content is comprehensive and up-to-date

---

## 8. Images and media

- [ ] Main page has only 2 screenshots — add Galaxy Eggbert, MeshCraft screenshot
- [ ] `src/About/Hall_of_Fame/star.jpg` is used inline with `<img>` tags; the stars approach is functional but brittle — consider using Unicode ★ characters instead for simpler maintenance
- [ ] `src/Blupi/Community/Daniel_Roux/index.md` — photos are hotlinked from `smaky.ch`; consider mirroring to `drive.openeggbert.com` in case the source goes down
- [ ] Most project pages (CNA, Free Direct, Free API, etc.) have no screenshots — add screenshots or diagrams where appropriate

---

## 9. Projects section — remaining gaps

- [ ] `src/Projects/Sharp_Runtime/index.md` — add implementation status table (which System::* classes are done)
- [ ] `src/Projects/Galaxy_Eggbert/index.md` — add screenshot, add World Format link (there's a `World Format.md` in the repo)
- [ ] `src/Projects/MeshCraft/index.md` — add screenshot (`mesh_craft_screenshot.png` exists in the repo)
- [ ] `src/Projects/Planet_Blupi/index.md` — add build instructions specific to the OE fork
- [ ] `src/Projects/Galaxy_Eggbert/index.md` — add link to world format specification
- [ ] All new project pages are missing `tags:` frontmatter — add relevant tags once a tag taxonomy is defined

---

## 10. Potential new features for the website itself

- [ ] Add a `src/Changelog/index.md` page tracking website content updates
- [ ] Add a `src/Sitemap/index.md` or improve the existing `tree.html` with descriptions
- [ ] Consider adding a `src/Search/index.md` or static search integration
- [ ] Tags system (`tags.html`) — ensure all pages have relevant tags assigned; many pages have no `tags:` key at all
- [ ] Add a dedicated `src/Downloads/index.md` aggregating all download links from across the site
- [ ] `src/About/Useful_websites/index.md` — the WARC archive download links should be updated for all new archived sites
