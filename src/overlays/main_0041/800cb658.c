/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB658 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void func_800CB3BC(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
typedef struct { s32 m[8]; } Mat_800CB658;
struct Src_800CB658 {
    u8 pad0[0x34];
    Mat_800CB658 mat;
};
struct Node_800CB658 {
    u8 pad0[0x6];
    s16 unk6;
    u8 pad8[0x2];
    s16 unkA;
    u8 padC[0x2];
    s16 unkE;
    u8 pad10[0x10];
    struct Src_800CB658 *unk20;
};
struct Entity_800CB658 {
    u8 pad0[0x6];
    s16 unk6;
    u8 pad8[0x2];
    s16 unkA;
    u8 padC[0x2];
    s16 unkE;
    s16 unk10;
    s16 unk12;
    u8 pad14[0x8];
    s32 unk1C;
    u8 pad20[0x14];
    struct Node_800CB658 *unk34;
    Mat_800CB658 mat;
};
extern s32 rand(void);
extern void func_800CB3BC();

s32 func_800CB658(s32 arg0) {
    struct Node_800CB658 *node;
    struct Entity_800CB658 *ent;
    s32 v;

    node = ((struct Entity_800CB658 *)arg0)->unk34;
    if (((struct Entity_800CB658 *)arg0)->unk12 > ((struct Entity_800CB658 *)arg0)->unk10) {
        if (((struct Entity_800CB658 *)arg0)->unk1C > 0) {
            ((struct Entity_800CB658 *)arg0)->unk10 = (s16)(rand() & 0x30);
            v = -0x30;
            goto shared;
        }
    } else if (((struct Entity_800CB658 *)arg0)->unk1C < 0) {
        ((struct Entity_800CB658 *)arg0)->unk10 = (s16)((rand() & 0x30) + 0x40);
        v = 0x30;
    shared:
        ((struct Entity_800CB658 *)arg0)->unk1C = v;
    }
    ((struct Entity_800CB658 *)arg0)->unk12 = (s16)(((struct Entity_800CB658 *)arg0)->unk12 + ((struct Entity_800CB658 *)arg0)->unk1C);
    ((struct Entity_800CB658 *)arg0)->mat = node->unk20->mat;
    func_800CB3BC(arg0, 0, 0, -0x50);
    ent = ((struct Entity_800CB658 *(*)(s32, void *, s16, s16, s32, s32, s32))func_80146A6C)(0xE, (void *)arg0, ((struct Entity_800CB658 *)arg0)->unk6, ((struct Entity_800CB658 *)arg0)->unkA, ((struct Entity_800CB658 *)arg0)->unkE, 0, 0);
    if (ent != 0) {
        ent->mat = node->unk20->mat;
    }
}
