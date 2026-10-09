/* SC02.CD member35: func_8017FB1C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
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
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B23C(void *a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B23C(void *a0);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012B23C(void *a0);
extern s32 func_801803F8(void *a0, s32 a1, s32 a2, s32 a3);
s32 func_801803F8(void *a0, s32 a1, s32 a2, s32 a3);

void func_8017FB1C(s32 a0) {
    s32 ent;
    s32 i;
    s32 angle;
    s32 base;
    ent = a0;
    i = 0;
    base = -0x40000;
    angle = ((*(u16 *)(ent + 0x70) & 0xF) | -0x8000) << 16;
    while (i < 4) {
        func_801803F8((void *)(ent + 0x7C),
                      *(s16 *)(*(s32 *)(ent + 0x20) + 0x12),
                      base - func_8005C49C() % 4 * 0x10000,
                      angle >> 16);
        i++;
    }
    *(s32 *)(ent + 0xEC) = 0x40000;
    func_8012B23C((void *)ent);
    func_8012B178(ent, *(s32 *)(ent + 0xEC));
    *(s32 *)(ent + 0x1C) = 0x10;
    *(s16 *)(ent + 0x34) = 0;
}
