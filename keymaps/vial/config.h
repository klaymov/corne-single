#pragma once

// Згенеруй свій UID командою:
// python3 -c "import os; print('{' + ', '.join([hex(b) for b in os.urandom(8)]) + '}')"
// І заміни значення нижче
#define VIAL_KEYBOARD_UID {0xAB, 0xCD, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC}

// Комбо для розблокування (перші дві клавіші — Tab і Q)
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
