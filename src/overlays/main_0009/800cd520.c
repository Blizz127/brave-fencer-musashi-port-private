/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD520 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8001AD38(const char*);
extern void func_800116A0(void);
extern s32 D_800CDD34;
void func_800116A0(void);
extern const u32 D_800CD364[];

void func_800CD520(void) {
    func_8001AD38((const char *)D_800CD364);
    D_800CDD34 = 0;
    func_800116A0();
}
