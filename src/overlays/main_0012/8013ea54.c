/* Overlay range [8013EA54,8013EB7C) from MAIN.CD member 0012.
 * SHA256(span)=902848e250c9aacd584341b922f005a7da75dd6271a53347c5038a8aabce348e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013EA54 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern s16 currentLocationId;
extern void func_8002D4C8(s32 a0, s32 a1);
extern short currentLocationId;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern void func_80137B80(void);
extern unsigned short D_80115112;
void func_8013E958();
extern s32 func_80141C50(void);
extern void func_8013F244(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern void func_8013E958(void);
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern s32 D_80115130;
extern s16 D_8011514C;

void func_8013EA54(void) {
    s32 sp10[2];
    if ((s16)func_80141C50() == 0) {
        D_801151D0 = *(s32 *)&D_801151C8[(u16)D_800B9A02 * 4];
        func_8013F244();
        func_8013FAF8(0, 5);
        func_80137B80();
        if (D_8011511E & 0x40) {
            if (D_8011511A == 0 && currentLocationId == 0x308F) {
                func_8002D4C8(0x466, 0);
            } else {
                u16 v = D_8011511A;
                if (v != 4) {
                    D_80115130 = 0;
                }
                if ((u16)(v - 1) <= 1) {
                    D_8011514C = 0;
                }
                func_8002D4C8(0x45D, 0);
                D_80115112 += 1;
            }
        } else if (D_8011511E & 0x810) {
            func_8013E958();
        }
    }
    (void)sp10;
}
