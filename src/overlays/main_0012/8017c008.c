/* Exact overlay word export for [8017C008,8017C080) from MAIN.CD
 * member0012 (extracted/overlays/main/0012.bin offset 0x7BEB0, base 80128158).
 * Callee of live STOP 8017BF38; jal 8002D4C8.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017C008 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern void *D_8011DB24;
extern u8 D_800B9A15;
extern unsigned char D_800B9A13;
extern u16 D_80115110;
extern unsigned short D_80115112;
extern u16 D_80115112;
extern void func_8002D4C8(int, int);
void func_8002D4C8(s32 a0, s32 a1);

void func_8017C008(s32 a0, s32 a1) {
    extern u8 D_800B9A15;
    extern unsigned char D_800B9A13;
    extern u16 D_80115110;
    extern unsigned short D_80115112;
    extern s16 D_80115126;
    extern s16 D_801857F0;
    extern s16 D_801857EC;
    extern void *D_8011DB24;
    extern void func_8017C080(void);
    void *func_ptr;

    D_800B9A15 = 1;
    D_800B9A13 = 5;
    D_80115110 = 4;
    func_ptr = func_8017C080;
    D_80115126 = a0;
    D_801857F0 = a1;
    D_801857EC = a1;
    D_80115112 = 0;
    D_8011DB24 = func_ptr;
    func_8002D4C8(0x1E, 0);
}
