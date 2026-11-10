/* sc02_0037: func_801827A8 from Druthulu/BFM-decomp
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
extern void func_8012C218(void *a0);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void *memcpy(void *, const void *, u32);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
void func_8012C218(void *a0);
extern s32 func_8005C49C(void);
extern s32 func_80143B6C(s32 arg0, s32 arg1);
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
extern int func_8005C49C(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_8004945C(s32, s32, void*);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012C218(void*);
extern int func_8005C49C(void);
extern short D_800B9A02;
extern void func_8012C218(void *a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012C218(void *a0);
extern s32 func_8005C49C(void);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern s32 func_8005C49C(void);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern s32 func_80143B6C(s32 a0, s32 a1);

void func_801827A8(void *a0)
{
    u16 sv0[4];
    u16 sv1[4];
    s32 flag[4];
    s32 cnt;
    s32 tmp;
    s32 m;
    if (*(s16 *)((s32)a0 + 0xFE) == *(s16 *)(*(s32 *)((s32)a0 + 0x64) + 0x36)) {
        if ((*(u16 *)(*(s32 *)((s32)a0 + 0x64) + 0x100) & 0x4000) == 0) {
            goto low;
        }
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) =
            *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) - 0x200;
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) =
            *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) - 0x200;
        if (*(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) >= 0x200) {
            goto tail;
        }
        func_80143B6C((s32)a0, 0);
    }
    func_8012C218(a0);
    return;
low:
    cnt = *(u16 *)((s32)a0 + 0x100) - 1;
    *(s16 *)((s32)a0 + 0x100) = cnt;
    if ((s16)cnt < 9) {
        *(s16 *)((s32)a0 + 0x100) = 0x18;
        if (*(s16 *)(*(s32 *)((s32)a0 + 0x64) + 0x70) == 5) {
            *(s16 *)((s32)a0 + 0x12) = func_8005C49C() % 56 - 0x1C;
            *(s16 *)((s32)a0 + 0x16) = func_8005C49C() % 96 - 0x60;
            *(s16 *)((s32)a0 + 0x1A) = func_8005C49C() % 56 - 0x2C;
        } else if (*(s16 *)(*(s32 *)((s32)a0 + 0x64) + 0x70) == 6) {
            *(s16 *)((s32)a0 + 0x12) = func_8005C49C() % 56 - 0x1C;
            *(s16 *)((s32)a0 + 0x16) = func_8005C49C() % 32 - 0x20;
            *(s16 *)((s32)a0 + 0x1A) = func_8005C49C() % 128 - 0x60;
        }
    }
    tmp = *(s16 *)((s32)a0 + 0x100);
    if (tmp < 0x10) {
        s32 g1;
        g1 = *(s32 *)((s32)a0 + 0x20);
        *(s16 *)(g1 + 0x1A) = tmp * 0x300;
        *(s16 *)(g1 + 0x18) = tmp * 0x300;
    } else {
        s32 g2;
        g2 = *(s32 *)((s32)a0 + 0x20);
        *(s16 *)(g2 + 0x1A) = (0x20 - tmp) * 0x300;
        *(s16 *)(g2 + 0x18) = (0x20 - tmp) * 0x300;
    }
tail:
    {
        s32 msk;
        msk = 0x80000000;
        if (*(s32 *)(*(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0x20) + 0x4) < 0) {
            *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x4) |= msk;
        } else {
            *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x4) &= 0x7FFFFFFF;
        }
    }
    *(s32 *)((s32)a0 + 0x4) = *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0x4);
    *(s32 *)((s32)a0 + 0x8) = *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0x8);
    *(s32 *)((s32)a0 + 0xC) = *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0xC);
    sv0[0] = *(u16 *)((s32)a0 + 0x12);
    sv0[1] = *(u16 *)((s32)a0 + 0x16);
    sv0[2] = *(u16 *)((s32)a0 + 0x1A);
    m = *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0x20) + 0x34;
    __asm__ volatile ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"( m ) : "$12", "$13", "$14" );
    __asm__ volatile ( "lw $12, 20( %0 );" "lw $13, 24( %0 );" "ctc2 $12, $5;" "lw $14, 28( %0 );" "ctc2 $13, $6;" "ctc2 $14, $7" : : "r"( m ) : "$12", "$13", "$14" );
    func_8004945C(sv0, sv1, flag);
    *(s16 *)((s32)a0 + 0x6) = sv1[0];
    *(s16 *)((s32)a0 + 0xA) = sv1[1];
    *(s16 *)((s32)a0 + 0xE) = sv1[2];
}
