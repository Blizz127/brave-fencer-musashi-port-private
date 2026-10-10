/* sc03_0098: func_801814A8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);

void func_801814A8(a0)
s32 a0;
{
    s32 v1;
    if (func_8012BEE8(a0) != 0) {
        *(s16 *)(a0 + 2) = 6;
        v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(a0 + 0x34) = 0;
        *(u16 *)(v1 + 0x1C) = 0x400;
        *(u16 *)(v1 + 0x18) = 0x400;
        v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x1A) = 0x3000;
    }
}
