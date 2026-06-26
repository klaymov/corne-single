# Corne Single — QMK firmware для однієї Pro Micro

## Структура файлів

```
corne_single/
├── config.h              ← піни, matrix, diode direction
├── info.json             ← опис клавіатури і layout
├── rules.mk              ← MCU, фічі
└── keymaps/
    ├── default/
    │   └── keymap.c      ← keymap без Vial
    └── vial/
        ├── config.h      ← UID для Vial (ЗМІНИТИ!)
        ├── vial.json     ← layout для Vial GUI
        └── keymap.c      ← keymap з Vial
```

## Встановлення QMK

### Windows
1. Завантаж QMK MSYS: https://msys.qmk.fm/
2. Запусти QMK MSYS
3. `qmk setup`

### Linux/Mac
```bash
pip3 install qmk
qmk setup
```

## Розміщення файлів

Скопіюй папку `corne_single` в:
```
~/qmk_firmware/keyboards/corne_single/
```

## Компіляція і прошивка

### Варіант A — звичайний QMK (без конфігуратора)
```bash
qmk compile -kb corne_single -km default
qmk flash -kb corne_single -km default
```

### Варіант B — з Vial (рекомендовано, є живий GUI конфігуратор)

1. Спочатку згенеруй унікальний UID:
```bash
python3 -c "import os; print('{' + ', '.join([hex(b) for b in os.urandom(8)]) + '}')"
```
2. Встав результат у `keymaps/vial/config.h` замість `{0xAB, 0xCD, ...}`

3. Клонуй Vial-QMK замість звичайного QMK:
```bash
git clone https://github.com/vial-kb/vial-qmk.git
cd vial-qmk
make git-submodule
```

4. Скопіюй папку `corne_single` туди і компілюй:
```bash
qmk compile -kb corne_single -km vial
qmk flash -kb corne_single -km vial
```

5. Завантаж Vial GUI: https://get.vial.today/
6. Підключи клавіатуру — вона з'явиться автоматично
7. Drag-and-drop клавіші без перекомпіляції!

## Matrix

| | Col0 | Col1 | Col2 | Col3 | Col4 | Col5 | Col6 | Col7 | Col8 | Col9 | Col10 | Col11 | Col12 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Pin | D4 | C6 | D7 | E6 | B4 | B5 | E5 | B6 | B2 | B3 | B1 | F7 | F6 |

| | Row0 | Row1 | Row2 | Row3 |
|---|---|---|---|---|
| Pin | D3 | D2 | D1 | D0 |

Col 6 (E5) — є в матриці але не використовується жодною клавішею (gap між половинами)

## Діоди
Анод → рядок = `ROW2COL` ✓

## Якщо щось не працює
- Перевір `DIODE_DIRECTION` — має бути `ROW2COL`
- Якщо клавіші "дзеркалять" — можливо треба змінити порядок колонок або рядків
- Якщо Pro Micro не розпізнається — затисни RST двічі швидко для входу в bootloader
