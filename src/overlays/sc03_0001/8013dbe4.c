/* sc03_0001: func_8013DBE4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern void *D_801ED438;
extern void func_8013DD68(void);
extern s32 D_801ED44C;
extern void *D_801ED438;
extern s32 D_801ED44C;
extern void *D_801ED438;
extern s16 *D_801ED43C;
extern s32 D_801ED44C;
extern s32 D_801ED46C;
extern s32 D_801ED470;
extern s32 D_801ED474;
extern void func_8013DD68(void);
void func_8013DD68();

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;
    if (D_801ED43C != 0) {
        D_801ED44C = 0;
        p = (int *)(param_1 * 12 + (int)D_801ED438);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801ED46C != x) {
            flag = 1;
            if (D_801ED46C < x) {
                if (x - D_801ED46C < 5) {
                    D_801ED46C = x;
                } else {
                    D_801ED46C = D_801ED46C + 4;
                }
            } else {
                if (D_801ED46C - x < 5) {
                    D_801ED46C = x;
                } else {
                    D_801ED46C = D_801ED46C - 4;
                }
            }
        }
        if (D_801ED470 != y) {
            flag = 1;
            if (D_801ED470 < y) {
                if (y - D_801ED470 < 5) {
                    D_801ED470 = y;
                } else {
                    D_801ED470 = D_801ED470 + 4;
                }
            } else {
                if (D_801ED470 - y < 5) {
                    D_801ED470 = y;
                } else {
                    D_801ED470 = D_801ED470 - 4;
                }
            }
        }
        if (D_801ED474 != z) {
            flag = 1;
            if (D_801ED474 < z) {
                if (z - D_801ED474 < 5) {
                    D_801ED474 = z;
                } else {
                    D_801ED474 = D_801ED474 + 4;
                }
            } else {
                if (D_801ED474 - z < 5) {
                    D_801ED474 = z;
                } else {
                    D_801ED474 = D_801ED474 - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801ED44C = flag;
    }
}
