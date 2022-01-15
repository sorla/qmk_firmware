// More readable non-keys
#define _______ KC_TRNS
#define ___x___ KC_NO

// One shot mods
#define OS_SFT OSM(MOD_LSFT)
#define OS_GUI OSM(MOD_LGUI)
#define ATAB LCA(KC_TAB)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define CBSP C(KC_BSPC)
#define OS_RALT OSM(MOD_RALT)

// Layer manipulation
#define GO_HOME TO(_COLEMAK)
#define GO_NUMS TO(_NUMBERS)
#define GO_MATHS TO(_MATHS)
#define GO_NAV TO(_NAV)

#define TG_NUMS TT(_MATHS)
#define TG_NAV  TT(_NAV)
#define MO_FUN  MO(_FUNCTION)
#define TG_MOUS TT(_MOUSE)
#define TO_MOUS TO(_MOUSE)

#define ESC_GUI MT(MOD_LGUI,KC_ESC)
#define BSP_ALT MT(MOD_LALT,KC_BSPC)
#define SPC_CTL MT(MOD_LCTL,KC_SPC)
#define ENT_SFT MT(MOD_LSFT,KC_ENT)
