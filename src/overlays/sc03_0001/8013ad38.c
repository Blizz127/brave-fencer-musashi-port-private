/* sc03_0001: func_8013AD38 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct vec;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { s16 x, y; } Pair_8013AD38;
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
extern void func_8012931C(struct vec *a0);
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
extern short D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern short D_800B9A02;
extern s16 D_800D45F4[];
extern u8 D_8018DBDC[];
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro mvmva sf, mx, v, cv, lm\n"
    "    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

void func_8013AD38(void *flag, s32 a1, void *out2, void *out3)
{
    extern s16 D_800D466C[];
    extern u8 D_8018DC18[];
    u8 *tbl;
    s16 vec[4];
    s32 res[3];
    s32 i;
    tbl = D_8018DC18;
    if (((s16)a1) < 0xC00) {
        tbl = D_8018DBDC;
    }
    for (i = 0; i < 30; i++) {
        vec[0] = D_800D45F4[2 * i] + (((D_800D466C[2 * i] - D_800D45F4[2 * i]) * ((s16)a1)) >> 12);
        vec[1] = D_800D45F4[2 * i + 1] + (((D_800D466C[2 * i + 1] - D_800D45F4[2 * i + 1]) * ((s16)a1)) >> 12);
        __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"( vec ) );
        __asm__ volatile ("nop;nop;mvmva 1, 0, 0, 0, 0");
        __asm__ volatile ( "swc2 $25, 0( %0 );" "swc2 $26, 4( %0 );" "swc2 $27, 8( %0 )" : : "r"( res ) : "memory" );
        ((Pair_8013AD38 *)out2)[i].x = res[0];
        ((Pair_8013AD38 *)out2)[i].y = res[1];
        if (((s16 *)flag)[0] < 0) ((s8 *)out3)[2 * i] = -tbl[2 * i]; else ((s8 *)out3)[2 * i] = tbl[2 * i];
        if (((s16 *)flag)[1] < 0) ((s8 *)out3)[2 * i + 1] = -tbl[2 * i + 1]; else ((s8 *)out3)[2 * i + 1] = tbl[2 * i + 1];
    }
    ((Pair_8013AD38 *)out2)[i] = ((Pair_8013AD38 *)out2)[0];
    if (((s16 *)flag)[0] < 0) ((s8 *)out3)[2 * i] = -tbl[0]; else ((s8 *)out3)[2 * i] = tbl[0];
    if (((s16 *)flag)[1] < 0) ((s8 *)out3)[2 * i + 1] = -tbl[1]; else ((s8 *)out3)[2 * i + 1] = tbl[1];
}
