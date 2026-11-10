/* sc02_0037: func_801805F0 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
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
extern void func_8002D4C8(s32 a0, s32 a1);
extern u16 D_80126B62;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 arg0, s32 arg1);
extern s32 func_8012BCCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern u8 D_800AF648;
extern s16 D_800B9A02;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8004914C();
extern void func_800491AC();
extern s32 func_8004955C(s32, s32, s32*, s32*);
extern void *memcpy(void *, const void *, u32);
extern s32 func_8012BCCC(s32);
extern void func_8012CBCC(s32);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_8002D4C8(int, int);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern short D_800B9A02;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32, void *);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern s32 func_8012BCCC(s32 a0);
extern void func_8012A828(s32, void*);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern s32 func_8012BCCC(s32 a0);
extern void func_8012A828(s32, void*);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012BCCC(s32 a0);
extern void func_8012A828(s32, void*);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);

void func_801805F0(s32 a0) {
    extern u8 D_800AF648;
    extern s32 D_801B1508;
    extern s32 D_801A39E8;
    extern s32 D_801A3CBC;
    extern u16 D_80126B62;
    struct {
        s16 v[3];
        s16 pad0;
        u16 sxy[2];
        s32 z;
        s32 flag;
        s32 unused[1];
    } L;
    s16 x;
    s32 y;
    if (*(s32 *)(a0 + 0x94) == 0xD) {
        L.v[0] = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x48);
        L.v[1] = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C);
        L.v[2] = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x50);
        { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_8004914C(r4); }
        { void *r4; r4 = &D_800AF648; func_800491AC(r4); }
        func_8004955C((s32)L.v, (s32)L.sxy, &L.z, &L.flag);
        if (L.flag >= 0 && (u32)((L.sxy[0] + 0x9F) & 0xFFFF) < 0x13F
                        && (u32)((L.sxy[1] + 0x77) & 0xFFFF) < 0xEF) {
            s32 vol = (s16)L.sxy[0];
            if (vol < 0) {
                vol = -vol;
            }
            vol = ((0xA0 - vol) * 127) / 160;
            func_8002D4C8(0x702, (vol | 0x1000) & 0xFFFF);
        }
    }
    if (func_8012BCCC(a0) <= 0x24000) {
        s16 c;
        c = *(u16 *)(a0 + 0x102) + 1;
        *(s16 *)(a0 + 0x102) = c;
        if (c >= 0x78) {
            if ((*(u16 *)(a0 + 0x100) & 0x2000) == 0) {
                ((void (*)(s32, s32))func_8012A828)(a0, (s32)&D_801B1508);
                *(s16 *)(a0 + 0x2) = 10;
                *(s16 *)(a0 + 0x102) = 0;
                *(s32 *)(a0 + 0x58) = (s32)&D_801A39E8 | 0x40000000 | 0x20000000;
            }
        }
    }
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) += func_8012B8E4(a0, 0x10);
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) &= 0xFFF;
    x = *(s16 *)(a0 + 0xA);
    y = *(s16 *)&D_80126B62;
    if (x <= y - 0x100) {
        *(s16 *)(a0 + 0xA) = x + 0x8;
    } else if (x >= y - 0x80) {
        *(s16 *)(a0 + 0xA) = x - 0x8;
    }
    func_8012B1B4(a0, (s32)&D_801A3CBC);
    func_8012CBCC(a0);
}
