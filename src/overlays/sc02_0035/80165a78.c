/* SC02.CD member35: func_80165A78 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
extern u8 D_80078EC1;
extern u8 D_80078EC1;
extern u8 D_80078EC1;
extern u8 D_80078EC1;
extern u8 D_80078EC1;
extern u8 D_80078EC1;
extern u8 D_80078EC1;
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
extern u8 D_80078EC1;
