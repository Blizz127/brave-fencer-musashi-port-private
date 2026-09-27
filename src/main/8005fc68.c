#include "psx_types.h"


extern s32 D_80078C7C;
extern s32 D_80078CC0;
extern void func_8006186C(void);
extern void func_80061A80(void);

/* The generated retail label grouped two adjacent callable ranges.  These
 * source functions retain their actual boundaries. */
void func_8005FC68(void) {
    D_80078C7C = 0;
    D_80078CC0 = 0;
    func_8006186C();
}
