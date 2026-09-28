/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB228 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CAF84();
extern void func_800CAF84();
typedef struct {
    s32 a, b, c, d;
} Blk16;

void func_800CB228(s32 arg0) {
    register s32 ent __asm__("$7");
    register s32 oth __asm__("$5");
    s32 cnt;
    s32 p;
    u16 t0;
    u16 t1;

    ent = arg0;
    cnt = *(s32 *)(ent + 0x1C);
    oth = *(s32 *)(ent + 0x34);
    *(s32 *)(ent + 0x1C) = cnt + 1;
    if (cnt < 10) {
        *(u16 *)(ent + 0x28) = *(u16 *)(ent + 0x28) + 0x120;
    } else {
        t0 = *(u16 *)(ent + 2);
        *(s16 *)(ent + 0x12) = (*(u16 *)(oth + 0x12) << 16) >> 17;
        t1 = *(u16 *)(oth + 0x1A);
        t0 += 1;
        *(s32 *)(ent + 0x30) = 0x20;
        *(s32 *)(ent + 0x1C) = -0xC0;
        *(u16 *)(ent + 0x2A) = 0x500;
        *(u16 *)(ent + 2) = t0;
        *(s16 *)(ent + 0x1A) = (t1 << 16) >> 17;
    }
    p = *(s32 *)(oth + 0x20);
    *(Blk16 *)(ent + 0x38) = *(Blk16 *)(p + 0x34);
    *(Blk16 *)(ent + 0x48) = *(Blk16 *)(p + 0x44);
    func_800CAF84(ent);
}
