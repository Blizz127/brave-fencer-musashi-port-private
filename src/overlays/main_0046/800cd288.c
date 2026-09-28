/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD288 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801473EC(s32 *a0);
extern s32 func_801488A8(void);
extern void func_80146D90(void *arg0);
extern s32 func_80148D44(void *arg0);
extern void func_80147AD4(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_801473EC(s32*);
typedef struct Work {
      s32 unk00;
      s32 pad04[3];
      s32 unk10;
      s32 unk14;
      s32 unk18;
      s32 pad1C;
      s32 unk20;
      s32 pad24[132];
      s32 unk234;
      s32 unk238;
      s32 unk23C;
} Work;

void func_800CD288(Work *arg0) {
    s32 pad00; s32 pad04; s32 pad08; s32 pad0C;
    s32 pad10; s32 pad14; s32 pad18; s32 pad1C;
    u8 *s1;
    s32 a0;
    (void)&pad00; (void)&pad04; (void)&pad08; (void)&pad0C;
    (void)&pad10; (void)&pad14; (void)&pad18; (void)&pad1C;
    s1 = (u8 *) arg0->unk20;
    if (func_801488A8() != 0) {
        func_80146D90(arg0);
        *(s16 *) (s1 + 0x12) = func_80148D44(arg0);
        func_80147AD4(arg0, 0, 0, -0xC000);

        arg0->unk234 += arg0->unk10;
        arg0->unk238 += arg0->unk14;
        arg0->unk23C += arg0->unk18;

        if (arg0->unk234 > 0xB0000) {
            arg0->unk234 = 0xB0000;
        } else if (arg0->unk234 < -0xB0000) {
            arg0->unk234 = -0xB0000;
        }

        if (arg0->unk238 > 0xB0000) {
            arg0->unk238 = 0xB0000;
        } else if (arg0->unk238 < -0xB0000) {
            arg0->unk238 = -0xB0000;
        }

        if (arg0->unk23C > 0xB0000) {
            arg0->unk23C = 0xB0000;
        } else if (arg0->unk23C < -0xB0000) {
            arg0->unk23C = -0xB0000;
        }
    } else {
        a0 = 0;
        if (arg0->unk234 != 0) {
            a0 = 1;
            if (arg0->unk234 >= 0) {
                arg0->unk234 -= 0x8000;
                if (arg0->unk234 < 0) {
                    arg0->unk234 = 0;
                }
            } else {
                arg0->unk234 += 0x8000;
                if (arg0->unk234 >= 0) {
                    arg0->unk234 = 0;
                }
            }
        }
        if (arg0->unk238 != 0) {
            a0 = 1;
            if (arg0->unk238 >= 0) {
                arg0->unk238 -= 0x8000;
                if (arg0->unk238 < 0) {
                    arg0->unk238 = 0;
                }
            } else {
                arg0->unk238 += 0x8000;
                if (arg0->unk238 >= 0) {
                    arg0->unk238 = 0;
                }
            }
        }
        if (arg0->unk23C != 0) {
            a0 = 1;
            if (arg0->unk23C >= 0) {
                arg0->unk23C -= 0x8000;
                if (arg0->unk23C < 0) {
                    arg0->unk23C = 0;
                }
            } else {
                arg0->unk23C += 0x8000;
                if (arg0->unk23C >= 0) {
                    arg0->unk23C = 0;
                }
            }
        }
        if (a0 == 0) {
            return;
        }
    }

    arg0->unk10 = arg0->unk234;
    arg0->unk14 = arg0->unk238;
    arg0->unk18 = arg0->unk23C;
    ((void (*)(void *))func_801473EC)(arg0);
}
