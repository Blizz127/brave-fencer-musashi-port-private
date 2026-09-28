/* Native retail instruction export [80052BEC,80052D00).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80052BEC - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
typedef struct { RECT clip; s16 ofs[2]; } DRAWENVh;
extern s16 D_800C7C88;
extern s16 D_800C7C74;
extern s16 D_800794E0[];
extern s16 D_800794E4[];
extern s16 D_800A5E50;
extern s16 D_800A5E52;
extern s16 D_800A6548;
extern s16 D_800A654A;
extern DRAWENVh D_800A6438;
extern void func_80059D68(DRAWENVh *);
extern void func_8004921C(s32, s32);
void func_80052BEC(void)
{
    s32 x, y;

    if (D_800C7C88) {
        D_800A654A = 0;
        D_800A6548 = 0;
        D_800A6438.ofs[0] = D_800A5E50 + D_800794E0[D_800C7C74];
        D_800A6438.ofs[1] = D_800A5E52 + D_800794E4[D_800C7C74];
        func_80059D68(&D_800A6438);
    } else {
        x = D_800A5E50 + *(D_800C7C74 ? D_800794E0 : D_800794E0 + 1);
        y = D_800A5E52 + *(D_800C7C74 ? D_800794E4 : D_800794E4 + 1);
        func_8004921C(x, y);
        D_800A6548 = x;
        D_800A654A = y;
    }
}
