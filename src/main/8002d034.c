/* Exact retail word export for [8002D034,8002D1F0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

/* func_8002D034 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_800A46BA;
extern void func_8002D29C(void);

extern s32 D_800A64B0;

extern u8 D_8006A980;
extern void func_8002DF80(void);

extern void (*D_800A4F24)(void);

extern u8 D_800A4E70;
extern s32 D_800A4E68;
extern s16 D_800A4E6C;
extern void func_8002D240(s32 a0);

extern u8 D_800A4E7A;
extern s16 D_800A4E76;
extern u16 D_800A4E74;
extern s16 D_800A4E78;

void func_8002D034(void) {
    s32 *ptr;
    s32 i;

    if (D_800A46BA) {
        func_8002D29C();
    }

    ptr = &D_800A64B0;
    for (i = 0; i < 8; i++, ptr = (s32 *)((u8 *)ptr + 0xC)) {
        if (ptr[0] != 0 && --ptr[0] == 0) {
            void (*func)(void *) = (void (*)(void *))ptr[2];
            func(ptr);
        }
    }

    if ((D_8006A980 & 0xEF) != 0) {
        func_8002DF80();
    }

    if (D_800A4F24 != NULL) {
        D_800A4F24();
    }

    if (D_800A4E70 != 0) {
        if (--D_800A4E68 == 0) {
            s32 a0 = D_800A4E6C;
            D_800A4E70 = 0;
            func_8002D240(a0);
        }
    }

    {
        register u8 *flagPtr __asm__("$8");
        flagPtr = &D_800A4E7A;
    if (*flagPtr != 0) {
        if (D_800A4E76 > (s16)D_800A4E74) {
            s16 delta = D_800A4E78;
            if ((s16)D_800A4E74 < D_800A4E76 - delta) {
                D_800A4E74 = (s16)D_800A4E74 + delta;
            } else {
                D_800A4E74 = D_800A4E76;
                *flagPtr = 0;
            }
        } else {
            s16 delta = D_800A4E78;
            if (D_800A4E76 + delta < (s16)D_800A4E74) {
                D_800A4E74 = (s16)D_800A4E74 - delta;
            } else {
                D_800A4E74 = D_800A4E76;
                *flagPtr = 0;
            }
        }

        func_8002D240((s16)D_800A4E74);
    }
    }
}
