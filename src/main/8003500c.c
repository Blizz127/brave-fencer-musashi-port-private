/* Exact retail word export for [8003500C,800351E8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8003500C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_8006AEF5;
extern s32 D_8006AEF8;
extern s32 D_8006AEFC;
extern u8 D_80076118[];
extern u8 D_80076138[];
extern s32 D_80076114;
extern u8 D_8007620C;

void func_8003500C(void) {
    if (D_8006AEF5 != 0) {
        return;
    }

    if (D_8006AEFC != D_8006AEF8) {
        s32 idx = D_8006AEF8;
        u8 *self = D_80076118 + idx * 0x30;

        if (self[0] != 0) {
            register s32 (*fn8)(void *) __asm__("$3") = *(s32 (**)(void *))(self + 8);
            register s32 type __asm__("$2") = self[4];

            D_80076114 = type;
            if (fn8(self) == 0) {
                return;
            }

            {
                register s32 (*fn1C)(s32) __asm__("$6") = *(s32 (**)(s32))(self + 0x1C);
                register s32 type2 __asm__("$5") = self[4];

                D_80076114 = type2;
                if (fn1C != NULL) {
                    fn1C(*(s32 *)(D_80076138 + D_8006AEF8 * 0x30));
                }
            }

            self[0] = 0;
            self[1] = 0;
            D_8006AEF8 += 1;
            if ((u32)D_8006AEF8 >= 4) {
                D_8006AEF8 = 0;
            }
            if (D_8006AEF8 == D_8006AEFC) {
                D_80076114 = 0;
            }
            return;
        } else {
            if (self[1] != 0 && self[7] == 0) {
                s32 (*fn24)(void *) = *(s32 (**)(void *))(self + 0x24);

                if (fn24 != NULL) {
                    fn24(self);
                }
                if (self[2] != 0) {
                    return;
                }
            }

            self[1] = 0;
            D_8006AEF8 += 1;
            if ((u32)D_8006AEF8 >= 4) {
                D_8006AEF8 = 0;
            }
            if (D_8006AEF8 == D_8006AEFC) {
                D_80076114 = 0;
            } else {
                D_80076114 = 1;
            }
            return;
        }
    } else {
        D_8007620C = 0;
    }
}
