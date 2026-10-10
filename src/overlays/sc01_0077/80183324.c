/* sc01_0077: func_80183324 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183324.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012B030(u8 *a0);
extern void func_8012A828(int, void *);
extern void func_8012B2CC(int);
extern void func_8012B23C(int);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012B23C(s32 a0);
extern void func_8012B2CC(int a0);
extern void func_8012B23C(int a0);
extern void func_8012A828(int a0, void *a1);
extern void func_80182968(void);
extern unsigned char D_8018AA8C[];
extern unsigned char D_801AFF18[];
extern void func_80182988();
extern void func_80182988(int param_1);
extern void func_8012B2CC(s32);
extern void func_8012B23C(s32);
extern u8 D_801AFD28;
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8001C214(s32 a0, s32 a1);
extern s32 func_80143970(s32 a0);
extern s32 func_8012B030(u8 *a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_80182968(void);
extern void func_80182988(s32 a0);
extern s32 func_8005C49C(void);
extern u8 D_8018AD90[];
extern s32 D_8018AD60[];
extern u8 D_8018ABC0[];
extern u8 D_8018AABC[];
extern u8 D_8018AA8C[];
extern u8 D_8018ABA8[];
extern u8 D_8018ABAA[];
extern u8 D_8018ABAC[];
extern u8 D_801AFD28;
extern u8 D_801AFF18[];
extern u8 D_801AFFC0[];

void func_80183324(s32 param_1) {
    s32 frame_pad[4];
    s32 idx;
    u8 *ptr;
    u16 mode;
    s32 cond;
    u16 tmp;
    (void)&frame_pad;
    if (func_8012C354(param_1, (s32)&D_8018AD90) == 0) {
        return;
    }
    idx = (s32)((u32)*(u16 *)(param_1 + 0x70) << 0x10) >> 0x18;
    func_8001C214(*(s32 *)(param_1 + 0x20), D_8018AD60[idx]);
    ptr = &D_8018ABC0[idx * 0x34];
    *(s32 *)(param_1 + 0x78) = (s32)ptr;
    *(u16 *)(param_1 + 0x76) = *(u16 *)ptr;
    func_80143970(param_1);
    func_8012B030((u8 *)param_1);
    *(u16 *)(param_1 + 0x100) = 0;
    *(s32 *)(param_1 + 0xbc) = (s32)&D_8018AABC;
    *(s32 *)(param_1 + 0x38) = *(s32 *)(param_1 + 0x4);
    *(s32 *)(param_1 + 0x3c) = *(s32 *)(param_1 + 0x8);
    *(s32 *)(param_1 + 0x40) = *(s32 *)(param_1 + 0xc);
    mode = *(u16 *)(param_1 + 0x70);
    cond = 1;
    if ((u32)(mode - 0x505) >= 2) {
        cond = ((mode & 0xff00) == 0x700);
    }
    if (cond != 0) {
        *(u16 *)(param_1 + 0x86) = 0xb4;
    }
    switch ((s32)((u32)*(u16 *)(param_1 + 0x70) << 0x10) >> 0x18) {
    case 0:
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
            goto seq0;
        case 5:
            ((void (*)(s32))func_80182968)(param_1);
            break;
        case 4:
        case 6:
        default:
        seq0:
            *(u16 *)(param_1 + 0xe4) = 0x1e;
            *(u16 *)(param_1 + 0x5e) = 0;
            *(u16 *)(param_1 + 0x5c) = 0xaa10;
            func_8012B2CC(param_1);
            func_8012B23C(param_1);
            func_8012B14C(param_1, (s32)&D_8018AA8C);
            func_8012A828(param_1, &D_801AFF18);
            break;
        }
        if ((*(u16 *)(param_1 + 0x70) & 0x80) != 0) {
            *(u16 *)(param_1 + 0x5c) = 0xaa10;
            *(u16 *)(param_1 + 0x2) = 1;
            *(u16 *)(param_1 + 0x34) = 2;
            *(u16 *)(param_1 + 0x5e) = 0;
            *(s32 *)(param_1 + 0x1c) = 0x1e;
            func_8012A828(param_1, &D_801AFFC0);
            *(u16 *)(param_1 + 0xfc) = 0;
        }
        break;
    case 1:
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
            goto seq1;
        case 5:
            ((void (*)(s32))func_80182968)(param_1);
            break;
        case 4:
        case 6:
        default:
        seq1:
            *(u16 *)(param_1 + 0xe4) = 0x1e;
            *(u16 *)(param_1 + 0x5e) = 0;
            *(u16 *)(param_1 + 0x5c) = 0xaa10;
            func_8012B2CC(param_1);
            func_8012B23C(param_1);
            func_8012B14C(param_1, (s32)&D_8018AA8C);
            func_8012A828(param_1, &D_801AFF18);
            break;
        }
        break;
    case 2:
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
            goto seq2;
        case 5:
            ((void (*)(s32))func_80182968)(param_1);
            break;
        case 4:
        case 6:
        default:
        seq2:
            *(u16 *)(param_1 + 0xe4) = 0x1e;
            *(u16 *)(param_1 + 0x5e) = 0;
            *(u16 *)(param_1 + 0x5c) = 0xaa10;
            func_8012B2CC(param_1);
            func_8012B23C(param_1);
            func_8012B14C(param_1, (s32)&D_8018AA8C);
            func_8012A828(param_1, &D_801AFF18);
            break;
        }
        break;
    case 3:
        *(u16 *)(param_1 + 0x6) = *(u16 *)&D_8018ABA8[*(u8 *)(param_1 + 0x70) * 8];
        *(u16 *)(param_1 + 0xa) = *(u16 *)&D_8018ABAA[*(u8 *)(param_1 + 0x70) * 8];
        tmp = *(u16 *)&D_8018ABAC[*(u8 *)(param_1 + 0x70) * 8];
        *(u16 *)(param_1 + 0x2) = 9;
        *(u16 *)(param_1 + 0x34) = 0;
        *(u16 *)(param_1 + 0x5e) = 0;
        *(u16 *)(param_1 + 0x5c) = 0xaa10;
        *(u16 *)(param_1 + 0xe) = tmp;
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x12) = 0;
        func_8012B2CC(param_1);
        func_8012B23C(param_1);
        func_8012A828(param_1, &D_801AFD28);
        break;
    case 4:
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x12) = func_8005C49C() & 0xfff;
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
            goto seq4;
        case 5:
            ((void (*)(s32))func_80182968)(param_1);
            break;
        case 4:
        case 6:
        default:
        seq4:
            *(u16 *)(param_1 + 0xe4) = 0x1e;
            *(u16 *)(param_1 + 0x5e) = 0;
            *(u16 *)(param_1 + 0x5c) = 0xaa10;
            func_8012B2CC(param_1);
            func_8012B23C(param_1);
            func_8012B14C(param_1, (s32)&D_8018AA8C);
            func_8012A828(param_1, &D_801AFF18);
            break;
        }
        break;
    case 5:
        func_80182988(param_1);
        break;
    case 6:
        *(u16 *)(param_1 + 0x2) = 0xd;
        *(u16 *)(param_1 + 0x34) = 0;
        *(u16 *)(param_1 + 0x5c) = 0;
        *(s32 *)(param_1 + 0x1c) = 0x10;
        func_8012A828(param_1, &D_801AFFC0);
        break;
    case 7:
        *(u16 *)(param_1 + 0x2) = 0x11;
        *(u16 *)(param_1 + 0x34) = 0;
        *(u16 *)(param_1 + 0x5c) = 0;
        func_8012A828(param_1, &D_801AFFC0);
        *(s32 *)(param_1 + 0x1c) = 0;
        func_8012B2CC(param_1);
        break;
    }
    *(s32 *)(param_1 + 0x24) = *(s16 *)(param_1 + 0x6);
    *(s32 *)(param_1 + 0x28) = *(s16 *)(param_1 + 0xa);
    *(s32 *)(param_1 + 0x2c) = *(s16 *)(param_1 + 0xe);
}
