#pragma once

// Згенеруй свій UID командою:
// python3 -c "import os; print('{' + ', '.join([hex(b) for b in os.urandom(8)]) + '}')"
// І заміни значення нижче
#define VIAL_KEYBOARD_UID {0xD1, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88}

// Комбо для розблокування (перші дві клавіші — Tab і Q)
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
