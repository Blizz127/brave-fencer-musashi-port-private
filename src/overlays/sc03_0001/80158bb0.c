/* sc03_0001: func_80158BB0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
struct S;
struct S {
    u8 pad0[0x7E];
    u16 f7E;
};
extern void func_80146CA0(void *a0);
extern s32 func_801472C8(struct S *a0);
extern void func_80147324(s32 arg0);
extern void func_801474D8(s32 *a0);
extern void func_801474EC(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80154A74(int, int);
extern s32 D_801ED518;
extern int D_801ED518;
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 func_801472C8(struct S *a0);
extern void func_80147324(s32 a0);
extern void func_801474D8(s32 *a0);
extern void func_801474EC(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern M2C_UNK D_800D58D8;
extern s32 D_801ED518;

void func_80158BB0(void *arg0) {
    if (D_801ED518 == 0) {
        D_801ED518 = 1;
    }
    func_80147324(0x456);
    func_80154274(arg0, &D_800D58D8);
    func_80154A74(arg0, 0x16);
    (*(s32 *)((s8 *)(arg0) + (0x234))) = 0xE30000;
    (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x20)))) + (0x10))) = 0;
    func_801474EC(arg0);
    func_801474D8(arg0);
    func_801472C8(arg0);
    func_80146CA0(arg0);
}
