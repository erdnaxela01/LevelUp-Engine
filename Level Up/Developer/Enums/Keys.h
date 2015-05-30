#ifndef __KEYS_H
#define __KEYS_H

namespace LevelUp
{
    enum LevelUpKeys
    {
        KEY_NULL,
        KEY_ARROW_UP,
        KEY_ARROW_DOWN,
        KEY_ARROW_LEFT,
        KEY_ARROW_RIGHT,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
        KEY_1,
        KEY_2,
        KEY_3,
        KEY_4,
        KEY_5,
        KEY_6,
        KEY_7,
        KEY_8,
        KEY_9,
        KEY_0,
        KEY_TAB,
        KEY_LSHIFT,
        KEY_RSHIFT,
        KEY_ENTER,
		KEY_SPACE
    };

#ifdef WIN32
    LevelUpKeys convertToKey(unsigned int k);
#endif
}


#endif