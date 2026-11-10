/* sc02_0037: func_8017F844 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
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
extern void func_8012A828(s32 a0, void * a1);
extern s32 func_8012B030(u8 *a0);
extern void func_8012C218(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8001C214(int, int);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
void func_8012C218(void *a0);
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
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern s32 func_8012B030(u8 *a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012C218(void*);
extern short D_800B9A02;
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32, void *);
extern void func_8002AC00(s32 arg0);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012C218(void *a0);
extern s32 func_8012B030(u8 *a0);

void func_8017F844(void *a0) {
    extern s32 D_801A9DAC;
    extern s32 D_801B14F0;
    u16 buf[8];
    s32 ent;
    u16 saved;
    u16 v0;
    register u16 v1 __asm__("$3");
    register u16 a3 __asm__("$7");
    func_8002AC00(0xD);
    if (*(u16 *)((s32)a0 + 0x0) != 0) {
        v0 = *(u16 *)((s32)a0 + 0x6);
        buf[0] = v0;
        buf[4] = v0;
        v1 = *(u16 *)((s32)a0 + 0xA);
        v0 = v1 - 8;
        buf[1] = v1;
        buf[5] = v1;
        a3 = *(u16 *)((s32)a0 + 0xE);
        v1 = v1 + 8;
        buf[1] = v0;
        buf[5] = v1;
        buf[2] = a3;
        buf[6] = a3;
        if ((func_8012CEB0((s32)&buf[0], (s32)&buf[4], 0) & 0x1F) == 0) {
            if ((*(s16 *)((s32)a0 + 0x100) & 0x8000) == 0) {
                saved = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12);
                func_8001C214(*(s32 *)((s32)a0 + 0x20), (s32)&D_801A9DAC);
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)&D_801B14F0);
                *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = saved;
                ent = func_8012C658(0x12C, 1, (s32)a0);
                if (ent != 0) {
                    if (*(s16 *)((s32)a0 + 0xA) >= 0x10) {
                        func_8012C218((void *)ent);
                    } else {
                        *(u16 *)(*(s32 *)(ent + 0x20) + 0x12) = saved;
                        func_8012B030((u8 *)ent);
                        if (*(s16 *)((s32)a0 + 0x70) == 5) {
                            s16 t = *(s16 *)((s32)a0 + 0x100);
                            *(s16 *)(ent + 0x70) = 6;
                            *(s16 *)(ent + 0xFE) = 1;
                            *(s16 *)(ent + 0x100) = t;
                            do {
                                func_8012C658(0x12F, 5, ent);
                                *(s16 *)(ent + 0xFE) = *(u16 *)(ent + 0xFE) + 3;
                            } while (*(s16 *)(ent + 0xFE) < 0x10);
                            *(s16 *)(ent + 0xFE) = 0;
                        }
                    }
                }
            }
        }
    }
}
