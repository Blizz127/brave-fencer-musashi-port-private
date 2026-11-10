/* sc02_0037: func_80159120 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801555F4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern s32 func_80029504(void);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 func_8013767C(s32 a0);
extern void func_80139914(s32 arg0);
extern s32 func_801399F0(s32 a0);
extern void func_801458E0(void);
extern u8 D_80078E50;
extern void func_801458E8(void);
extern void func_80145A2C(void);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146C98(s32 *a0, s16 a1);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80078E8C;
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern void func_80146C98(s32 *a0, s16 a1);
extern s32 func_8013767C(s32 a0);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern void func_80146C98(s32 *a0, s16 a1);
extern s32 func_8013767C(s32 a0);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern s32 func_80029504(void);
extern s32 func_801399F0(s32);
extern void func_80139914(s32 a0);
extern s32 func_80029A94(s32);
extern void func_80175454(void);
extern void func_801458E0(void);
extern void func_800298BC(void *);
extern void func_801458E8(void);
extern s32 func_8013767C(s32 a0);
extern void func_8002992C(s32);
extern void func_80145A2C(void);
extern void func_80146C98(s32 *a0, s16 a1);
extern void func_800CF804(void);
extern void func_800CF818(void);
extern u8 D_80078E50;
extern s32 D_80078E8C;
extern u8 D_80110D0C[];
extern u8 D_80110C3C[];

void func_80159120(s32 a0) {
    s32 r;
    s32 v1;
    s32 base;
    func_80029504();
    base = *(s32 *)(a0 + 0x20);
    *(u16 *)(base + 0x12) = (*(u16 *)(base + 0x12) + 0x16) & 0xFFF;
    r = func_801399F0(*(s32 *)(a0 + 0x198));
    if (r == 0) {
        return;
    }
    func_80139914(*(s32 *)(a0 + 0x198));
    *(s32 *)(a0 + 0x198) = 0;
    if (r != 1) {
        if (r == 2) {
            goto L290;
        }
    }
    v1 = *(s16 *)(a0 + 0x244);
    if (v1 != 1) {
        if (v1 == 2) {
            goto L224;
        }
    }
    if (func_80029A94(1) != 0) {
        s32 t;
        func_80175454();
        func_801458E0();
        t = D_80078E8C;
        func_800298BC(&D_80078E50);
        func_801458E8();
        D_80078E8C = t / 2;
        goto L270;
    }
    *(s32 *)(a0 + 0x198) = func_8013767C((s32)D_80110D0C);
    func_80146C98((s32 *)a0, 0xB);
    return;
L224:
    if (func_80029A94(0) != 0) {
        func_80175454();
        func_8002992C(0);
        func_80145A2C();
        goto L270;
    }
    *(s32 *)(a0 + 0x198) = func_8013767C((s32)D_80110D0C);
    func_80146C98((s32 *)a0, 0xB);
    return;
L270:
    func_80146C98((s32 *)a0, 0xC);
    func_800CF804();
    func_800CF818();
    return;
L290:
    *(s32 *)(a0 + 0x198) = func_8013767C((s32)D_80110C3C);
    func_80146C98((s32 *)a0, 0x9);
}
