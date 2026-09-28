/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A418 - byte-exact against retail at -O2 (tools/register_match.py). */
struct BigCopy;
struct BigCopy { s32 words[41]; };
struct Q16 { s32 a, b, c, d; };
extern struct BigCopy D_80114EE8;
extern s32 D_801151D4;

void func_8012A418(void) {
    struct Q16 *src;
    struct Q16 *dst;
    struct Q16 *end;
    src = (struct Q16 *)D_801151D4;
    dst = &D_80114EE8;
    end = src + 10;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (src != end);
    *(s32 *)dst = *(s32 *)src;
}
