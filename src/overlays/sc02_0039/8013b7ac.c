/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013B7AC - byte-exact against retail at -O0 (tools/register_match.py). */
typedef struct { s32 f0; u8 pad[0x18]; } E_3B7AC_8013B7AC;

void func_8013B7AC(int a0) {
    extern E_3B7AC_8013B7AC D_801A0CD8[];
 D_801A0CD8[a0].f0 = 0; }
