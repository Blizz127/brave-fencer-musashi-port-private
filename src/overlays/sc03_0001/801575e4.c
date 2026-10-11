/* sc03_0001: func_801575E4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern s32 D_8011F730;
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147300(u16 arg0);
extern void func_80147324(s32 arg0);
extern void func_8014B768(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154A74(s32 a0, s32 a1);
void func_80156648(s32 *a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80156648(s32 *a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8014B768(s32 a0, s32 a1);
extern void func_80147300(u16 arg0);
extern void func_80146CA0(void *a0);
extern u8 D_800D4F14[];
extern s32 D_8011F730;

void func_801575E4(void *a0) {
    s32 v;
    func_80154A74((s32)a0, 0x15);
    v = *(u8 *)((u8 *)a0 + 0x1AB) ^ 1;
    *(u8 *)((u8 *)a0 + 0x1AB) = v;
    if (v != 0) {
        *(u8 *)((u8 *)a0 + 0x1AA) = 0xA;
    } else {
        *(u8 *)((u8 *)a0 + 0x1AA) = 0xB;
    }
    func_80154274((s32 *)a0, (s32)D_800D4F14);
    func_80147324(0x455);
    func_80146E90((s32 *)a0, 0);
    func_80156648((s32 *)a0);
    func_80146994(0x5, (s32)a0, 0, 0);
    func_8014B768((s32)a0, 0x333);
    func_80147300(0x5F3);
    D_8011F730 |= 4;
    func_80146CA0(a0);
}
