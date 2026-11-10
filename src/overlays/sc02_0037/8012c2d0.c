/* sc02_0037: func_8012C2D0 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_801202A0[];
extern u8 D_80120194[];
extern u8 D_801202A0[];

s32 func_8012C2D0(void)
{
    s32 p;
    s32 it;
    it = (s32)D_80120194;
    __asm__ __volatile__("" : "=r"(it) : "0"(it));
    p = it + 0x658C;
    goto test;
copy:
    return it;
test:
    it = (s32)D_801202A0;
    __asm__ __volatile__("" : "=r"(it) : "0"(it));
    if (it == p) goto zero;
body:
    if (*(u16 *)it == 0) goto copy;
    it += 0x10C;
    if (it != p) goto body;
zero:
    return 0;
}
