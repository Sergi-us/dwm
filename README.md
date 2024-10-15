# Sergi's Build von dwm

## FAQ

> Was sind die Keybindings (Tastenbindungen)?
Das ist suckless, der Quellcode ist die Dokumentation! Schau dir [config.h](config.h) an.
Ok, ok, eigentlich halte ich eine Readme in `sarbs.mom` für das ganzes System, einschließlich der Keybindings.
Drücke <kbd>Super+F1</kbd>, um es in dwm anzuzeigen (dafür wird zathura benötigt).

## Patches und Funktionen

- [Klickbare Statusleiste](https://dwm.suckless.org/patches/statuscmd/) mit meinem Build von [dwmblocks](https://github.com/Sergi-us/dwmblocks).
- Liest [xresources](https://dwm.suckless.org/patches/xresources/) Farben/Variablen (d.h. funktioniert mit `pywal`, etc.).
- Scratchpad: Zugänglich mit <kbd>Mod+Shift+Enter</kbd>.
- Neue Layouts: bstack, fibonacci, deck, centered master und mehr. Alle gebunden an die Tasten <kbd>Super+(Shift+)t/z/u/i</kbd>.
- Echter Vollbildmodus (<kbd>Super+f</kbd>) und verhindert Fokuswechsel.
- Fenster können sticky (fixiert) gemacht werden (<kbd>Super+s</kbd>).
- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/) versteckt Tags ohne Fenster.
- [stacker](https://dwm.suckless.org/patches/stacker/): Fenster manuell im Stack nach oben/unten bewegen (<kbd>Super-K/J</kbd>).
- [shiftview](https://dwm.suckless.org/patches/nextprev/): Durch Tags zyklisch wechseln (<kbd>Super+g/;</kbd>).
- [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Lücken in allen Layouts erlaubt.
- [swallow patch](https://dwm.suckless.org/patches/swallow/): Wenn ein aus einem Terminal gestartetes Programm es unbenutzbar machen würde, nimmt es vorübergehend dessen Platz ein, um Platz zu sparen.

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
