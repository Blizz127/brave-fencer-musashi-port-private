/* sc03_0098: func_80139914 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013A8B0(s32 *a0);
void func_8013A8B0(s32 *a0);

void func_80139914(s32 arg0)
{
    s32 temp_a0;
    (*(s16 *)((s8 *)(arg0) + (4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    if ((*(u16 *)((s8 *)(arg0) + (0x18))) != 0) {
        temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x40)));
        if (temp_a0 != 0) {
            func_8013A8B0(temp_a0);
        }
    }
}
