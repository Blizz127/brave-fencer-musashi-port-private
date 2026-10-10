/* sc03_0098: func_8012C284 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80126720[];

u16 *func_8012C284(u16 *a0)
{
    u16 *end;
    end = (u16 *)D_80126720;
    if (a0 == 0) {
        a0 = (u16 *)(D_80126720 - 0x6480);
    } else {
        a0 = (u16 *)((u8 *)a0 + 0x10C);
    }
    while (a0 != end) {
        if (*a0 == 0) {
            return a0;
        }
        a0 = (u16 *)((u8 *)a0 + 0x10C);
    }
    return 0;
}
