/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013A0A4 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8013A0A4;
struct S8013A0A4 {
    u8 pad0[4];
    s16 field_4;
    u8 pad6[2];
    s32 field_8;
    u8 pad12[10];
    u16 field_16;
    u8 pad18[6];
    u8 field_1E;
    u8 pad1F[15];
    s16 field_2E;
};
extern void func_80139B18(s32 a0);
void func_80139A8C(s32 a0);
void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);

void func_8013A0A4(struct S8013A0A4 *a0) {
    if (a0->field_1E != 0) {
        a0->field_1E = a0->field_1E + 5;
    } else {
        a0->field_1E = 4;
    }
    if (a0->field_1E >= 0xC) {
        a0->field_16 = (a0->field_16 + 1) % (a0->field_2E + 1);
        a0->field_1E = 0;
        if (a0->field_8 & 0x100) {
            a0->field_4 = 6;
        } else {
            a0->field_4 = 2;
        }
    }
    func_80139A8C((s32)a0);
    func_80139B18((s32)a0);
}
