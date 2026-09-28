/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014FD54 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80133784(int a0, void *a1, int a2);
void func_80149290(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_80149290(s32 a0);

int func_8014FD54(int param_1)
{
    short buf1[3];
    short buf2[4];
    int ret;
    register int result __asm__("$2");
    buf1[0] = 0;
    buf1[1] = 0;
    buf1[2] = 7;
    ((void (*)(int, void *, void *))func_80149290)(param_1, buf1, buf1);
    buf2[0] = 0;
    buf2[1] = 0;
    buf2[2] = (short)0xffe8;
    ((void (*)(int, void *, void *))func_80149290)(param_1, buf2, buf2);
    ret = func_80133784(1, buf1, (int)buf2);
    if (ret != 0) {
        result = 0;
        if ((ret & 0x8000) != 0) {
            result = *(unsigned char *)((char *)buf2 + 6) == 0x15;
        }
    } else {
        result = 0;
    }
    return result;
}
