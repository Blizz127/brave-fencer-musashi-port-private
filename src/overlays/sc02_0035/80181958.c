/* SC02.CD member35: func_80181958 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
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
typedef struct {
        u16 x, y, z, w;
    } V8_80181958;
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012BCCC(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012BCCC(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012CBA4(s32 a0);
extern void func_8012A828(s32*, s32);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern void func_8012CBA4(s32 a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_8012BDBC(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_8012BDBC(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);

void func_80181958(s32 a0) {
    extern u8 D_8019C480[];
    extern u8 D_801A9188[];
    V8_80181958 pad[2];
    V8_80181958 sp20;
    V8_80181958 sp28;
    s32 t;
    s32 r;
    s32 v;
    func_8012B1B4(a0, (s32)D_8019C480);
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) += func_8012B8E4(a0, 0x10);
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) &= 0xFFF;
    if ((((s32 (*)(s32))func_8012CBA4)(a0) & 0x6000) == 0) {
        *(s32 *)(a0 + 0x4) = *(s32 *)(a0 + 0x38);
        *(s32 *)(a0 + 0x8) = *(s32 *)(a0 + 0x3C);
        *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0x40);
    }
    v = func_8004787C(*(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) & 0xFFF);
    r = 0x30;
    sp20.x = *(u16 *)(a0 + 0x6) - ((v * r) >> 12);
    sp20.y = *(u16 *)(a0 + 0xA) - 0x20;
    v = func_80047948(*(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) & 0xFFF);
    sp20.z = *(u16 *)(a0 + 0xE) - ((v * r) >> 12);
    sp28.x = sp20.x;
    sp28.y = sp20.y + 0x60;
    sp28.z = sp20.z;
    if ((func_80133784(1, &sp20, (s32)&sp28) & 0x6000) == 0) {
        *(s32 *)(a0 + 0x4) = *(s32 *)(a0 + 0x38);
        *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0x40);
    }
    t = func_8012BCCC(a0);
    if (t < 0x2401) {
        if (func_8012BDBC(a0, 0x200) == 1) {
            *(s16 *)(a0 + 0x2) = 0x11;
            ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801A9188);
        }
    }
    if (t > 0x40000) {
        *(s16 *)(a0 + 0x2) = 6;
    }
}
