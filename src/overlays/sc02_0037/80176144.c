/* sc02_0037: func_80176144 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef unsigned int uint;
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
typedef struct { s32 g0; s32 pad[2]; } S_AF634;
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
extern u8 D_8011F7A8;
extern s16 D_8011F7BC;
extern s16 D_8011F7BE;
extern s16 D_800B9A02;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern short D_800B9A02;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
s32 func_80178004(uint *param_1, uint param_2, int param_3);

void func_80176144(s32 a0)
{
    extern S_AF634 aAF634[] __asm__("D_800AF634");
    extern S_AF634 aAF638[] __asm__("D_800AF638");
    extern u8 D_8011F7A8;
    extern s16 D_8011F7BC;
    extern s16 D_8011F7BE;
    extern s32 func_80178004();
    u32 *slot;
    u32 *p;
    s16 param_1 = (s16)a0;
    p = (u32 *)(aAF638[param_1].g0 + aAF634[param_1].g0 * 4);
    slot = (u32 *)(param_1 * 4 + (s32)&D_8011F7A8);
    slot[14] = (u32)p;
    __asm__("");
    p = (u32 *)func_80178004((s32)p,
                             (s16)((*(u16 *)&D_8011F7BC) - 0x17),
                             (s16)((*(u16 *)&D_8011F7BE) + 0x65));
    slot[16] = (u32)p - 0x14;
    p += 5;
    aAF634[param_1].g0 += ((s32)p - (s32)slot[14]) >> 2;
}
