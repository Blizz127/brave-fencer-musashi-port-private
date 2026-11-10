/* sc02_0037: func_8017CE7C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct S;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
struct S {
    u8 pad0[0x7E];
    u16 f7E;
};
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_80139FBC(struct obj *a0);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_8014708C(void *arg0);
extern s32 func_801472C8(struct S *a0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_8014708C(void *a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8017D030(int);
extern void func_8017D030(int);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8014708C(void *arg0);
extern s32 func_801472C8(struct S *a0);
extern void func_8017D030(int);
void func_8017D030(int param_1);

void func_8017CE7C(void *a0)
{
    void *obj;
    s32 t;
    s32 r;
    s16 i;
    u16 v;
    u16 w;
    u16 d;
    t = *(s32 *)((s32)a0 + 0x1C);
    obj = *(void **)((s32)a0 + 0x34);
    *(s32 *)((s32)a0 + 0x1C) = t + 1;
    if (t < 0x20) {
        if (*(s32 *)((s32)a0 + 0x30) == 0) {
            v = *(u16 *)((s32)obj + 0x64) - 0x80;
            w = *(u16 *)((s32)obj + 0x62) + 0x100;
            *(s16 *)((s32)obj + 0x64) = v;
            *(s16 *)((s32)obj + 0x60) = v;
            *(s16 *)((s32)obj + 0x62) = w;
        } else {
            r = *(s32 *)((s32)obj + 0x20);
            *(u16 *)(r + 0x2C) |= 0x10;
            r = *(s32 *)((s32)obj + 0x20);
            d = *(u16 *)(r + 0x1C) - 0x80;
            *(s16 *)(r + 0x1C) = d;
            *(s16 *)(r + 0x18) = d;
            r = *(s32 *)((s32)obj + 0x20);
            *(u16 *)(r + 0x1A) += 0x100;
        }
        i = 0;
        do {
            func_80146A6C(0x1B, obj, 0, 0, 0, 0, 0);
            i++;
        } while (i < 3);
    } else {
        if (*(s32 *)((s32)a0 + 0x30) == 0) {
            func_8014708C(obj);
            func_801472C8((struct S *)obj);
        } else {
            *(s32 *)(*(s32 *)((s32)obj + 0x20) + 0x4) |= 0x80000000;
        }
        *(s32 *)((s32)a0 + 0x1C) = 0;
        *(s16 *)((s32)a0 + 2) = *(u16 *)((s32)a0 + 2) + 1;
    }
    ((void (*)(void *))func_8017D030)(a0);
}
