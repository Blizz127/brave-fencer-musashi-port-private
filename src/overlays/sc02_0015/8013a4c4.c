/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013A4C4 - byte-exact against retail at -O2 (tools/register_match.py). */
struct Inner8013A4C4;
struct S8013A4C4;
struct Inner8013A4C4 {
    u8 pad28[0x28];
    s16 unk28;      
    s16 unk2A;      
};
struct S8013A4C4 {
    s16 unk0;       
    s16 unk2;       
    struct Inner8013A4C4 *unk4;   
    u8 padE[6];
    s16 unkE;       
};
extern void func_8013A530();

void func_8013A4C4(struct S8013A4C4 *a0) {
    struct Inner8013A4C4 *a1 = a0->unk4;
    a0->unkE = 0;
    a1->unk28 -= 0x400;
    a1->unk2A -= 0x400;
    if (a1->unk28 < 0x401) {
        a1->unk2A = 0;
        a1->unk28 = 0;
        a0->unk0 = 4;
        a0->unk2 = 0;
        a0->unk4 = 0;
    } else {
        func_8013A530();
    }
}
