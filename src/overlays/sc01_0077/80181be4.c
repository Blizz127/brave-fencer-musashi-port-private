/* sc01_0077: func_80181BE4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80181BE4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012C51C(void *a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_8012B8E4(s32 arg0, s32 arg1);
extern char D_801AFFC0[];
extern s32 D_801B0D50;
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C51C(void *a0, s32 a1);
extern void func_8012B2CC(s32 a0);
extern void func_80184ED8(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BCCC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern u8 D_8018AAD4;
extern u8 D_8018AA6C[];
extern char D_801AFD28[];
extern char D_801B01E0[];
extern u8 D_801B0E48[];
extern s32 D_801B0D50;
extern char D_801AFFC0[];
struct PrimBE4 { s16 f0, f2, f4, f6, f8, fA, fC, fE; s32 f10; };

void func_80181BE4(s32 p)
{
    s32 t;
    s32 c;
    switch (*(u16 *)(p + 0x34)) {
    case 0:
        if (*(s32 *)(p + 0x1C) == 7) {
            s32 base = (s32)&D_8018AAD4;
            func_8012D5E4(p, base, base + 8, 0xB);
        }
        break;
    case 2:
        if (*(s32 *)(p + 0x1C) == 10) {
            s32 base = (s32)&D_8018AAD4;
            func_8012D5E4(p, base, base + 8, 0xB);
        }
        break;
    case 3: {
        s32 s1c;
        if (*(s32 *)(p + 0x1C) >= 0x19) {
            s32 r = func_8012B8E4(p, 4);
            s32 o = *(s32 *)(p + 0x20);
            *(u16 *)(o + 0x12) = *(u16 *)(o + 0x12) + r;
        }
        s1c = *(s32 *)(p + 0x1C);
        if (s1c == 0xC) {
            struct PrimBE4 sp;
            s16 buf[4];
            s32 tv0;
            func_8012F214(p, (s32)D_8018AA6C, (s32)buf);
            sp.f6 = 0x20;
            sp.f8 = 2;
            sp.fA = 0;
            sp.f10 = 0;
            sp.fE = 0;
            sp.f0 = buf[0];
            sp.f2 = buf[1];
            sp.f4 = buf[2];
            sp.fC = *(u16 *)(*(s32 *)(p + 0x20) + 0x12);
            tv0 = func_8012C51C(&sp, p);
            if (tv0 != 0) {
                *(u16 *)(*(s32 *)(tv0 + 0x20) + 0x12) = *(u16 *)(*(s32 *)(p + 0x20) + 0x12);
                func_8012B2CC(tv0);
            }
        } else if (s1c == 0xF) {
            func_80184ED8(p, (s32)D_8018AA6C);
        }
        break;
    }
    }
    if (func_8012BEE8(p) == 0) {
        return;
    }
    switch (*(u16 *)(p + 0x34)) {
    case 0:
        t = ((s32)(*(u16 *)(p + 0x70) << 16)) >> 24;
        if (t == 0 || (u32)(t - 3) < 2) {
            if (func_8012BCCC(p) < 0x4001) {
                *(s16 *)(p + 2) = 2;
                *(u16 *)(p + 0x34) = 1;
                func_8012A828(p, D_801AFD28);
                *(s32 *)(p + 0x1C) = 0xA;
                return;
            }
        }
        goto reset;
    case 1:
        *(s16 *)(p + 2) = 2;
        *(u16 *)(p + 0x34) = 2;
        func_8012A828(p, D_801B01E0);
        *(s32 *)(p + 0x1C) = 0x18;
        return;
    case 3:
        c = *(u8 *)(p + 0x102) + 1;
        *(u8 *)(p + 0x102) = c;
        if ((u32)(c & 0xFF) >= 3) {
            *(u8 *)(p + 0x102) = 0;
            *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) + 1;
            func_8012A828(p, D_801B0E48);
        } else {
            *(s16 *)(p + 2) = 2;
            *(u16 *)(p + 0x34) = 3;
            func_8012A828(p, (void *)&D_801B0D50);
        }
        *(s32 *)(p + 0x1C) = 0x1E;
        return;
    case 4:
        if (func_8012BEE8(p) == 0) {
            goto reset;
        }
        if (func_8012BCCC(p) > 0x40000) {
            goto reset;
        }
        *(s16 *)(p + 2) = 2;
        *(u16 *)(p + 0x34) = 3;
        func_8012A828(p, (void *)&D_801B0D50);
        *(s32 *)(p + 0x1C) = 0x1E;
    case 2:
    default:
    reset:
        *(u16 *)(p + 0x5C) = 0xAA10;
        *(s16 *)(p + 2) = 1;
        *(u16 *)(p + 0x34) = 2;
        *(s16 *)(p + 0x5E) = 0;
        *(s32 *)(p + 0x1C) = 0x1E;
        func_8012A828(p, D_801AFFC0);
        *(s16 *)(p + 0xFC) = 0;
        return;
    }
}
