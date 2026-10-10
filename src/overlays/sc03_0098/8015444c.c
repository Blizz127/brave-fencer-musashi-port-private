/* sc03_0098: func_8015444C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015444C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct actor4c {
    u8 pad00[0x20];
    struct actor4c *unk20;
    u8 pad24[0x44 - 0x24];
    u32 unk44;
    u8 pad48[0xB4 - 0x48];
    s32 *unkB4;
    s16 unkB8;
    s16 unkBA;
    u8 unkBC;
    u8 unkBD;
    u8 padBE[0xDC - 0xBE];
    u8 unkDC;
    u8 padDD[0x1A8 - 0xDD];
    u8 unk1A8;
} Actor4C;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80155440(s32 *a0);
extern s32 func_801549F8(s32 a0, s32 a1, s32 a2);
extern void func_80059A1C(s32, void *);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80155440(s32 *a0);
extern s32 func_801549F8(s32 a0, s32 a1, s32 a2);
extern void func_80154B4C(u8 *a0, s32 a1);
extern s32 func_80155394(s32 *a0);
extern void func_801553A8(s32 *a0);
extern u8 D_80126738;
extern u8 D_80126748;
extern u8 D_80126838;
extern u8 D_80126848;
s32 func_801549F8(s32 param_1, s32 _arg1, s32 _arg2);
void func_80154A74(s32 a0, s32 a1);
void func_80154B4C(u8 *a0, s32 a1);

void func_8015444C(void *a0v, s32 *arg1x, s32 *arg2x, s32 *arg3x) {
    Actor4C *arg0 = a0v;
    s32 *arg1 = arg1x;
    s32 *arg2 = arg2x;
    s32 *arg3 = arg3x;
    Actor4C *p = arg0->unk20;
    u8 t;
    s32 t2;
    u32 op;
    s32 temp;
    s32 nb4;
    s32 nbc;
    s32 w;
    u8 *img;
    if (p != ((void *)0)) {
        t = *(u8 *)&arg0->unkB8;
        if (t != 0) {
            if (*arg1 == 0) {
                arg0->unkB8 = t;
                *arg1 += 1;
            }
            t2 = (u16)arg0->unkB8 - 1;
            arg0->unkB8 = t2;
            if (!(t2 & 0xFF)) {
                op = arg0->unkB4[arg0->unkBC];
                switch (op) {
                case 0:
                    arg0->unkB8 = 0;
                    *arg2 |= 0x8000;
                    arg0->unkBA = 0;
                    arg0->unkBC = 0;
                    arg0->unkBD = 0;
                    break;
                case 1:
                    arg0->unkB8 = 1;
                    *arg2 |= 0x8000;
                    arg0->unkBC = 0;
                    arg0->unkBD = 0;
                    arg0->unkDC = 0;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 2:
                    arg0->unkB8 = 0;
                    arg0->unkBC = arg0->unkBC + 1;
                    *arg2 |= 0x8000;
                    break;
                case 3:
                    temp = arg0->unkB4[arg0->unkBC + 1];
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 2;
                    arg0->unkBA = temp;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 5:
                    nb4 = arg0->unkB4[arg0->unkBC + 1];
                    nbc = arg0->unkB4[arg0->unkBC + 2];
                    arg0->unkB8 = 1;
                    arg0->unkDC = 0;
                    arg0->unkBC = nbc;
                    arg0->unkB4 = (s32 *)nb4;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 6:
                    arg0->unkBC = arg0->unkB4[arg0->unkBC + 1];
                    arg0->unkB8 = 1;
                    arg0->unkDC = ((s32 (*)(s32))func_801549F8)((s32)arg0);
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 7:
                    arg0->unkB8 = 1;
                    *arg2 |= 0x4000;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 8:
                    arg0->unkB8 = 1;
                    *arg2 |= 0x2000;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 9:
                    arg0->unkB8 = 1;
                    *arg2 |= 0x1000;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 10:
                    arg0->unkB8 = 1;
                    *arg2 |= 0x800;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 13:
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 14:
                    if (*arg3 == 0) {
                        func_80154B4C((u8 *)arg0, arg0->unkB4[arg0->unkBC + 1]);
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 2;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 15:
                    if (*arg3 == 0) {
                        func_80154A74((s32)arg0, arg0->unkB4[arg0->unkBC + 1]);
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 2;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 16:
                    if (*arg3 == 0) {
                        func_801553C0((s32)arg0);
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 17:
                    if (*arg3 == 0) {
                        func_80155440((s32 *)arg0);
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 18:
                    if (*arg3 == 0) {
                        func_80155394((s32 *)arg0);
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 19:
                    if (*arg3 == 0) {
                        func_801553A8((s32 *)arg0);
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 20:
                    if (*arg3 == 0) {
                        arg0->unk1A8 ^= 1;
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 21:
                    if (*arg3 == 0) {
                        w = arg0->unkB4[arg0->unkBC + 1];
                        img = &D_80126738;
                        func_80059A1C(w, img);
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 2;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 22:
                    if (*arg3 == 0) {
                        w = arg0->unkB4[arg0->unkBC + 1];
                        img = &D_80126838;
                        func_80059A1C(w, img);
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 2;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 4:
                case 11:
                case 12:
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 2;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 23:
                    if (*arg3 == 0) {
                        p->unk20 = (Actor4C *)&D_80126748;
                    }
                    arg0->unkB8 = (u16)arg0->unkBA;
                    arg0->unkBC++;
                    arg0->unkBD++;
                    arg0->unkDC++;
                    break;
                case 24:
                    if (*arg3 == 0) {
                        p->unk20 = (Actor4C *)&D_80126848;
                    }
                    arg0->unkB8 = (u16)arg0->unkBA;
                    arg0->unkBC++;
                    arg0->unkBD++;
                    arg0->unkDC++;
                    break;
                case 25:
                    if (*arg3 == 0) {
                        arg0->unk44 = arg0->unk44 & 0xFFFDFFFF;
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                case 26:
                    if (*arg3 == 0) {
                        arg0->unk44 = arg0->unk44 | 0x20000;
                    }
                    arg0->unkB8 = 1;
                    arg0->unkBC = arg0->unkBC + 1;
                    arg0->unkBD = arg0->unkBD + 1;
                    func_8015444C(arg0, arg1, arg2, arg3);
                    break;
                default:
                    p->unk20 = (Actor4C *)(op + 0x10);
                    arg0->unkB8 = (u16)arg0->unkBA;
                    arg0->unkBC++;
                    arg0->unkBD++;
                    arg0->unkDC++;
                    break;
                }
            }
            arg0->unkB8 = (u16)arg0->unkB8 | *arg2;
        }
    }
}
