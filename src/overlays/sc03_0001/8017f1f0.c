/* sc03_0001: func_8017F1F0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8017E1B4(void *a0);
void aF8017E1B4(void) __asm__("func_8017E1B4");

void func_8017F1F0(s32 a0, s32 a1)
{
    extern s32 D_801EEAEC[];
    register s32 rv __asm__("$2");
    s32 x = D_801EEAEC[0];
    s32 y = a1;
    s32 d;
    if (y < a0) {
        if (x < y) {
            x = x + 0x5A0;
        }
        y = y + 0x5A0;
    }
    if (a0 >= x) {
        rv = -1;
        goto done;
    }
    if (x >= y) {
        rv = -1;
        goto done;
    }
    d = x - a0;
    if (d < 16) {
        rv = d * 2;
        goto done;
    }
    d = y - x;
    if (d < 16) {
        rv = d * 2;
        goto done;
    }
    rv = 31;
done:
    __asm__("" :: "r"(rv));
}
