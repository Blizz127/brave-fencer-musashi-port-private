/* SC02.CD member35: func_801814B0 from Druthulu/BFM-decomp
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
    } V8_801814B0;
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
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
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8004787C(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8004787C(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8004787C(s32 a0);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_80047948(s32 a0);
extern void func_8012CBA4(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8005C49C(void);
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
extern s32 func_8005C49C(void);

void func_801814B0(s32 a0) {
    extern u8 D_801A94C8[];
    extern u8 D_801A8E48[];
    extern u8 D_801A96D0[];
    s32 sp10[4];
    V8_801814B0 pad[2];
    V8_801814B0 sp30;
    V8_801814B0 sp38;
    s32 t;
    s32 r;
    s32 v;
    *(s16 *)(a0 + 0xFC) = *(u16 *)(a0 + 0xFC) + 1;
    sp10[0] = 0;
    sp10[1] = 0;
    sp10[2] = (*(s16 *)(a0 + 0xFC) * -0x20000) / 0x24;
    func_8012B1B4(a0, (s32)sp10);
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) += func_8012B8E4(a0, 0x10);
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) &= 0xFFF;
    if ((((s32 (*)(s32))func_8012CBA4)(a0) & 0x6000) == 0) {
        *(s32 *)(a0 + 0x4) = *(s32 *)(a0 + 0x38);
        *(s32 *)(a0 + 0x8) = *(s32 *)(a0 + 0x3C);
        *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0x40);
    }
    v = func_8004787C(*(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) & 0xFFF);
    r = 0x30;
    sp30.x = *(u16 *)(a0 + 0x6) - ((v * r) >> 12);
    sp30.y = *(u16 *)(a0 + 0xA) - 0x20;
    v = func_80047948(*(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) & 0xFFF);
    sp30.z = *(u16 *)(a0 + 0xE) - ((v * r) >> 12);
    sp38.x = sp30.x;
    sp38.y = sp30.y + 0x60;
    sp38.z = sp30.z;
    if ((func_80133784(1, &sp30, (s32)&sp38) & 0x6000) == 0) {
        *(s32 *)(a0 + 0x4) = *(s32 *)(a0 + 0x38);
        *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0x40);
    }
    t = func_8012BCCC(a0);
    if (t < 0x1001) {
        if (func_8012BDBC(a0, 0x200) == 1) {
            s32 s;
            if ((func_8005C49C() & 3) == 0) {
                ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801A94C8);
                s = 0x5;
            } else {
                ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801A8E48);
                s = 0xF;
            }
            *(s16 *)(a0 + 0x2) = s;
        }
    }
    if (t > 0x40000) {
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801A96D0);
        *(s16 *)(a0 + 0x2) = 1;
        *(s16 *)(a0 + 0xFC) = 0;
        *(s16 *)(a0 + 0xFE) = 1;
    }
    if (*(s16 *)(a0 + 0xFC) == 0x24) {
        *(s16 *)(a0 + 0xFC) = 0;
    }
}
