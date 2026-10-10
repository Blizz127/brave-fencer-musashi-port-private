/* sc01_0077: func_8018308C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182E7C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 D_80126B58;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012B2CC(int);
extern void func_8012B23C(int);
extern void func_8012B14C(s32 a0, s32 a1);
extern unsigned char D_801B09D0;
extern void func_8012B23C(s32 a0);
extern s32 func_8012CBA4(s32 a0);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern s32 func_8012CBA4(s32);
extern void func_8012B2CC(int a0);
extern void func_8012B23C(int a0);
extern void func_8012A828(int a0, void *a1);
extern void func_80182968(void);
extern unsigned char D_8018AA8C[];
extern unsigned char D_801AFF18[];
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32);
extern void func_8012B23C(s32);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_80182968(void);
extern s32 func_8005C49C(void);
extern unsigned char D_8018AA8C[];
extern unsigned char D_801AFF18[];
extern void func_8012A828(s32, void *);
extern void func_8002D4C8(s32, s32);
extern unsigned char D_801B09D0;
extern s32 D_80126B58;
extern s32 func_8012E544(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern s32 func_8012CBA4(s32 a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_80182968(void);
extern s32 func_8005C49C(void);
extern s16 D_8018AB94;
extern s16 D_8018AB96;
extern unsigned char D_8018AA8C[];
extern unsigned char D_801AFF18[];
extern unsigned char D_801B09D0;

void func_8018308C(s32 param_1)
{
    u8 *base = (u8 *)&D_80126B58;
    s32 flag;
    s32 cond;
    s32 t;
    s32 d;
    s32 y;
    u16 mode;
    s32 p;
    mode = *(u16 *)(param_1 + 0x70);
    cond = 1;
    if ((u32)(mode - 0x505) >= 2) {
        cond = ((mode & 0xff00) == 0x700);
    }
    if (cond == 0) {
        flag = 0;
    } else {
        p = func_8012E544(0x298);
        if (p != 0) {
            if (*(u16 *)(p + 2) != 2) {
                flag = 0;
            } else {
                d = *(s16 *)(p + 0xe) - *(s16 *)(param_1 + 0xe);
                if (d < 0) {
                    d = -d;
                }
                flag = d < 0x20;
            }
        }
    }
    if (flag != 0) {
        *(s16 *)(param_1 + 2) = 0x10;
        *(s16 *)(param_1 + 0x34) = 0;
        *(s16 *)(param_1 + 0x5c) = 0;
        *(s32 *)(param_1 + 0x1c) = 0;
        ((void (*)(s32, u8 *))func_8012A828)(param_1, ((u8 *)&D_801B09D0));
        *(s16 *)(param_1 + 0x98) = 0;
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x2c) |= 0x10;
        *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x1a) = 0x100;
        func_8002D4C8(0x436, 0);
    } else {
        switch (*(u16 *)(param_1 + 0x34)) {
        case 0:
            if (*(s16 *)(base + 0xe) > D_8018AB94) {
                *(u16 *)(param_1 + 0x34) = 1;
                func_8012B178(param_1, 0xfff60000);
            }
            break;
        case 1:
            t = *(u16 *)(param_1 + 0xfc) - 1;
            *(u16 *)(param_1 + 0xfc) = t;
            if ((t << 0x10) <= 0) {
                func_80143B6C(param_1, 0);
                *(u16 *)(param_1 + 0xfc) = 8;
            }
            func_8012CBA4(param_1);
            y = *(s16 *)(param_1 + 0xe);
            if ((y < D_8018AB96) || ((y - *(s16 *)(base + 0xe)) < 0x80)) {
                *(u16 *)(param_1 + 0x70) = 0;
                *(u8 *)(param_1 + 0xc1) = 0;
                *(u16 *)(param_1 + 0x2) = 1;
                *(u16 *)(param_1 + 0x34) = 0;
                *(s32 *)(param_1 + 0x1c) = (func_8005C49C() & 0x1f) + 0x46;
                *(u16 *)(param_1 + 0xe0) = 0;
                *(u16 *)(param_1 + 0xe2) = *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x12);
                switch ((s32)((u32)*(u16 *)(param_1 + 0x70) << 0x10) >> 0x18) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 7:
                    if ((*(u16 *)(param_1 + 0xfe) & 2) != 0) {
                        *(u16 *)(param_1 + 0xe2) = 0;
                    }
                    goto seq;
                case 5:
                    ((void (*)(s32))func_80182968)(param_1);
                    break;
                case 4:
                case 6:
                default:
                seq:
                    *(u16 *)(param_1 + 0xe4) = 0x1e;
                    *(u16 *)(param_1 + 0x5e) = 0;
                    *(u16 *)(param_1 + 0x5c) = 0xaa10;
                    func_8012B2CC(param_1);
                    func_8012B23C(param_1);
                    func_8012B14C(param_1, (s32)&D_8018AA8C);
                    func_8012A828(param_1, &D_801AFF18);
                    break;
                }
            }
            break;
        }
    }
}
