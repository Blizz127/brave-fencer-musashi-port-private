/* SC02.CD member35: func_8018023C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef double f64;
struct Vec;
struct Vec {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};
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
typedef struct {
        u16 f0;
        u16 f2;
        u16 f4;
        u16 x;
        u16 f8;
        u16 y;
        u16 fC;
        u16 z;
        u8 p10[0x10];
        s32 f20;
        u8 p24[0x34];
        s32 f58;
        u8 p5C[8];
        s32 f64;
        u8 p68[0x10C - 0x68];
    } Ent_8017FD58;
typedef struct { s16 vx, vy, vz, pad; } SV3_8012CC88;
typedef struct { short vx, vy, vz, pad; } Vec;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B6D4(s16 *a0, s16 *a1);
extern void func_8012ADE4(u8 *a0);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8012BC60(struct Vec *a0, struct Vec *a1);
extern s32 func_8012B6D4(s16 *a0, s16 *a1);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern void func_8012ADE4(u8 *a0);

void func_8018023C(s32 a0) {
    extern u8 D_801202A0[];
    Ent_8017FD58 *e;
    s32 i;
    s16 *mover;
    s32 off;
    unsigned int *offp;
    s32 ang;
    s32 v0;
    SV3_8012CC88 sp10;
    SV3_8012CC88 sp18;
    e = (Ent_8017FD58 *)D_801202A0;
    i = 0;
    mover = (s16 *)(a0 + 4);
    offp = (unsigned int *)&off;
    for (; i < 0x60; i++, e++) {
        if (e->f0 == 0x17F && a0 != (s32)e &&
            func_8012BC60((struct Vec *)mover, (struct Vec *)&e->f4) < 0x1000) {
            ang = func_8012B6D4(mover, (s16 *)&e->f4);
            func_8012B0B4(offp, ang, 0x41);
            sp18.vx = e->x;
            sp18.vy = e->y;
            sp18.vz = e->z;
            sp18.vx += off;
            sp18.vz += (off >> 16);
            sp10.vx = *(u16 *)(a0 + 0x3A);
            sp10.vy = *(u16 *)(a0 + 0x3E);
            sp10.vz = *(u16 *)(a0 + 0x42);
            v0 = func_8012CEB0((s32)&sp10, (s32)&sp18, 0);
            if ((v0 & 0x2000) == 0) {
                func_8012ADE4((u8 *)a0);
                return;
            }
            *(s16 *)(a0 + 0x6) = sp18.vx;
            *(s16 *)(a0 + 0xA) = sp18.vy;
            *(s16 *)(a0 + 0xE) = sp18.vz;
            return;
        }
    }
}
