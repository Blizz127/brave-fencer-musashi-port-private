/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB6A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);

void func_800CB6A4(void *arg0) {
    extern s32 func_800CB6FC(s32 a0);
    extern void func_80146C3C(void);

    (*(s32 *)((char *)arg0 + 0x1C))++;
    if ((*(s32 *)((char *)arg0 + 0x1C)) < 2) {
        *(u32 *)((char *)arg0 + 0x30) >>= 1;
        func_800CB6FC((s32)arg0);
    } else {
        func_80146C3C();
    }
}
