/* sc02_0037: func_8015444C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015444C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 aF8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4) __asm__("");
extern s32 aF8014C4AC();
extern s32 aF8014E5B4(s32 a0, void *a1, void *a2) __asm__("");
extern s32 aF8014E5B4(s32 a0, void *a1, void *a2);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
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

void func_8015444C(void* a0v, s32* arg1x, s32* arg2x, s32* arg3x)
{
    typedef struct actor4c_8015444C {
        u8 pad00[0x20];
        struct actor4c_8015444C *unk20;
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
