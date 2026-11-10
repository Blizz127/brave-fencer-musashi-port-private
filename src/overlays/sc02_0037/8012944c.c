/* sc02_0037: func_8012944C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern s16 D_80114EE0;
extern s16 D_80114EE0;
extern s32 D_8005128C;
extern s16 D_80114EE0;
extern u8 D_800B9A78;
extern void func_801298F4(void *arg0);
extern void func_801299C8();
void func_801298F4(void *arg0);
void func_801299C8();

void func_8012944C(void) {
    s32 base;
    register short *p __asm__("$17");
    s32 i;
    s32 sh;
    s32 *g = (s32 *)&D_8005128C;
    int v;
    s32 arg;
    if (*g == 0x34420200) {
        *g = 0;
    }
    D_80114EE0 = 1;
    base = (s32)&D_800B9A78;
    i = 0;
    sh = 0x30000;
    p = (short *)(base + 0x1E);
    do {
        v = (u16)p[0xb];
        if (v == 0x7ffe) goto F0;
        if (v < 0x7fff) {
            if (v == 0x7ffd) goto DC;
            goto L504;
        }
        if (v != 0x7fff) goto L504;
        goto L530;
    DC:
        if (i != 0) goto L530;
        func_801299C8(1, 1, base);
        goto L530;
    F0:
        arg = (i << 0x11) >> 0x10;
        func_801299C8(1, arg, base);
        goto L530;
    L504:
        func_801298F4((void *)base);
        arg = sh >> 0x10;
        *p = p[0x12] + p[0xe];
        func_801299C8(1, arg, base);
    L530:
        p += 0x2a;
        sh += 0x10000;
        i += 1;
        base += 0x54;
    } while (i < 2);
}
