/* sc01_0077: func_801387B8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
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
void func_80138948(void *a0);
s32 func_80138DE0(u8 *arg0, u8 arg1, s32 arg2);
s32 func_80139220(s32 a0);
void func_80139A8C(s32 a0);
void func_80139B18(s32 a0);

void func_801387B8(s32 arg0) {
    extern s32 func_80138DE0(u8 *arg0, u8 arg1, s32 arg2);
    extern s32 func_80139220(s32 a0);
    extern void func_80138948(void *a0);
    extern void func_80139A8C(s32 a0);
    extern void func_80139B18(s32 a0);
    extern s32 D_80127530[];
    u16 *p;
    s32 base;
    s32 cont;
    u8 cmd;
    s32 sub;
    s32 pc;
    for (;;) {
        cont = 0;
        if (*(s32 *)(arg0 + 8) & 0x400) {
            base = D_80127530[*(u16 *)(arg0 + 0x4A)];
            p = (u16 *)(arg0 + 0x44);
        } else {
            p = (u16 *)(arg0 + 0x10);
            base = *(s32 *)(arg0 + 0);
        }
        pc = *p;
        cmd = *(u8 *)(base + pc);
        sub = *(u8 *)(base + pc + 1);
        if (cmd >= 0x20) {
            cont = func_80138DE0(arg0, cmd, sub);
            if (!(*(s32 *)(arg0 + 8) & 0x80220)) {
                cont = 0;
            }
        } else {
            if (cmd != 0) {
                switch (cmd) {
                case 10:
                    func_80139220(arg0);
                    *p += 1;
                    goto loop_end;
                case 1:
                    cont = 1;
                    *(u8 *)(arg0 + 0x23) = sub;
                    *p += 2;
                    goto loop_end;
                case 7:
                    if (!(*(s32 *)(arg0 + 8) & 0x20000)) {
                        *(s32 *)(arg0 + 8) &= ~0x20;
                    }
                    break;
                case 23:
                    *(s32 *)(arg0 + 8) |= 2;
                default:
                    cont = 1;
                    *p += 1;
                    goto loop_end;
                }
            }
            func_80138948((void *)arg0);
        }
    loop_end:
        if (cont == 0) {
            func_80139A8C(arg0);
            func_80139B18(arg0);
            return;
        }
    }
}
