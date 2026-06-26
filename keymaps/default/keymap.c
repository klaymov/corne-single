#include QMK_KEYBOARD_H

// 46 клавіш: 3 ряди по 12 + 10 thumb
// Layer 0 = основний, Layer 1 = символи/fn (з твого kbfirmware)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0 — основний
    // Порожні позиції (col 6) = KC_NO
    [0] = LAYOUT(
        //  col0       col1     col2     col3     col4     col5     |  col7     col8     col9     col10    col11    col12
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
        //  thumb: col1     col2     col3     col4     col5     |  col7     col8     col9     col10    col11
                 KC_LCTL, MO(1),   KC_SPC,  KC_DOWN, KC_UP,      KC_LEFT, KC_RGHT, KC_ENT,  MO(2),   KC_LALT
    ),

    // Layer 1 — символи (з kbfirmware Layer 1)
    [1] = LAYOUT(
        KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,    KC_SCLN, KC_QUOT, KC_GRV,  KC_COMM, KC_SLSH, KC_RBRC,
        LCTL(KC_BSPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_LABK, KC_RABK, KC_TRNS, KC_TRNS,
                 KC_LCTL, KC_TRNS, KC_SPC,  KC_DOWN, KC_UP,       KC_LEFT, KC_RGHT, KC_LGUI, KC_TRNS, KC_LALT
    ),

    // Layer 2 — media/fn (з kbfirmware Layer 2)
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_F1,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT,    KC_VOLU, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
