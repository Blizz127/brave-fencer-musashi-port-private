/* sc02_0037: func_8013AB54 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
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
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *, const void *, u32);
extern void *memcpy(void *, const void *, u32);
extern void func_8013AD38(void *a0, s32 a1, void *a2, void *a3);
extern void func_8013AF20();
extern short D_800B9A02;
extern void func_8013AD38(void *a0, s32 a1, void *a2, void *a3);
extern void func_8013B274(s32 a0, s32 a1, void *a2);
extern void func_8013AF20();
extern s32 D_800A5E60;
void func_8013AD38(void *flag, s32 a1, void *out2, void *out3);
void func_8013AF20(u32 *param_1, u16 *param_2, u16 *param_3, u8 *param_4);
void func_8013B274(s32 a0, s32 a1, void *a2);

s32 func_8013AB54(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 buf[0xE4];
    s32 neg;
    s32 a, b;
    s32 t4, t6;
    t4 = *(s16 *)(a2 + 4) * 12;
    *(s16 *)(buf + 0xE0) = t4 + 0x10;
    neg = a3 & 0x8000;
    t6 = *(s16 *)(a2 + 6) * 12 + (*(s16 *)(a2 + 6) - 1) * 2;
    *(s16 *)(buf + 0xE2) = t6 + 8;
    if (neg == 0) {
        *(s16 *)(buf + 0xE0) = t4 + 0x38;
        *(s16 *)(buf + 0xE2) = t6 + 0x10;
    }
    a = ((s32)*(s16 *)(buf + 0xE0) << 12) / 154;
    b = ((s32)*(s16 *)(buf + 0xE2) << 12) / 42;
    *(s16 *)(buf + 0xE0) = a;
    *(s16 *)(buf + 0xE2) = b;
    if (neg != 0) {
        *(s16 *)(buf + 0xE0) = -a;
    }
    *(s16 *)(buf + 0xC8) = b;
    *(s16 *)(buf + 0xC2) = 0;
    *(s16 *)(buf + 0xC4) = 0;
    *(s16 *)(buf + 0xC6) = 0;
    *(s16 *)(buf + 0xCA) = 0;
    *(s16 *)(buf + 0xCC) = 0;
    *(s16 *)(buf + 0xCE) = 0;
    *(s16 *)(buf + 0xD0) = 0x1000;
    *(s16 *)(buf + 0xC0) = *(u16 *)(buf + 0xE0);
    *(s32 *)(buf + 0xD4) = *(s16 *)(a2 + 0);
    *(s32 *)(buf + 0xD8) = *(s16 *)(a2 + 2);
    *(s32 *)(buf + 0xDC) = 0;
    {
        s32 *p = (s32 *)(buf + 0xC0);
        __asm__ __volatile__(
            "lw $12, 0(%0)\n"
            "lw $13, 4(%0)\n"
            "ctc2 $12, $0\n"
            "ctc2 $13, $1\n"
            "lw $12, 8(%0)\n"
            "lw $13, 12(%0)\n"
            "lw $14, 16(%0)\n"
            "ctc2 $12, $2\n"
            "ctc2 $13, $3\n"
            "ctc2 $14, $4\n"
            "lw $12, 20(%0)\n"
            "lw $13, 24(%0)\n"
            "ctc2 $12, $5\n"
            "lw $14, 28(%0)\n"
            "ctc2 $13, $6\n"
            "ctc2 $14, $7\n"
            : : "r"(p) : "$12", "$13", "$14", "memory");
    }
    func_8013AD38(buf + 0xE0, 0, buf + 0x00, buf + 0x80);
    D_800A5E60 = a0;
    if (a3 != 0) {
        func_8013B274(a1, 0x80, buf + 0xE0);
    }
    func_8013AF20(a1, a2, buf + 0x00, buf + 0x80);
    return D_800A5E60;
}
