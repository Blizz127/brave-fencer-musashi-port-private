/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E4ED0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801E6644[];
extern void func_80171A1C(void*);
extern s32 func_80014C54(s32, s32, s32);
extern void func_800D1724(void *);
extern void func_80171A1C(void *);

void func_801E4ED0(void *arg0) {

    extern u8 D_801E6644[];
    s32 result;
    result = func_80014C54(0, 0, 0x80);
    if ((result << 16) != 0) {
        func_800D1724(&(*(int *)D_801E6644));
        func_80171A1C(arg0);
    }
}
