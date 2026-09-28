/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F6B0 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_8016F330(void);
extern void func_80171928(void *a0);
extern void func_8016F330(void);

void func_8016F6B0(void *a0) {
    func_8016F330();
    func_80171928(a0);
}
