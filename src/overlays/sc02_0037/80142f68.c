/* sc02_0037: func_80142F68 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013F350.c (preprocessed; only the declarations it uses),
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
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 func_8012BF10(s32 a0, s32 a1);
extern s32 func_8012C0EC(s32 a0);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern short D_800B9A02;
extern short D_800B9A02;
extern u16 D_80115116;
extern s32 func_80142DB8(s32 *a0);
extern s32 func_8012C0EC(s32 a0);
extern void func_80142BB4(s32 *a0, s32 a1, s32 a2);
extern void func_80142C9C(s32 *a0);
extern s32 func_8012BF10(s32 a0, s32 a1);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 func_80142DB8(s32 *a0);
extern void func_80142BB4(s32 *a0, s32 a1, s32 a2);
void func_8012AD44(s32 *a0, s16 a1);
void func_80142BB4(s32* param_1, s32 param_2, s32 param_3);
void func_80142C9C(s32 * arg0);
s32 func_80142DB8(s32 *a0);
extern s32 func_80142DB8(s32 *a0);
extern s32 func_8012C0EC(s32 a0);
extern void func_80142BB4(s32 *a0, s32 a1, s32 a2);
extern void func_80142C9C(s32 *a0);
extern s32 func_8012BF10(s32 a0, s32 a1);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_80142F68(s32 *a0) {
    if (func_80142DB8(a0) == 1) {
        func_80142BB4(a0, 1, 3);
        return;
    }
    if (*(s16 *)((u8 *)a0 + 0x100) != 0) {
        if (func_8012C0EC(a0) == 0) {
            return;
        }
        func_80142BB4(a0, 0, 3);
        return;
    }
    func_80142C9C(a0);
    if (func_8012BF10((s32)a0, 0x30) != 0) {
        func_8012AD44(a0, 2);
    }
}
