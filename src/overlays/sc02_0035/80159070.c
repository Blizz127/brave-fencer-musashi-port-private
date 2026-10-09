/* SC02.CD member35: func_80159070 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
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
extern void func_80146CA0(void *a0);
extern void func_80139914(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);
extern u8 D_80110C94[];
extern u8 D_80110CD4[];

void func_80159070(void *a0) {
    s32 obj;
    s32 r;
    s32 v;
    u8 *tbl;
    obj = *(s32 *)((u8 *)a0 + 0x20);
    *(u16 *)(obj + 0x12) = (*(u16 *)(obj + 0x12) + 0x16) & 0xFFF;
    r = func_801399F0(*(s32 *)((u8 *)a0 + 0x198));
    *(s16 *)((u8 *)a0 + 0x244) = r;
    if ((s16)r != 0) {
        func_80139914(*(s32 *)((u8 *)a0 + 0x198));
        v = *(s16 *)((u8 *)a0 + 0x244);
        *(s32 *)((u8 *)a0 + 0x198) = 0;
        switch (v) {
        default:
        case 1:
            tbl = D_80110C94;
            break;
        case 2:
            tbl = D_80110CD4;
            break;
        }
        *(s32 *)((u8 *)a0 + 0x198) = func_8013767C((s32)tbl);
        func_80146CA0(a0);
    }
}
