/* sc02_0037: func_80159C84 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80159C84.c (preprocessed; only the declarations it uses),
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
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 func_8005C49C(void);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147324(s32 arg0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern void func_801483E8(unsigned char *self);
extern s32 func_801488A8(u8 *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern s32 func_8016F1AC(void);
extern s32 func_80149AA8(s32 *a0);
extern s32 func_80149B54(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32 func_80149B54(s32 * arg0);
extern void func_80149BAC(s32 *a0);
extern s32 func_80149CD4(s32 a0);
extern s32 func_80149D9C(s32 a0);
extern void func_80149FA8(void);
extern s32 func_80149FB0(s32 a0);
extern s32 func_8014A738(void *arg0);
extern void func_8014A830(void);
extern void func_8014C010(s32 a0, s32 a1);
extern u16 D_800B99DA;
extern void func_80147324(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80155440(s32 *a0);
extern void func_80154190(u8 *a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154B4C(u8 *a0, s32 a1);
extern int func_80161208();
extern void func_8015E880(s32 *a0);
extern s32 func_80161208();
extern void func_80147A84(int);
extern void func_80154A74(int, int);
extern int func_8005C49C(void);
extern s32 func_80172590(u8 *a0);
extern s32 func_80149FB0(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_80149D9C(s32 a0);
extern void func_80149FA8(void);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern int func_80161BE0(void *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern s32 func_801619A4(s32 *a0);
extern s32 func_80149AA8(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32 func_80149B54(s32 *a0);
extern s32 func_8014A738(void*);
extern void func_8014A830(void);
extern void func_80149BAC(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 a0);
extern s32 func_80149A64(s32 *a0);
extern void func_800CCCC0(u8 *a0);
extern s32 func_80149CD4(s32 a0);
extern void func_8015E880(s32 *a0);
extern s32 func_801488A8(u8 *a0);
extern void func_8015A230(s32 *a0);
extern void func_80154B4C(u8 *a0, s32 a1);
extern s32 func_8016F1AC(void);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80154190(u8 *a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80155440(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_80161208();
extern void func_801483E8(unsigned char*);
extern s32 func_80172590(u8 *a0);
void func_8015A230(s32 *a0);

void func_80159C84(u8 *p) {
    extern unsigned char D_8018620C;
    extern void (*D_801862A8[])(void *);
    extern s32 D_800D5F04;
    extern s32 D_800D5F14;
    extern s32 D_800D5F34;
    extern s32 D_800D5F44;
    extern s32 D_800D49F4;
    s32 t;
    if (((s32 (*)(void))func_80149D9C)() != 0) {
        D_801862A8[*(u16 *)p](p);
        ((void (*)(u8 *))func_80149FA8)(p);
        return;
    }
    func_80149FB0((s32)p);
    if (func_80161B18(p) != 0) {
        return;
    }
    if (func_80161B84(p) != 0) {
        return;
    }
    if (func_80161BE0(p) != 0) {
        return;
    }
    if (func_801496D4(p) != 0) {
        D_801862A8[*(u16 *)p](p);
        ((void (*)(u8 *))func_80149704)(p);
        return;
    }
    switch (func_801619A4((s32 *)p)) {
    case 0:
    case 1:
    case 2:
    case 6:
        if (func_80149AA8((s32 *)p) != 0) {
            D_801862A8[*(u16 *)p](p);
            func_80149AD4((s32 *)p);
            return;
        }
        if (func_80149B54((s32 *)p) != 0) {
            D_801862A8[*(u16 *)p](p);
            if (((s32 (*)(u8 *))func_8014A738)(p) != 0) {
                ((void (*)(u8 *))func_8014A830)(p);
                return;
            }
            func_80149BAC((s32 *)p);
            return;
        }
        break;
    case 3:
        func_801498E0((s32 *)p);
        break;
    case 4:
        func_80149954((s32)p);
        break;
    case 5:
        if (func_80149A64((s32 *)p) != 0) {
            D_801862A8[*(u16 *)p](p);
            func_800CCCC0(p);
            return;
        }
        break;
    }
    if (func_80149CD4((s32)p) != 0) {
        D_801862A8[*(u16 *)p](p);
        func_8015E880((s32 *)p);
        return;
    }
    if (func_801488A8(p) != 0) {
        D_801862A8[*(u16 *)p](p);
        func_8015A230((s32 *)p);
        return;
    }
    if ((*(u32 *)(p + 0x44) & 0x200) == 0 && *(u16 *)(p + 0xD4) == 0x8000) {
        if (*(s32 *)(p + 0x234) >= 3) {
            t = (s32)&D_800D5F44;
            if (*(s32 *)(p + 0xD0) == t) {
                func_80154B4C(p, (s32)&D_800D5F34);
                goto after_b4c;
            }
        } else {
            t = (s32)&D_800D5F14;
            if (*(s32 *)(p + 0xD0) == t) {
                func_80154B4C(p, (s32)&D_800D5F04);
                goto after_b4c;
            }
        }
        if ((func_8005C49C() & 0xF) == 0) {
            func_80154B4C(p, t);
        }
    }
after_b4c:
    if (*(u16 *)(p + 0xB8) & 0x8000) {
        if ((*(u32 *)(p + 0x44) & 0x200) == 0) {
            if (func_8016F1AC() != 0) {
                *(s32 *)(p + 0x234) = 0;
                *(s32 *)(p + 0x238) = 0;
            }
            switch (*(s32 *)(p + 0x234)) {
            case 0:
                if ((*(s32 *)(p + 0x238))++ >= 4) {
                    *(s32 *)(p + 0x238) = 0;
                    *(s32 *)(p + 0x234) = *(s32 *)(p + 0x234) + 1;
                    func_80154150((s32)p, 1);
                    break;
                }
                func_80146DB8((s32 *)p, (s32 *)&D_8018620C);
                func_80154190(p, 0);
                break;
            case 1:
                *(s32 *)(p + 0x238) = 0;
                *(s32 *)(p + 0x234) = *(s32 *)(p + 0x234) + 1;
                func_80154150((s32)p, 0);
                break;
            case 2:
                if ((*(s32 *)(p + 0x238))++ >= 2) {
                    if ((*(u32 *)(p + 0x44) & 4) != 0) {
                        *(s32 *)(p + 0x234) = 0;
                        *(s32 *)(p + 0x238) = 0;
                        func_80154150((s32)p, 0);
                        break;
                    }
                    *(s32 *)(p + 0x238) = 0;
                    *(s32 *)(p + 0x234) = *(s32 *)(p + 0x234) + 1;
                    func_80154150((s32)p, 2);
                    break;
                }
                func_80154190(p, 0);
                break;
            case 3:
                func_80147324(0x445);
                *(s32 *)(p + 0x234) = *(s32 *)(p + 0x234) + 1;
                func_80155440((s32 *)p);
                func_80154150((s32)p, 3);
                func_80154A74((s32)p, 0x13);
                break;
            case 4:
                break;
            default:
                break;
            }
        } else {
            func_80146DB8((s32 *)p, (s32 *)&D_8018620C);
            func_80154150((s32)p, 5);
            func_80154A74((s32)p, 0x1C);
        }
    }
    if (*(s32 *)(p + 0xB4) == (s32)&D_800D49F4) {
        func_80147A84((s32)p);
        func_801473EC((s32 *)p);
        if ((D_800B99DA & 3) == 0) {
            func_8014C010((s32)p, 1);
        }
    }
    if (((s32 (*)(s32))func_80161208)((s32)p) == 0) {
        ((void (*)(u8 *))func_801483E8)(p);
        func_80172590(p);
    }
}
