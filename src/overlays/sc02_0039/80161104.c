/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161104 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80161208();
extern s32 func_80161208();
extern s32 func_80161208(void);
extern s32  func_80161208();

s32 func_80161104(void) {
    return func_80161208() == 0;
}
