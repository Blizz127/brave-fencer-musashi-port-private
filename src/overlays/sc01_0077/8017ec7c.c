/* sc01_0077: func_8017EC7C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct vec;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
typedef struct { s32 w[8]; } Blk20;
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern int func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern Blk20 D_800AE620;

s32 func_8017EC7C(s32 param_1)
{
    s32 vec[3];
    Blk20 mat;
    u32 uVar1;
    *(s32 *)(param_1 + 0x10) = 0;
    *(s32 *)(param_1 + 0x14) = 0x10000;
    *(s32 *)(param_1 + 0x18) = 0;
    uVar1 = func_8005C49C();
    mat = D_800AE620;
    func_8004A0DC(uVar1 & 0xFFF, &mat);
    vec[0] = 0x4000;
    vec[2] = 0;
    vec[1] = 0;
    func_800484EC((s32)&mat, (s32)vec, (s32)vec);
    *(s32 *)(param_1 + 0x2C) = vec[0];
    *(s32 *)(param_1 + 0x30) = vec[2];
    *(s16 *)(param_1 + 0x34) = 0;
}
