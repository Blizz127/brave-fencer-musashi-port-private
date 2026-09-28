/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013ED6C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800B9A02;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern u16 D_8011511A;
void func_8013E958();
extern s32 func_80141C50(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern void func_8013E958(void);
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_8011511E;
extern s32 func_8013F350(void);
extern u16 D_80115112;

void func_8013ED6C(void) {
    s32 sp10[2];
    if ((s16)func_80141C50() == 0) {
        D_801151D0 = *(s32 *)&D_801151C8[(u16)D_800B9A02 * 4];
        func_8013F350();
        func_8013FAF8(7, 8);
        if (D_8011511A == 7) {
            if ((D_8011511E & 0x810) == 0) {
                return;
            }
        }
        func_8013E958();
        D_80115112 = 4;
    }
    (void)sp10;
}
