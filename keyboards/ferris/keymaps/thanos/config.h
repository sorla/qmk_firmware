#pragma once

#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_TIMEOUT 150

#define COMBO_TERM 45
#define TAPPING_TOGGLE 2


// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 25
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

// Add a layout that allows both halves to work as mirror images
#define SH_LAYOUT(\
        L01, L02, L03, L04, L05,\
        L06, L07, L08, L09, L10,\
        L11, L12, L13, L14, L15,\
                       L16, L17\
    )\
    {\
        { L01, L02, L03, L04, L05 }, \
        { L06, L07, L08, L09, L10 }, \
        { L11, L12, L13, L14, L15 }, \
        { L16, L17, ___, ___ , ___}, \
        { L05, L04, L03, L02, L01,}, \
        { L10, L09, L08, L07, L06,}, \
        { L15, L14, L13, L12, L11,}, \
        { L17, L16, ___, ___ , ___}, \
    }

