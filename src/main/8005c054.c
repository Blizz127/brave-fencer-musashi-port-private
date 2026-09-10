/* Exact retail word export for [8005C054,8005C1C0); EXE and assembly verified. */
#include "psx_types.h"

/* Byte-exact timeout/reset recovery. MMIO and queue observations must
 * remain explicit. func_80072880 is a data symbol despite its name.
 * Volatile array views recover accesses, not original declarations. */
extern s32 func_8004239C(s32);
extern s32 func_800426FC(s32);
extern s32 func_8005C604(const char *, ...);
extern s32 D_800728A0, D_800728A4, D_8007289C;
extern volatile s32 D_8007288C, D_80072890;
extern volatile u32 D_8007287C[];
extern u32 func_80072880, D_80072884;
extern volatile u32 *D_8007285C, *D_80072860, *D_80072868, *D_80072878;
extern char D_80074238[], D_8007426C[];

s32 func_8005C054(void) {
    s32 old_count, previous;
    if (D_800728A0 < func_8004239C(-1) ||
        (old_count = D_800728A4, D_800728A4 = old_count + 1,
         old_count > 0xF0000)) {
        (void)*D_8007285C;
        func_8005C604(D_80074238, (D_8007288C - D_80072890) & 0x3F,
                     *D_8007285C, *D_80072868, *D_80072860);
        func_8005C604(D_8007426C, D_8007287C[0], func_80072880, D_80072884);
        previous = func_800426FC(0);
        D_80072890 = 0;
        D_8007289C = previous;
        D_8007288C = D_80072890;
        *D_80072868 = 0x401;
        *D_80072878 |= 0x800;
        *D_8007285C = 0x02000000;
        *D_8007285C = 0x01000000;
        func_800426FC(D_8007289C);
        return -1;
    }
    return 0;
}
