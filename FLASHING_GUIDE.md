# Corne Single - Flashing & Setup Guide

This guide provides step-by-step instructions on how to flash the Vial-compatible firmware to your Corne Single (unibody) keyboard.

## Prerequisites
Before you begin, ensure you have the following installed on your computer:
1. **[QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)** - For flashing the firmware to the microcontroller.
2. **[Vial](https://get.vial.today/download/)** (or use the Web version at [vial.rocks](https://vial.rocks/)) - For configuring your keymap in real-time.

---

## Step 1: Locate the Firmware
Make sure you have the pre-compiled `.hex` firmware file. You can find it right in this repository under the `firmware` folder:
`firmware/corne_single_vial.hex`

*(Note: If you want to modify the source code and compile it yourself, you will need to build it using the QMK CLI or Docker).*

---

## Step 2: Flashing the Keyboard
1. Open **QMK Toolbox**.
2. Under the **Local file** section, click `Open` and select your `corne_single_vial.hex` file.
3. Check the **Auto-Flash** checkbox (this makes the flashing process start automatically once the keyboard is in bootloader mode).
4. Connect your keyboard via USB.
5. Press the physical **Reset button** on your keyboard (some boards require a quick double-tap). 
6. QMK Toolbox should display `Caterina device connected` (or similar, depending on your bootloader) in yellow text, and the flashing process will begin.
7. Wait until you see **`Flash complete`**.

---

## Step 3: Configuring via Vial
1. Open the **Vial** application on your PC.
2. Your "Corne Single" should be immediately recognized. 
3. You will see the exact physical layout of your keyboard on the screen.
4. Click on any key in the GUI to remap it, assign macros, or adjust layers. Changes are saved directly to the keyboard's memory instantly!

---

## Troubleshooting Common Issues

### 1. Keys are not registering (dead keyboard)
If your keyboard is recognized by your PC but none of the keys type anything, the physical diode direction likely doesn't match the firmware. 
- Open `config.h` and `info.json`.
- Change `DIODE_DIRECTION` from `ROW2COL` to `COL2ROW` (or vice versa).
- Recompile and flash again.

### 2. Vial displays a generic 104-key layout instead of the Corne
If Vial shows a huge standard keyboard instead of your custom split-like layout, it means your `vial.json` file is improperly formatted.
- Ensure your `keymaps/vial/vial.json` strictly follows the legacy KLE (Keyboard Layout Editor) standard.
- Use relative matrix labels (e.g., `"0,0"`, `"2,10"`) instead of arbitrary text like `"Tab"`.
- Make sure you change the `VIAL_KEYBOARD_UID` in `config.h` after fixing the JSON so that Vial clears its broken cache and re-downloads the layout.

### 3. Firmware is too large to compile (ATmega32U4)
Vial takes up a lot of memory. If your build fails with a "firmware is too large" error:
- Ensure `LTO_ENABLE = yes` is set in your `rules.mk` (this compresses the compiled code significantly).
- Disable unnecessary features in `rules.mk` such as `EXTRAKEY_ENABLE = no`, `SPACE_CADET_ENABLE = no`, or `MAGIC_ENABLE = no`.
