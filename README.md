# Sergi's Build von dwm
## FAQ

> Was sind die Keybindings (Tastenbindungen)?
Das ist suckless, der Quellcode ist die Dokumentation! Schau dir [config.h](config.h) an.
Ok, ok, eigentlich halte ich eine Readme in `sarbs.mom` für das ganzes System, einschließlich der Keybindings.
Drücke <kbd>Super+F1</kbd>, um es in dwm anzuzeigen (dafür wird zathura benötigt).

## Patches und Funktionen

- bar height https://dwm.suckless.org/patches/bar_height/
	- erlaubt die höhe der Statusbar in Pixeln anzugeben
- `statuscmd` https://dwm.suckless.org/patches/statuscmd/
	- mit meinem Build von [dwmblocks](https://github.com/Sergi-us/dwmblocks).
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

## Was kommt als nächstes

Das wichtigste zuerst. Es steht ein Update auf die Version 6.5 an. Danach sollen die Paches Aktualisiert werden (oder ich mache das in einem Durchgang)

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
	- Erweiterte darstellung von Farben und Symbolen im DMENU
- `setborderpx` https://dwm.suckless.org/patches/setborderpx/
	- Fenstergrenzen lassen sich per Keybind die Pixelbreite definieren.
- `alwayscenter` https://dwm.suckless.org/patches/alwayscenter/
	- alle fliegeneden Fenster werden Zentriert.
-

## Installation für Neulinge

Git-Repo runderladen
```bash
git clone https://github.com/Sergi-us/dwm.git
```
ins verzeichniss wechseln
```
cd dwm
```
DMW instalieren
```
sudo make install
```

## Ist in SARBS bereits integriert
schau dir https://github.com/Sergi-us/SARBS an
