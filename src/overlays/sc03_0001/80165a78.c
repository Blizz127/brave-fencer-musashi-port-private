/* sc03_0001: func_80165A78 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
extern void func_80165AC8(void);
void func_80165AC8(void);

void func_80165A78(s32 arg0)
{
    void *temp_a0;
    func_80165AC8();
    temp_a0 = (*(void **)((s8 *)(arg0) + (0x20)));
    (*(s8 *)((s8 *)(arg0) + (0x197))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x44))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x44))) & ~8);
    (*(u16 *)((s8 *)(temp_a0) + (0x2C))) = (u16) ((*(u16 *)((s8 *)(temp_a0) + (0x2C))) & 0xFFDF);
}
