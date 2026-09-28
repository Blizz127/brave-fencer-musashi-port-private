/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCB20 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCB20(void *a0) {
    extern void func_80154150(s32 a0, s32 a1);
    extern void func_801483E8(u8 *a0);
    extern void func_8014CBF8(void *a0);
    extern void func_801474EC(s32 *a0);
    extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
    extern void func_801477E8(s32 *a0, s32 a1);
    extern s32 func_800CCEA0(void *a0);

    func_80154150((s32)a0, 0xF);
    func_801483E8((u8 *)a0);
    func_8014CBF8(a0);
    func_801474EC((s32 *)a0);
    func_80146DE8((s32 *)a0, 0, 0, 0);
    func_801477E8((s32 *)a0, 0xffee0000);
    func_800CCEA0(a0);
}
