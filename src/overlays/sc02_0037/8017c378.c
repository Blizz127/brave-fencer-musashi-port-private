/* sc02_0037: func_8017C378 from Druthulu/BFM-decomp
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
extern s16 D_800B9A08;
extern short D_800B9A08;
extern u16 D_80126B62;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];
extern u8 D_80126B5C;
extern void func_8012BD14(s32 a0);
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
extern s32 func_800291B4(s32 arg);
extern s32 func_8005C49C(void);
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
extern s32 func_80013328(s32 a0, s32 a1);
extern u16 D_800B99DA;
extern int func_8005C49C(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_801746A4(void);
extern s32 func_80178B18(s32 param_1, s32 param_2);
void func_8017BEBC(s32 param_1, s32 param_2);
extern s32 func_800291B4(s32 arg);
extern s32 func_800291B4(s32 arg);
extern s16 D_800B9A08;
extern s32 func_80013328(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_801746A4(void);
extern s32 func_80178B18(s32 param_1, s32 param_2);
extern void func_8017BEBC(s32 a0, s32 a1);
extern void func_8012BD14(s32 a0);

void func_8017C378(s32 a0) {
    extern u16 D_800B99DA;
    extern u8 D_80126B5C;
    extern u8 D_801202A0[];
    extern u16 D_80126B62;
    extern s16 D_80115214;
    extern u8 D_80187654[];
    extern u8 D_801876B8[];
    s32 s0 = *(s32 *)(a0 + 0x20);
    s16 found;
    s32 lvl;
    s16 i;
    s16 j;
    s32 rand_val;
    if ((D_800B99DA & 0xF) == 0) {
        u8 *p;
        u8 *end;
        for (p = D_801202A0, end = p + 0x6480; p < end; p += 0x10C) {
            if (*(u16 *)p == 0x128) {
                found = ((s32)p == a0);
                break;
            }
        }
        lvl = func_80013328(a0 + 4, (s32)&D_80126B5C);
        if (lvl < 0x800) {
            lvl = 0x44 - ((lvl >> 5) & 0x38);
        } else {
            lvl = 4;
        }
        if (found != 0 || D_80115214 < lvl) {
            D_80115214 = lvl;
        }
    }
    *(u16 *)(s0 + 0x12) += 0x20;
    rand_val = func_8005C49C();
    func_8017BEBC(a0, rand_val & 0xF);
    if (*(u16 *)(a0 + 0x5E) != 0) {
        for (i = 0; (u16)i < 8; i++) {
            if (*(u16 *)(a0 + 0x5E) == D_80187654[i]) {
                func_801746A4();
                *(s32 *)(a0 + 0x1C) = 0x20;
                *(u16 *)(a0 + 0x2) += 1;
            }
        }
        *(s16 *)(a0 + 0x5E) = 0;
        return;
    }
    if (*(s16 *)(a0 + 0x10A) != 0) {
        return;
    }
    j = 5;
    do {
        if ((func_800291B4(j + 0x3B) & 0xFF) != 0) {
            break;
        }
        j++;
    } while (j < 0x28);
    if (j != 0x28) {
        *(s16 *)(a0 + 0x10A) = 1;
    } else if (((s32 (*)(s32))func_8012BD14)(a0) < 0x2A40) {
        if (D_800B9A08 == 0x3028) {
            if ((u16)(*(u16 *)(a0 + 0xA) - D_80126B62 + 4) < 4) {
                *(u16 *)(a0 + 0x106) += 1;
            }
            if (*(s16 *)(a0 + 0x106) < 2) {
                return;
            }
        }
        func_80178B18(a0, (s32)D_801876B8);
        *(s16 *)(a0 + 0x10A) = 1;
        *(s16 *)(a0 + 0x2) = 0xA;
    } else {
        *(s16 *)(a0 + 0x106) = 0;
    }
}
