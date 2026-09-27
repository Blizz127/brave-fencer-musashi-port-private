/* Exact retail word export for [8005BED8,8005C020); EXE and assembly verified. */
#include "psx_types.h"

/* Byte-exact full range [8005BED8,8005C020); generated assembly omitted
 * the entry label. MMIO reads must remain observable on each iteration.
 * Native execution needs a platform boundary, not direct PS1 addresses. */
extern void func_8005C020(void);
extern void func_8005BA90(void);
extern s32 func_8005C054(void);
extern s32 D_8007288C, D_80072890;
extern volatile u32 *D_80072868;
extern volatile u32 *D_8007285C;

s32 func_8005BED8(s32 mode) {
    s32 pending;
    if (mode == 0) {
        func_8005C020();
        while (D_8007288C != D_80072890) {
            func_8005BA90();
            if (func_8005C054() != 0) {
                return -1;
            }
        }
        while ((*D_80072868 & 0x01000000) != 0 ||
               (*D_8007285C & 0x04000000) == 0) {
            if (func_8005C054() != 0) {
                return -1;
            }
        }
        return 0;
    }
    pending = (D_8007288C - D_80072890) & 0x3F;
    if (pending != 0) {
        func_8005BA90();
    }
    if ((*D_80072868 & 0x01000000) != 0 ||
        (*D_8007285C & 0x04000000) == 0) {
        if (pending == 0) {
            return 1;
        }
        return pending;
    }
    return pending;
}
