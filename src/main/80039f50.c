/* Main-exec range [80039F50,8003A098) from the SLUS executable.
 * SHA256(span)=98b78d3a359472689bbe2ba1742c6f72837e597c3ee2ff8224b02d3fe9a4083d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80039F50 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern void func_80039C70(u8 *arg0, s16 arg1, s16 arg2);   
extern void func_80039DEC();  

void func_80039F50(u8 **a0, s16 a1)
{
    register u8 **pvVar4 __asm__("$7"); 
    u8 *pbVar3;
    register s32 bVar1 __asm__("$4"); 
    u8 bVar2;
    register u8 *pbVar5 __asm__("$2"); 
    u8 bVar6;

    pvVar4 = a0;
    pbVar3 = *pvVar4;
    *pvVar4 = pbVar3 + 1;
    bVar1 = *pbVar3;
    *pvVar4 = pbVar3 + 2;
    bVar2 = pbVar3[1];

    switch (bVar1) {
    case 6:
        func_80039C70(pvVar4, a1, bVar2);
        break;
    case 7:
        pbVar5 = (u8 *)pvVar4 + a1 * 0x1A;
        pbVar5[0x1B] = bVar2;
        break;
    case 8:
        break;
    case 0xA:
        pbVar5 = (u8 *)pvVar4 + a1 * 0x1A;
        pbVar5[0x1E] = bVar2;
        break;
    case 0x62:
        pbVar5 = (u8 *)pvVar4 + a1 * 0x1A;
        bVar6 = pbVar5[0x21];
        pbVar5[0x20] = bVar2;
        pbVar5[0x22] = bVar2 + 1;
        pbVar5[0x21] = bVar6 | 2;
        break;
    case 0x63:
        func_80039DEC(pvVar4, a1, bVar2);
        break;
    }
}
