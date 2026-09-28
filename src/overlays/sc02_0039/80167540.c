/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80167540 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
struct Sub2_80167540 {
    u8 pad0[0x44];
    s32 unk44;         
};
typedef struct { s32 m[8]; } Mat_80167540;
struct Src_80167540 {
    u8 pad0[0x34];
    Mat_80167540 mat;           
};
struct Node_80167540 {
      u16 unk0;
    u8 pad2[0x4];
      s16 unk6;
    u8 pad8[0x2];
      s16 unkA;
    u8 padC[0x2];
      s16 unkE;
    u8 pad10[0x10];
      struct Src_80167540 *unk20;
    u8 pad24[0x28];
      struct Sub2_80167540 *unk4C;
};
struct Entity_80167540 {
      s16 unk0;
      u16 unk2;
    u8 pad4[0xC];
      s16 unk10;
      s16 unk12;
    u8 pad14[0x8];
      s32 unk1C;
    u8 pad20[0x10];
      s32 unk30;
      struct Node_80167540 *unk34;
      Mat_80167540 mat;
};
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 rand(void);
extern int rand(void);
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);
extern void func_80146C3C();
extern void func_80146C3C(void);
s32 func_801670E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 func_80167540(s32 arg0) {

    struct Node_80167540 *node;
    struct Entity_80167540 *ent;
    s32 v;

    node = ((struct Entity_80167540 *)arg0)->unk34;
    if (node->unk0 == 1) {
        if (((struct Entity_80167540 *)arg0)->unk12 > ((struct Entity_80167540 *)arg0)->unk10) {
            if (((struct Entity_80167540 *)arg0)->unk1C > 0) {
                ((struct Entity_80167540 *)arg0)->unk10 = (s16) (rand() & 0x30);
                v = -0x30;
                goto shared;
            }
        } else if (((struct Entity_80167540 *)arg0)->unk1C < 0) {
            ((struct Entity_80167540 *)arg0)->unk10 = (s16) ((rand() & 0x30) + 0x40);
            v = 0x30;
shared:
            ((struct Entity_80167540 *)arg0)->unk1C = v;
        }
        ((struct Entity_80167540 *)arg0)->unk12 = (s16) (((struct Entity_80167540 *)arg0)->unk12 + ((struct Entity_80167540 *)arg0)->unk1C);
        ((struct Entity_80167540 *)arg0)->mat = node->unk20->mat;
        ((void (*)(struct Entity_80167540 *, s32, s32, s32))func_801670E4)(((struct Entity_80167540 *)arg0), 0, 0, 0);
        ent = ((struct Entity_80167540 *(*)(s32, struct Entity_80167540 *, s16, s16, s32, s32, s32))func_80146A6C)(0xE, ((struct Entity_80167540 *)arg0), node->unk6, node->unkA, node->unkE, 0, 0);
        if (ent != 0) {
            ent->mat = node->unk20->mat;
        }
        if (((struct Entity_80167540 *)arg0)->unk34->unk4C->unk44 & 0x20) {
            ((struct Entity_80167540 *)arg0)->unk30 = 0x600;
            ((struct Entity_80167540 *)arg0)->unk2 = (u16) (((struct Entity_80167540 *)arg0)->unk2 + 1);
        }
    } else {
        ((void(*)(struct Entity_80167540 *))func_80146C3C)(((struct Entity_80167540 *)arg0));
    }
}
