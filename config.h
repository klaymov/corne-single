#pragma once

#define MATRIX_ROWS 4
#define MATRIX_COLS 13

// Rows: D3=0, D2=1, D1=2, D0=3
#define MATRIX_ROW_PINS { D3, D2, D1, D0 }

// Cols: 0=D4, 1=C6, 2=D7, 3=E6, 4=B4, 5=B5, 6=E5, 7=B6, 8=B2, 9=B3, 10=B1, 11=F7, 12=F6
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5, E5, B6, B2, B3, B1, F7, F6 }

// Анод діода іде до рядку => ROW2COL
#define DIODE_DIRECTION ROW2COL

// Базові налаштування
#define TAPPING_TERM 200
