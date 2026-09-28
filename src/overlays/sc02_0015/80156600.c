/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80156600 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8;
struct S8 { u32 a; u32 b; } __attribute__((packed, aligned(1)));
typedef struct { s16 a; s16 b; s16 c; s16 d; } S8;
extern s32 D_801151E0[];
extern S8 D_80126AF0[];

s32 func_80156600(void* _arg0)
{
    u32 i = 0;
    s8 *ptr = &((s8 *)D_80126AF0)[0];
    do {
        if (D_801151E0[i] & 1) {
            return ptr;
        }
        ptr += 8;
        i++;
    } while (i < 3);
    return (s8 *)0;
}
