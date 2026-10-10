/* sc03_0098: func_80173E1C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80015954(s32 a0, s32 a1);
extern void func_801484B0(s32 a0, s32 a1);
extern void func_80149350(s32 arg0);
extern void func_80139914(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_801399F0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern u8 D_800D5DC0[];
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 D_80127508;
extern void func_80171A1C(u8 *a0);
extern s32 D_80127508;
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern void func_801484B0(s32 a0, s32 a1);
extern void func_80149350(s32 arg0);
extern void func_80015954(s32 a0, s32 a1);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern s32 D_80127508;
extern u8 D_800D5DC0[];

void func_80173E1C(s32 a0)
{
    s32 s0;
    s32 *s1;
    s32 sp10[2];
    s32 sp18[2];
    s1 = &D_80127508;
    s0 = a0;
    if (*s1 != 0) {
        func_801484B0((s32)sp10, (s32)sp18);
        ((void (*)(s32, s32, s32))func_80149350)(s0, (s32)sp10, (s32)sp10);
        func_80015954((s32)sp10, *s1 + 4);
    }
    if (*(s32 *)(s0 + 0x198) != 0) {
        if (func_801399F0(*(s32 *)(s0 + 0x198)) == 0) {
            return;
        }
        func_80139914(*(s32 *)(s0 + 0x198));
        *(s32 *)(s0 + 0x198) = 0;
        func_80154274((s32 *)s0, (s32)&D_800D5DC0);
        func_80171A1C((u8 *)s0);
    } else {
        s32 iVar1 = *(s32 *)(s0 + 0x200) - 1;
        *(s32 *)(s0 + 0x200) = iVar1;
        if (iVar1 != -1) {
            return;
        }
        func_80154274((s32 *)s0, (s32)&D_800D5DC0);
        func_80171A1C((u8 *)s0);
    }
}
