/* Overlay range [8013E4B4,8013E558) from MAIN.CD member 0012.
 * SHA256(span)=2093ec3ff40c8c16819b72dab3f861b82dd4656b6405cddd7ee1c01ef0b8332d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E4B4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u16 guard;   
    u16 pad;     
    u16 field;   
    u8  rest[14];  
} Ent;
extern s32 func_8012C750(s32 a0);
extern void *D_801274CC;
extern u8 *D_801274C8;

void func_8013E4B4(void) {
    u8 *s0;
    Ent *p;
    s32 i;
    s0 = D_801274C8;
    if (s0 != 0) {
        if (*(u16 *)(s0 + 6) != 0) {
            do {
                func_8012C750(s0);
                s0 += 0x14;
            } while (*(u16 *)(s0 + 6) != 0);
        }
    }
    s0 = (u8 *)D_801274CC;
    if (s0 != 0) {
        p = (Ent *)(s0 + 6);
        for (i = 0; p[i].guard != 0; i++) {
            p[i].field &= 0x7FFF;
        }
    }
}
