/* sc02_0037: func_8017F9C8 from Druthulu/BFM-decomp
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
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012B23C(s32 a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 func_8005C49C(void);
extern s32 func_80143970(s32 a0);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
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
extern void func_8012CAE4(void *a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32 a0, void *a1);
extern int func_8005C49C(void);
extern short D_800B9A02;
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern s32 func_8012C354(s32, s32);
extern void func_8012A828(s32, void *);
extern void func_8012B2CC(s32);
extern void func_8012A828(s32, void*);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012CAE4(void *a0);
extern s32 func_80143970(s32);
extern void func_8012A828(s32, void*);
extern void func_8012B23C(s32);
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8005C49C(void);

void func_8017F9C8(void *a0) {
    extern u8 D_801A3A18[];
    extern u8 D_801B03F8[];
    extern u8 D_801AFCC0[];
    extern char D_801B1370[];
    extern u8 D_801B11F0[];
    extern s32 D_801A3B50;
    extern s32 D_801A3BF0;
    extern s32 D_801A3C38;
    s16 state = *(s16 *)((s32)a0 + 0x70);
    if (func_8012C354((s32)a0, (s32)(D_801A3A18 + state * 0x34)) == 0) {
        func_8012CAE4((void *)a0);
    } else {
        s16 state2;
        u16 saved;
        *(u8 *)((s32)a0 + 0xC0) = 1;
        *(s32 *)((s32)a0 + 0xB4) = -0x401;
        ((void (*)(void *))func_80143970)((void *)a0);
        state2 = *(s16 *)((s32)a0 + 0x70);
        switch (state2) {
            case 0:
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801B03F8);
                *(s16 *)((s32)a0 + 0x2) = 1;
                ((void (*)(void *))func_8012B23C)((void *)a0);
                saved = *(u16 *)((s32)a0 + 0xFC);
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_801A3B50;
                *(s16 *)((s32)a0 + 0xFC) = 0;
                *(u16 *)((s32)a0 + 0x100) = saved;
                break;
            case 2:
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801AFCC0);
                saved = *(u16 *)((s32)a0 + 0xFC);
                *(s16 *)((s32)a0 + 0x2) = 9;
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_801A3BF0;
                *(u16 *)((s32)a0 + 0x100) = saved;
                break;
            case 1:
            case 3:
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)&D_801B1370);
                *(s16 *)((s32)a0 + 0x2) = 6;
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_801A3C38;
                break;
            case 4:
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801B03F8);
                *(s16 *)((s32)a0 + 0x2) = 0xD;
                ((void (*)(void *))func_8012B23C)((void *)a0);
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_801A3B50;
                *(s16 *)((s32)a0 + 0xFC) = 0x1E;
                break;
            case 5:
                if (*(s16 *)((s32)a0 + 0xFC) != 0) {
                    ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801B11F0);
                    *(s16 *)((s32)a0 + 0x2) = 0xE;
                    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = func_8005C49C() & 0xFFF;
                } else {
                    ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801B03F8);
                    *(s16 *)((s32)a0 + 0x2) = 1;
                }
                ((void (*)(void *))func_8012B23C)((void *)a0);
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_801A3B50;
                *(s16 *)((s32)a0 + 0xFE) = 1;
                do {
                    func_8012C658(0x12F, 5, (s32)a0);
                    *(s16 *)((s32)a0 + 0xFE) = *(u16 *)((s32)a0 + 0xFE) + 1;
                } while (*(s16 *)((s32)a0 + 0xFE) < 6);
                *(s16 *)((s32)a0 + 0xFE) = 0;
                break;
            }
        func_8012B2CC((s32)a0);
    }
}
