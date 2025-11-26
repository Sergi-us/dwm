# dwm - dynamic window manager

## FAQ

> Was sind die Keybindings?

Das ist Suckless, der Quellcode ist die Dokumentation! Schau dir [config.h](config.h) an.
Für das komplette System halte ich eine Dokumentation in `sarbs.mom` bereit.
Drücke <kbd>Super+F1</kbd> in dwm, um sie anzuzeigen (benötigt zathura).

## Patches und Funktionen

- `bar height` https://dwm.suckless.org/patches/bar_height/
	- erlaubt die höhe der Statusbar in Pixeln anzugeben
- `statuscmd` https://dwm.suckless.org/patches/statuscmd/
	- für Mausinteraktion mit der Statusbar (zusammen mit dwmblocks).
- `xresources` https://dwm.suckless.org/patches/xresources/
	- Liest Farben/Variablen (d.h. funktioniert mit `pywal`, etc.).
- `scratchpad` https://dwm.suckless.org/patches/scratchpads/
	- Ermöglicht das Erstellen von versteckten Terminals (Scratchpads), die bei Bedarf ein- und ausgeblendet werden können. Zugänglich mit <kbd>Mod+Shift+Enter</kbd> <kbd>Mod+Shift+Druck</kbd>.
- Neue Layouts: bstack, fibonacci, deck, centered master und mehr. Alle gebunden an die Tasten <kbd>Super+(Shift+)t/z/u/i</kbd>.
- `swallow` https://dwm.suckless.org/patches/swallow/
	- fügt "Window Swallowing" hinzu. Wenn ein aus einem Terminal gestartetes Programm es unbenutzbar machen würde, nimmt es vorübergehend dessen Platz ein, um Platz zu sparen.
- `actualfullscreen` https://dwm.suckless.org/patches/actualfullscreen/
	- Echter Vollbildmodus (<kbd>Super+f</kbd>) und verhindert Fokuswechsel.
- `sticky` https://dwm.suckless.org/patches/sticky/
	- Fenster können sticky (fixiert) gemacht werden (<kbd>Super+s</kbd>).
- `hide vacant tags` https://dwm.suckless.org/patches/hide_vacant_tags/
	- versteckt Tags ohne Fenster.
- `stacker` https://dwm.suckless.org/patches/stacker/
	- Fenster manuell im Stack nach oben/unten bewegen (<kbd>Super-K/J</kbd>).
- `shiftview` https://dwm.suckless.org/patches/nextprev/
	- Durch Tags zyklisch wechseln (<kbd>Super+g/;</kbd>).
- `vanitygaps` https://dwm.suckless.org/patches/vanitygaps/
	- Lücken in allen Layouts erlaubt.

## Geplante Patches

Update auf Version 6.6 ist vollzogen, danach folgen neue Patches:
(Ich überlege noch welche Patches folgen, ist lediglich eine Sammlung an Patches die mir gefallen und noch nicht
Implementiert sind)

- `movestack` https://dwm.suckless.org/patches/movestack/
	- Alternative zu `stacker`
- `resizehere` https://dwm.suckless.org/patches/resizehere/
	- Kleines Pacht damit die Maus nicht ins Eck springt bei der Größenänderung von Floating Windows.
- `statusallmons` https://dwm.suckless.org/patches/statusallmons/
	- Updatet die Statusbar auf allen Monitoren.
- `pertag` https://dwm.suckless.org/patches/pertag/
	- Erlaubt unterschiedliche Layouts auf allen Stags/Tabs.
- `tiledmove` https://dwm.suckless.org/patches/tiledmove/
	- Lässt die Fenster per Mouse im Tiling ändern.
- `unfloatvisible` https://dwm.suckless.org/patches/unfloatvisible/
	- Floating Fenster lässt sich zurück in den Stapel legen. (Die Funktionalität besteht bereits, aber es gilt zu prüfen ob es den Versionssprung überlebt)
- `status2d` https://dwm.suckless.org/patches/status2d/
	- An diesem Patch arbeite ich aktuell...
	- Erweiterte darstellung von Farben und Symbolen im DMENU
- `setborderpx` https://dwm.suckless.org/patches/setborderpx/
	- Fenstergrenzen lassen sich per Keybind die Pixelbreite definieren.
- `alwayscenter` https://dwm.suckless.org/patches/alwayscenter/
	- alle fliegeneden Fenster werden Zentriert.
-

## Installation
Teil von [SARBS](https://codeberg.org/Sergius/SARBS.git) - wird dort automatisch eingerichtet.

### Manuelle Installation

```bash
git clone https://codeberg.org/Sergius/dwm.git
cd dwm
sudo make install
```
