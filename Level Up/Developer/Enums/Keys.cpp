#include "Keys.h"

#ifdef WIN32
#include <Windows.h>
#endif

namespace LevelUp
{


    LevelUpKeys convertToKey(unsigned int k)
    {
        switch (k)
        {
        case 0x30:
            return KEY_0;
            break;
        case 0x31:
            return KEY_1;
            break;
        case 0x32:
            return KEY_2;
            break;
        case 0x33:
            return KEY_3;
            break;
        case 0x34:
            return KEY_4;
            break;
        case 0x35:
            return KEY_5;
            break;
        case 0x36:
            return KEY_6;
            break;
        case 0x37:
            return KEY_7;
            break;
        case 0x38:
            return KEY_8;
            break;
        case 0x39:
            return KEY_9;
            break;
        case 'A':
            return KEY_A;
            break;
        case 'B':
            return KEY_B;
            break;
        case 'C':
            return  KEY_C;
            break;
        case 'D':
            return KEY_D;
            break;
        case 'E':
            return KEY_E;
            break;
        case 'F':
            return KEY_F;
            break;
        case 'G':
            return KEY_G;
            break;
        case 'H':
            return KEY_H;
            break;
        case 'I':
            return KEY_I;
            break;
        case 'J':
            return KEY_J;
            break;
        case 'K':
            return KEY_K;
            break;
        case 'L':
            return KEY_L;
            break;
        case 'M':
            return KEY_M;
            break;
        case 'N':
            return KEY_N;
            break;
        case 'O':
            return KEY_O;
            break;
        case 'P':
            return KEY_P;
            break;
        case 'Q':
            return KEY_Q;
            break;
        case 'R':
            return KEY_R;
            break;
        case 'S':
            return KEY_S;
            break;
        case 'T':
            return KEY_T;
            break;
        case 'U':
            return KEY_U;
            break;
        case 'V':
            return KEY_V;
            break;
        case 'W':
            return KEY_W;
            break;
        case 'X':
            return KEY_X;
            break;
        case 'Y':
            return KEY_Y;
            break;
        case 'Z':
            return KEY_Z;
            break;
        case VK_RETURN:
            return KEY_ENTER;
            break;
        case VK_TAB:
            return KEY_TAB;
            break;
        case VK_LSHIFT:
            return KEY_LSHIFT;
            break;
        case VK_SHIFT:
            return KEY_RSHIFT;
            break;
        case VK_LEFT:
            return KEY_ARROW_LEFT;
            break;
        case VK_RIGHT:
            return KEY_ARROW_RIGHT;
            break;
        case VK_UP:
            return KEY_ARROW_UP;
            break;
        case VK_DOWN:
            return KEY_ARROW_DOWN;
            break;

        }
        return KEY_NULL;
    }
}