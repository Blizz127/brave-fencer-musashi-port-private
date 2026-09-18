/* Overlay range [8014FD54,8014FDF4) from MAIN.CD member 0012.
 * SHA256(span)=af63cdd965d25481ff9443812a6f0a28d266d5c7b14b74dec1bbe07477e6bc2f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014FD54 - 40 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80149290(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);

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
