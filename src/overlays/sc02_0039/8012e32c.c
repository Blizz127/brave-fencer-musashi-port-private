/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E32C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern u8 D_800AF648;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);

void func_8012E32C(void) {
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
}
