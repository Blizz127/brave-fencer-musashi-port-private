/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80129C40 - byte-exact against retail at -O2 (tools/register_match.py). */
struct BigCopy;
struct BigCopy { s32 words[41]; };
extern void func_80016714(void *a0, s32 a1);
extern struct BigCopy D_80126DB8;
extern u8 D_80126948[];
extern struct BigCopy D_80114EE8;
extern s32 D_80126E60[];
extern s8 D_801150D6;
extern s8 D_801152C0;
extern u8 D_80127504;
extern void func_800144D4(void);

void func_80129C40(s32 _arg0)
{
    func_80016714(((u8 *)&D_80126DB8), 0xA4);
    func_80016714(D_80126948, 0xA4);
    func_80016714(((u8 *)&D_80114EE8), 0xA4);
    func_80016714(((u8 *)&D_80114EE8) + 0xA4, 0xA4);
    func_80016714(((u8 *)&D_80114EE8) + 0x148, 0xA4);
    func_80016714(((u8 *)D_80126E60), 0xA4);
    func_80016714(((u8 *)D_80126E60) + 0xA4, 0xA4);
    func_80016714(((u8 *)D_80126E60) + 0x148, 0xA4);
    D_801150D6 = 0;
    D_801152C0 = 0;
    (*(s8 *)&D_80127504) = 0;
    func_800144D4();
}
