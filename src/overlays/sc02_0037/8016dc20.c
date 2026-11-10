/* sc02_0037: func_8016DC20 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8016AE5C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
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
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef struct {
    u16 x, y, z, xpad;
    u16 vx, vy, vz, vpad;
} Work8016;
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
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
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
extern s32 D_8011D030;
extern void func_80146C3C(u8 *a0);
extern void func_80149374(s32 a0, s32 a1);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern void func_80149374(s32 arg0, s32 arg1);
extern s32 func_801619D0(void *a0);
extern void func_80149374(int, int);
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
s32 func_80128ED8(s32 param_1, s32 *param_2);
void func_80146C3C(u8 *a0);
extern s32 func_800D21C4(s32 a0, void *a1, s32 a2);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_80146C3C();
extern void func_80146C3C(u8*);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C(u8*);
extern void func_80146C3C(u8*);
extern void func_80146C3C(u8*);
extern void func_800D23D0(void *a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C(u8*);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_800D23D0(void *a0);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_80146C3C(u8*);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_800D20C0();
extern void func_80146C3C(u8*);
extern void func_80146C3C(u8*);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
s32 func_80128ED8(s32 param_1, s32 *param_2);
void func_80146C3C(u8 *a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();
extern void func_80149374(s32 a0, s32 a1);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern s32 func_800D21C4(s32 a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C(u8*);
extern void func_80149374(s32 a0, s32 a1);
extern s32 func_801619D0(void *a0);

s32 func_8016DC20(s32 param_1) {
    extern s32 D_8011D030;
    extern s16 D_801C91E8;
    extern s16 D_801C91EC;
    extern s32 D_80186F10;
    extern s32 D_80186F1C;
    u16 *p;
    short i;
    s32 obj;
    s32 r;
    s32 node;
    s32 e;
    Work8016 w;
    i = 0;
    p = (u16 *)&D_8011D030;
    obj = *(s32 *)(param_1 + 0x34);
    do {
        if ((p != (u16 *)param_1) && (*p == 0x34)) goto done;
        i = i + 1;
        p += 0x2c;
    } while (i < 0x1e);
    func_80149374(obj, param_1 + 4);
    r = func_801619D0((void *)obj);
    i = 0;
    if (r != 0) {
        p = (u16 *)&D_8011D030;
        do {
            if (*p == 0x11) goto ddb0;
            i = i + 1;
            p += 0x2c;
        } while (i < 0x1e);
        func_80146A6C(0x11, (void *)param_1, *(s16 *)(param_1 + 6),
                      (s16)(*(u16 *)(param_1 + 0xA) - 8),
                      *(s16 *)(param_1 + 0xE), 0, 0);
        w.x = *(u16 *)(param_1 + 6);
        w.y = *(u16 *)(param_1 + 0xA);
        w.z = *(u16 *)(param_1 + 0xE);
        func_800D20C0(&w.x, &w.vx, 0);
        w.vy = 0;
        func_800D23D0(&w.vx);
        i = 0;
        do {
            e = func_80146A6C(0x12, (void *)param_1, *(s16 *)(obj + 6),
                              *(s16 *)(obj + 0xA), *(s16 *)(obj + 0xE),
                              i, 0);
            if (e != 0) {
                *(s16 *)(e + 0x12) = w.vx;
                *(s16 *)(e + 0x16) = w.vy;
                *(s16 *)(e + 0x1A) = 0;
            }
            i = i + 2;
        } while (i < 3);
        goto done;
    }
ddb0:
    if (((D_801C91E8 != *(s16 *)(obj + 6)) || (D_801C91EC != *(s16 *)(obj + 0xE)))
        && (node = func_800D21C4(param_1, &D_80186F10, 0x18), node != 0)) {
        D_801C91E8 = *(u16 *)(obj + 6);
        D_801C91EC = *(u16 *)(obj + 0xE);
        func_800D1FC8(param_1, 7);
        *(s32 *)(param_1 + 0x20) = node;
        *(u16 *)(node + 0x1A) = 0x3000;
        *(u16 *)(node + 0x18) = 0x3000;
        *(u8 *)(node + 0x26) = 0xFF;
        *(u32 *)(node + 4) = *(u32 *)(node + 4) | 0x50000000;
        func_80128EA8(node, param_1 + 0x24, (s32)&D_80186F1C);
        ((s32 (*)(void *, void *))func_80128ED8)(node, param_1 + 0x24);
        *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
        return;
    }
done:
    ((void (*)(s32))func_80146C3C)(param_1);
}
