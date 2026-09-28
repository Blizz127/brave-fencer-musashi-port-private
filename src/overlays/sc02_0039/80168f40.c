/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80168F40 - byte-exact against retail at -O2 (tools/register_match.py). */
struct A;
struct B;
struct Bv;
struct A {
    u16 unk00; u16 unk02; u16 unk04;    
    u16 unk06;                          
    u16 unk08; u16 unk0A; u16 unk0C;    
    u16 unk0E;                          
    u8  unk10; u8 unk11; u8 unk12;      
    u8  unk13;                          
    u8  unk14; u8 unk15; u8 unk16;      
    u8  unk17;                          
    s32 unk18;                          
};
struct B  { s32 w[8]; s32 tail[2]; };
struct Bv { s32 w[8]; };
typedef struct { s32 w[8]; } Blk20;
extern Blk20 D_800AE620;

void func_80168F40(void *arg0) {
    extern Blk20 D_800AE620;
    extern s32 func_80016A5C();
    struct A a;
    struct B b;
    a.unk00 = *(u16 *)((u8 *)arg0 + 0x10);
    a.unk02 = *(u16 *)((u8 *)arg0 + 0x14);
    a.unk04 = *(u16 *)((u8 *)arg0 + 0x18);
    a.unk08 = *(u16 *)((u8 *)arg0 + 0x6);
    a.unk0A = *(u16 *)((u8 *)arg0 + 0xA);
    a.unk0C = *(u16 *)((u8 *)arg0 + 0xE);
    a.unk10 = 8;
    a.unk14 = 0xC0;
    a.unk12 = 0;
    a.unk11 = 0;
    a.unk16 = 0x80;
    a.unk15 = 0x80;
    *(struct Bv *)&b = *(struct Bv *)&D_800AE620;
    a.unk18 = 0x50000000;
    func_80016A5C(&a, &b);
}
