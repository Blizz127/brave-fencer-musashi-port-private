/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80152C40 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80149020(s32 *a0);
extern void func_80159B3C(void *a0);
extern void func_80149020(s32 *a0);
extern void func_80165718(s32 a0);
extern void func_80152C80(s32 *a0);

void func_80152C40(s32 *a0) {
    func_80149020(a0);
    func_80152C80(a0);
    func_80159B3C(a0);
    func_80165718((s32)a0);
}
