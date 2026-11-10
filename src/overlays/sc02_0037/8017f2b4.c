/* sc02_0037: func_8017F2B4 from Druthulu/BFM-decomp
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
extern short D_800B9A02;
extern void func_8001FC08();

void func_8017F2B4(s32 param_1_a0)
{
    register s32 param_1 __asm__("$6");
    s32 base;
    s32 diff;
    s32 quot;
    u8 val;
    u8 *p;
    s32 negc;
    u8 lo;
    register u8 hi __asm__("$2");
    param_1 = param_1_a0;
    if (*(s16 *)(param_1 + 0xA) < 0xC0) {
        diff = 0xC0 - *(s16 *)(param_1 + 0xA);
        quot = (diff * 63) / 0xC0;
        __asm__("addiu %0, %1, 0x50" : "=r"(val) : "r"(quot));
        if (val >= 0x7F) {
            val = 0x7F;
        }
        base = *(s32 *)(*(s32 *)(*(s32 *)(param_1 + 0x20) + 0x24) + 0x0);
        p = (u8 *)base;
        __asm__("nop\n\taddiu %0, %1, 0x35" : "=r"(p) : "r"(p));
        *p = val;
        __asm__("addiu %0, %1, 4" : "=r"(p) : "r"(p));
        *p = val;
        __asm__("addiu %0, %1, 0x1C" : "=r"(p) : "r"(p));
        *p = val;
        __asm__("addiu %0, %1, 4" : "=r"(p) : "r"(p));
        *p = val;
        __asm__("addiu %0, %1, 0x1C" : "=r"(p) : "r"(p));
        *p = val;
        __asm__("addiu %0, %1, 4" : "=r"(p) : "r"(p));
        *p = val;
        p = (s32)p + 0x1C;
        *p = val;
        p[4] = val;
        {
            s32 x = -(s32) * (u16 *)(param_1 + 0xA);
            __asm__("addu %0, %1, $0" : "=r"(negc) : "r"(x));
            if ((s16)x > 0) {
                negc = 0;
            }
        }
        {
            s32 t0 = *(s32 *)(param_1 + 0x20);
            s32 t1 = *(s32 *)(t0 + 0x24);
            s32 loW, hiW;
            __asm__ __volatile__("addu %0, %1, $0" : "=r"(loW) : "r"(negc));
            base = *(s32 *)(t1 + 0x0);
            __asm__ __volatile__("srl %0, %1, 8" : "=r"(hiW) : "r"(negc));
            lo = (u8)loW;
            hi = (u8)hiW;
        }
        p = (u8 *)base;
        __asm__("addiu %0, %1, 0xCA" : "=r"(p) : "r"(p));
        *p = lo;
        __asm__("addiu %0, %1, 1" : "=r"(p) : "r"(p));
        *p = hi;
        __asm__("addiu %0, %1, 0x17" : "=r"(p) : "r"(p));
        *p = lo;
        __asm__("addiu %0, %1, 1" : "=r"(p) : "r"(p));
        *p = hi;
        __asm__("addiu %0, %1, 0xF" : "=r"(p) : "r"(p));
        *p = lo;
        __asm__("addiu %0, %1, 1" : "=r"(p) : "r"(p));
        *p = hi;
        p = (s32)p + 0xF;
        *p = lo;
        p[1] = hi;
        func_8001FC08(*(s32 *)(param_1 + 0x20));
    }
}
