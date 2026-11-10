/* sc02_0037: func_8016EC0C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8016AE5C.c (preprocessed; only the declarations it uses),
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
typedef struct {
                   s16 x;
                   s16 y;
                   s32 u04;
                   s16 u08;
                   s16 u0A;
                   s16 u0C;
                   s16 u0E;
                   u8 r;
                   u8 g;
                   u8 b;
                   u8 pad13;
                   s32 u14;
                   u8 u18;
                   u8 pad19[3];
    } T8016EC0C;
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
extern void func_80017B98(void *a0);

void func_8016EC0C(s32 a0, s32 a1)
{
    extern u8 D_80186FB8[];
    T8016EC0C s;
    u16 *p;
    s32 x;
    s32 y;
    s32 v;
    s.r = s.g = s.b = a1;
    s.u18 = D_80186FB8[*(u8 *)(a0 + 3)];
    s.u0C = 0x640;
    s.u0E = 0x1C8;
    s.u14 = 0;
    s.u08 = 0x28;
    s.u0A = 8;
    x = *(u16 *)(a0 + 4);
    s.x = x + 0x10;
    y = *(u16 *)(a0 + 6);
    s.u04 = 0x10;
    s.y = y;
    func_80017B98(&s);
    s.u08 = 8;
    y += 0xA;
    p = (u16 *)(a0 + 8);
    while (*p != 0xFFFF) {
        v = *p;
        switch (v) {
        case 0x1850:
        case 0x1858:
            s.x = x + 4;
            s.y = y - 7;
            break;
        case 0x3872:
            x += 2;
            p++;
            continue;
        default:
            s.x = x;
            s.y = y;
            x += 8;
            break;
        }
        s.u0C = *(u8 *)p + 0x500;
        s.u0E = (*p >> 8) + 0x100;
        p++;
        func_80017B98(&s);
    }
}
