/* sc03_0001: func_80156B74 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct S8;
struct UnalignedPair;
struct packed_word;
union word_bytes;
struct S8 { u32 a; u32 b; } __attribute__((packed, aligned(1)));
struct UnalignedPair {
    int a;
    int b;
} __attribute__((packed, aligned(1)));
struct packed_word { int w; } __attribute__((packed, aligned(1)));
union word_bytes {
    struct packed_word pw;
    u8 b[4];
};
typedef struct { s16 a; s16 b; s16 c; s16 d; } S8;
typedef struct { u8 b[8]; } B8;
struct PW8017E6D8 { int w; } __attribute__((packed, aligned(1)));
struct W4 { u32 w; } __attribute__((packed, aligned(1)));
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4;
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_80165140;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_80165140;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
struct PW8017C290 { int w; } __attribute__((packed, aligned(1)));
struct PW8017E72C { int w; } __attribute__((packed, aligned(1)));
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_8018EDB0;
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_8018F060;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_8018EDB0;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_8018F060;
typedef struct { u8 b[4]; } __attribute__((packed, aligned(1))) Blk4_E960;
typedef struct { u8 b[4]; } __attribute__((packed, aligned(1))) Block4;
extern void func_801484B0(s32 a0, s32 a1);
extern void func_801484E8(s32 a0, s32 a1);
extern void func_80148534(s32 a0, s32 a1);
extern void func_8014856C(s32 a0, s32 a1);
extern void func_800139C8(s32 a0, void *a1, void *a2);
extern S8 D_80126AF0[];
extern S8 D_80126AF0[];

void func_80156B74(s32 param_1, u32 param_2, u8 *param_3) {
    extern S8 D_80126AF0[];
    extern S8 D_801270A8;
    extern void func_801484B0(s32 a0, s32 a1);
    extern void func_801484E8(s32 a0, s32 a1);
    extern void func_80148534(s32 a0, s32 a1);
    extern void func_8014856C(s32 a0, s32 a1);
    extern void func_800139C8(s32 a0, void *a1, void *a2);
    extern void func_80156ECC(s32 a0, void *a1, void *a2, void *a3, void *a4);
    u16 local_28[3];
    B8 auStack_20;
    s32 v1 = *(s32 *)(param_1 + 0x20);
    D_801270A8.a = 0;
    D_801270A8.b = -0x1E;
    D_801270A8.c = 0;
    if (param_2 == 0) {
        if (*(s32 *)(v1 + 0x20) != 0) {
            ((void (*)(void *, void *))func_801484B0)(local_28, &auStack_20);
            D_80126AF0[0].a = local_28[0];
            D_80126AF0[0].b = local_28[1];
            D_80126AF0[0].c = local_28[2];
            ((void (*)(void *, void *))func_801484E8)(local_28, &auStack_20);
            D_80126AF0[1].a = local_28[0];
            D_80126AF0[1].b = local_28[1];
            D_80126AF0[1].c = local_28[2];
            goto L_call;
        }
        goto L_zero;
    }
    if (param_2 != 1) goto L_not1;
    if (*(s32 *)(v1 + 0x20) != 0) {
        ((void (*)(void *, void *))func_80148534)(local_28, &auStack_20);
        D_80126AF0[0].a = local_28[0];
        D_80126AF0[0].b = local_28[1];
        D_80126AF0[0].c = local_28[2];
        ((void (*)(void *, void *))func_8014856C)(local_28, &auStack_20);
        D_80126AF0[1].a = local_28[1];
        D_80126AF0[1].b = local_28[1];
        D_80126AF0[1].c = local_28[2];
        goto L_call;
    }
L_zero:
    D_80126AF0[0].a = 0;
    D_80126AF0[0].b = 0;
    D_80126AF0[0].c = 0;
    D_80126AF0[1].a = 0;
    D_80126AF0[1].b = 0;
    D_80126AF0[1].c = 0;
    goto L_call;
L_not1:
    if (param_2 == 2) {
        D_80126AF0[0].a = 0;
        D_80126AF0[0].b = -0x1E;
        D_80126AF0[0].c = -0x52;
        func_800139C8((s32)(s16)(*(u16 *)(param_1 + 0x24A) - *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x12)),
                      &D_80126AF0[0], &D_80126AF0[0]);
        D_80126AF0[1].a = 0;
        D_80126AF0[1].b = -0x1E;
        D_80126AF0[1].c = -0x52;
        goto L_call;
    }
    {
        u32 uVar1 = param_2 & 0x80FFFFFF;
        D_80126AF0[0].a = (s8)*(u8 *)(*param_3 * 3 + uVar1);
        D_80126AF0[0].b = (s8)*(u8 *)(*param_3 * 3 + uVar1 + 1);
        D_80126AF0[0].c = (s8)*(u8 *)(*param_3 * 3 + uVar1 + 2);
        D_80126AF0[1].a = (s8)*(u8 *)(*param_3 * 3 + uVar1 + 3);
        D_80126AF0[1].b = (s8)*(u8 *)(*param_3 * 3 + uVar1 + 4);
        D_80126AF0[1].c = (s8)*(u8 *)(*param_3 * 3 + uVar1 + 5);
    }
L_call:
    if ((param_2 & 0xF000000) == 0) {
        *param_3 = *param_3 + 1;
    }
    func_80156ECC(param_1, &D_801270A8, &D_80126AF0[0], &D_80126AF0[1], &D_80126AF0[2]);
}
