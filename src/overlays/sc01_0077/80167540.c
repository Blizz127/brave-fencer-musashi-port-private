/* sc01_0077: func_80167540 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct Sub2_80167540 {
    u8 pad0[0x44];
    s32 unk44;
};
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
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
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef void (*code)(unsigned short *);
struct Fr {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_80167AE0 {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_8016A290 {
    SVEC_8016A290 center;
    SVEC_8016A290 diff;
    s32 pos[3];
    s32 _pad1c;
    s16 mtx[32];
    SVEC_8016A290 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
typedef struct { s16 x, y, z, pad; } SVec_801670E4;
typedef struct {
               u16 cx, cy, cz;
               u16 _p06;
               u16 a8[4];
               s32 pos[3];
               s32 _p1C;
               SVec_801670E4 v[4];
               struct { u8 r, g, b, cd; } col[4];
               u32 code;
               s32 _p54;
               u8 m1[0x20];
               u8 m2[0x20];
} Fr_801670E4;
extern s32 func_801670E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80161CD0(s32 a0, s32 a1);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80147324(s32 arg0);
extern s32 func_800CF8B4();
extern void func_801599A4(void *a0);
extern void func_80162CCC(void);
extern void func_80016714(void *a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BDD0(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_8015BF48(s32 *a0);
extern s32 func_80161208();
extern s32 func_8005C49C(void);
extern void func_8015BDD0(s32 *a0);
extern void func_801599A4(void *a0);
extern s32 func_80161208();
extern int func_8005C49C(void);
extern s32 func_80161CD0(s32 a0, s32 a1);
extern s32 func_800CF8B4(void);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80161208();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_800CF8B4(void);
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80147324(s32 arg0);
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80147324(s32 arg0);
extern s32 func_800CF8B4();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_8016191C(void *a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(int a0, int a1);
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
extern void func_80147324();
extern void func_80147324(s32 arg0);
extern int func_800CF8B4();
extern void func_80147324(int arg0);
extern unsigned short D_80189604;
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
extern void func_80147324(s32 arg0);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void func_80147324(s32 arg0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80162CCC();
extern void func_80162CCC();
extern void func_80162CCC();
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern void func_80016714(void *a0, s32 a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
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
                ((struct Entity_80167540 *)arg0)->unk10 = (s16) (func_8005C49C() & 0x30);
                v = -0x30;
                goto shared;
            }
        } else if (((struct Entity_80167540 *)arg0)->unk1C < 0) {
            ((struct Entity_80167540 *)arg0)->unk10 = (s16) ((func_8005C49C() & 0x30) + 0x40);
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
