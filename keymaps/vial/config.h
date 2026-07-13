#pragma once

// Згенеруй свій UID командою:
// python3 -c "import os; print('{' + ', '.join([hex(b) for b in os.urandom(8)]) + '}')"
// І заміни значення нижче
#define VIAL_KEYBOARD_UID {0x91, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F, 0x70}

// Комбо для розблокування (перші дві клавіші — Tab і Q)
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
