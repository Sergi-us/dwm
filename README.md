# 🪟 dwm - Dynamic Window Manager

**Sergi's Build mit Patches für SARBS**

> **🔄 Umzug zu Codeberg**: Die aktive Entwicklung und Kollaboration findet jetzt auf [Codeberg](https://codeberg.org/Sergius/dwm) statt. GitHub dient nur als Mirror.
> 
> **📦 Hauptprojekt**: [SARBS](https://codeberg.org/Sergius/SARBS) - [Homepage](https://sarbs.xyz/sarbs/)

Minimalistischer, schneller Tiling Window Manager - das Herzstück von SARBS.

## ❓ FAQ

> **Was sind die Keybindings?**

Das ist Suckless - der Quellcode ist die Dokumentation! Schau dir [config.h](config.h) an.

Für das komplette System gibt's eine Dokumentation in `sarbs.mom`. Drücke <kbd>Super+F1</kbd> in dwm, um sie mit zathura anzuzeigen.

## ✨ Patches & Features

### Statusbar & Darstellung
- **`bar height`** - Statusbar-Höhe in Pixeln anpassbar  
  https://dwm.suckless.org/patches/bar_height/
- **`statuscmd`** - Mausinteraktion mit Statusbar (mit dwmblocks)  
  https://dwm.suckless.org/patches/statuscmd/
- **`xresources`** - Liest Farben aus Xresources (pywal-kompatibel)  
  https://dwm.suckless.org/patches/xresources/
- **`hide vacant tags`** - Versteckt Tags ohne Fenster  
  https://dwm.suckless.org/patches/hide_vacant_tags/

### Fenster-Management
- **`scratchpad`** - Versteckte Terminals (<kbd>Mod+Shift+Enter</kbd>, <kbd>Mod+Shift+Druck</kbd>)  
  https://dwm.suckless.org/patches/scratchpads/
- **`swallow`** - Window Swallowing - Programme nehmen Terminal-Platz ein  
  https://dwm.suckless.org/patches/swallow/
- **`actualfullscreen`** - Echter Fullscreen (<kbd>Super+f</kbd>)  
  https://dwm.suckless.org/patches/actualfullscreen/
- **`sticky`** - Fenster fixieren (<kbd>Super+s</kbd>)  
  https://dwm.suckless.org/patches/sticky/
- **`stacker`** - Fenster manuell im Stack bewegen (<kbd>Super+K/J</kbd>)  
  https://dwm.suckless.org/patches/stacker/

### Layouts
- **Neue Layouts**: bstack, fibonacci, deck, centered master und mehr
- **Keybindings**: <kbd>Super+(Shift+)t/z/u/i</kbd>
- **`vanitygaps`** - Lücken in allen Layouts  
  https://dwm.suckless.org/patches/vanitygaps/

### Navigation
- **`shiftview`** - Durch Tags zyklisch wechseln (<kbd>Super+g/;</kbd>)  
  https://dwm.suckless.org/patches/nextprev/

## 🚀 Geplante Patches

**Update auf Version 6.6 ist vollzogen**, danach folgen:

> Ich überlege noch welche Patches folgen - das hier ist lediglich eine Sammlung an Patches die mir gefallen und noch nicht implementiert sind.

- **`movestack`** - Alternative zu stacker  
  https://dwm.suckless.org/patches/movestack/
- **`resizehere`** - Maus springt nicht ins Eck bei Floating-Resize  
  https://dwm.suckless.org/patches/resizehere/
- **`statusallmons`** - Statusbar auf allen Monitoren  
  https://dwm.suckless.org/patches/statusallmons/
- **`pertag`** - Unterschiedliche Layouts pro Tag  
  https://dwm.suckless.org/patches/pertag/
- **`tiledmove`** - Fenster per Maus im Tiling verschieben  
  https://dwm.suckless.org/patches/tiledmove/
- **`unfloatvisible`** - Floating zurück in den Stack  
  https://dwm.suckless.org/patches/unfloatvisible/
- **`status2d`** - **Aktuell in Arbeit!** - Erweiterte Farben/Symbole in dwmblocks  
  https://dwm.suckless.org/patches/status2d/
- **`setborderpx`** - Fenstergrenzen per Keybind anpassen  
  https://dwm.suckless.org/patches/setborderpx/
- **`alwayscenter`** - Floating-Fenster zentrieren  
  https://dwm.suckless.org/patches/alwayscenter/

## ⚡ Installation

### Automatisch mit SARBS (empfohlen)
Wird durch das [SARBS-Installationsskript](https://codeberg.org/Sergius/SARBS) automatisch eingerichtet.

### Manuell
```bash
git clone https://codeberg.org/Sergius/dwm.git
cd dwm
sudo make install
```

## 🛠️ Konfiguration

Anpassungen in `config.h` vornehmen, dann:

```bash
sudo make clean install
```

## 📚 Weitere SARBS-Komponenten

- **[SARBS Hauptprojekt](https://codeberg.org/Sergius/SARBS)** - Auto-Rice Bootstrapping
- **[dotfiles](https://codeberg.org/Sergius/dotfiles)** - Konfigurationsdateien
- **[st](https://codeberg.org/Sergius/st)** - Terminal Emulator
- **[dmenu](https://codeberg.org/Sergius/dmenu)** - Application Launcher
- **[dwmblocks-async](https://codeberg.org/Sergius/dwmblocks-async)** - Statusbar
- **[surf](https://codeberg.org/Sergius/surf)** - Web Browser
- **[tabbed](https://codeberg.org/Sergius/tabbed)** - Tab Interface

## 🤝 Credits

- **[suckless.org](https://suckless.org/)** - Original dwm
- **[Luke Smith](https://github.com/LukeSmithxyz/dwm)** - Patch-Inspiration

## 📄 Lizenz

Siehe [LICENSE](LICENSE) Datei.

---

**📧 Kontakt**:
- [Codeberg Issues](https://codeberg.org/Sergius/dwm/issues)
- [GitHub Issues](https://github.com/Sergi-us/dwm/issues) (Mirror)
- [SARBS Homepage](https://sarbs.xyz/kontakt/)
