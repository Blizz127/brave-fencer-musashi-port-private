/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE0C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800183E0(s32 a0);
extern u8 D_800CB680[];
extern u8 D_800CB6C0[];
extern u8 D_800CB700[];
extern u8 D_800CB740[];
extern u8 D_800CB780[];
extern u8 D_800CB7C0[];
extern u8 D_800CB800[];
extern u8 D_800CB840[];
extern u8 D_800CB640[];

void func_800CAE0C(void) {
    func_800183E0((s32)D_800CB680);
    func_800183E0((s32)D_800CB6C0);
    func_800183E0((s32)D_800CB700);
    func_800183E0((s32)D_800CB740);
    func_800183E0((s32)D_800CB780);
    func_800183E0((s32)D_800CB7C0);
    func_800183E0((s32)D_800CB800);
    func_800183E0((s32)D_800CB840);
    func_800183E0((s32)D_800CB640);
}
