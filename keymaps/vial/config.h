#pragma once

// Згенеруй свій UID командою:
// python3 -c "import os; print('{' + ', '.join([hex(b) for b in os.urandom(8)]) + '}')"
// І заміни значення нижче
#define VIAL_KEYBOARD_UID {0xF6, 0x07, 0x18, 0x29, 0x3A, 0x4B, 0x5C, 0x6D}

// Комбо для розблокування (перші дві клавіші — Tab і Q)
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
