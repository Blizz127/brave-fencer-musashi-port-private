/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012853C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80011C10(void);
extern void func_80146074(void);

void func_8012853C(void) {
    func_80146074();
    func_80011C10();
}
