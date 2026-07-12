# Corne Single - QMK Firmware for Unibody Pro Micro

This repository contains the custom QMK/Vial firmware configuration for a "Corne Single" — a unibody implementation of the Corne keyboard using a single ATmega32U4 Pro Micro.

## Quick Start (Recommended)

**Do you just want to plug in and use the keyboard?**
We have already pre-compiled the firmware with full [Vial](https://get.vial.today/) support! This allows you to remap keys, macros, and layers instantly using a graphical interface without ever needing to compile code.

**👉 Please see the [FLASHING_GUIDE.md](./FLASHING_GUIDE.md) for quick and easy instructions on how to flash the pre-compiled firmware and start customizing your layout!**

---

## Repository Structure

```text
corne-single/
├── config.h              ← Pins, matrix, diode direction
├── info.json             ← Keyboard metadata and layout definitions
├── rules.mk              ← MCU, bootloader, enabled features
├── firmware/
│   └── corne_single_vial.hex ← Ready-to-flash compiled firmware
└── keymaps/
    ├── default/
    │   └── keymap.c      ← Basic QMK keymap without Vial
    └── vial/
        ├── config.h      ← Unique Vial UID
        ├── vial.json     ← Layout mapping for the Vial GUI
        ├── rules.mk      ← Vial feature flags
        └── keymap.c      ← Vial-compatible keymap
```

## Matrix Definition

| | Col0 | Col1 | Col2 | Col3 | Col4 | Col5 | Col6 | Col7 | Col8 | Col9 | Col10 | Col11 | Col12 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Pin | D4 | C6 | D7 | E6 | B4 | B5 | E5 | B6 | B2 | B3 | B1 | F7 | F6 |

| | Row0 | Row1 | Row2 | Row3 |
|---|---|---|---|---|
| Pin | D3 | D2 | D1 | D0 |

*Note: Col 6 (E5) is defined in the matrix but is intentionally skipped/unused to represent the gap between the two halves of the keyboard.*

## Hardware Setup
- **Microcontroller**: ATmega32U4 (Pro Micro)
- **Bootloader**: Caterina
- **Diode Direction**: `COL2ROW` (Current flows from Column to Row)

## Compiling from Source (Advanced)

If you want to modify the core C code or compile the firmware yourself, follow these steps:

1. Clone the `vial-qmk` repository (since standard QMK does not have Vial support):
```bash
git clone https://github.com/vial-kb/vial-qmk.git
cd vial-qmk
make git-submodule
```

2. Copy this entire repository folder into the `keyboards` directory of your cloned `vial-qmk` repo:
```bash
cp -r /path/to/corne-single keyboards/corne_single
```

3. Compile the firmware using `make`:
```bash
make corne_single:vial
```
*(Note: It is recommended to use `make` instead of the `qmk compile` CLI to prevent build marker conflicts with newer QMK module generators).*
