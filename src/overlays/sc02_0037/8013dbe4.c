/* sc02_0037: func_8013DBE4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013C98C.c (preprocessed; only the declarations it uses),
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
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_8013DD68(void);
extern void func_8013DD68(void);
void func_8013DD68();

void func_8013DBE4(int param_1)
{
    extern void *D_801C84A0;
    extern s16 *D_801C84A4;
    extern s32 D_801C84B4;
    extern s32 D_801C84D4;
    extern s32 D_801C84D8;
    extern s32 D_801C84DC;
    int *p;
    int x, y, z;
    int flag;
    if (D_801C84A4 != 0) {
        D_801C84B4 = 0;
        p = (int *)(param_1 * 12 + (int)D_801C84A0);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801C84D4 != x) {
            flag = 1;
            if (D_801C84D4 < x) {
                if (x - D_801C84D4 < 5) {
                    D_801C84D4 = x;
                } else {
                    D_801C84D4 = D_801C84D4 + 4;
                }
            } else {
                if (D_801C84D4 - x < 5) {
                    D_801C84D4 = x;
                } else {
                    D_801C84D4 = D_801C84D4 - 4;
                }
            }
        }
        if (D_801C84D8 != y) {
            flag = 1;
            if (D_801C84D8 < y) {
                if (y - D_801C84D8 < 5) {
                    D_801C84D8 = y;
                } else {
                    D_801C84D8 = D_801C84D8 + 4;
                }
            } else {
                if (D_801C84D8 - y < 5) {
                    D_801C84D8 = y;
                } else {
                    D_801C84D8 = D_801C84D8 - 4;
                }
            }
        }
        if (D_801C84DC != z) {
            flag = 1;
            if (D_801C84DC < z) {
                if (z - D_801C84DC < 5) {
                    D_801C84DC = z;
                } else {
                    D_801C84DC = D_801C84DC + 4;
                }
            } else {
                if (D_801C84DC - z < 5) {
                    D_801C84DC = z;
                } else {
                    D_801C84DC = D_801C84DC - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801C84B4 = flag;
    }
}
