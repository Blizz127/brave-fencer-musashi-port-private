/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013B6A0 - byte-exact against retail at -O0 (tools/register_match.py). */
typedef struct {
        s32 f0;
        u16 f4;
        u16 f6;
        u16 f8;
        u16 fA;
        s32 fC;
        u8  pad[0xC];
    } Ent_8013B6A0_8013B6A0;
typedef struct {
        u16 f0;
        u16 f2;
        u16 f4;
    } Src_8013B6A0_8013B6A0;

void func_8013B6A0(s32 idx, u16 *src, s32 val)
{
    extern Ent_8013B6A0_8013B6A0 D_80190578[];

    D_80190578[idx].f0 = 1;
    D_80190578[idx].f4 = ((Src_8013B6A0_8013B6A0 *)src)->f0;
    D_80190578[idx].f6 = ((Src_8013B6A0_8013B6A0 *)src)->f2;
    D_80190578[idx].f8 = ((Src_8013B6A0_8013B6A0 *)src)->f4;
    D_80190578[idx].fC = val;
}
