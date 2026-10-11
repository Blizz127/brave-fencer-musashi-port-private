/* sc03_0001: func_80174BF4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void (*D_80190B84[])();

void func_80174BF4(void * arg0)
{
    (*(s32 *)((s8 *)(arg0) + (0xC))) = 0x12C;
    (*(s32 *)((s8 *)(arg0) + (0x14))) = 0x12C;
    (*(s16 *)((s8 *)(arg0) + (0x20))) = 0x155;
    (*(s16 *)((s8 *)(arg0) + (0x22))) = 0x800;
    (*(s16 *)((s8 *)(arg0) + (0x24))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x2E))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x30))) = -0x28;
    (*(s16 *)((s8 *)(arg0) + (0x32))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x54))) = 0;
    D_80190B84[(*(u8 *)((s8 *)(arg0) + (4)))]();
}
