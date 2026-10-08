/* Owner re-derivation from retail assembly (clean input set). */
/* Boot-time graphics reset, then clears the 152-byte state block at 800BA118. */
#include "psx_types.h"

extern u8 D_800BA118[];

extern void func_80059234(s32 mode);
extern void func_800594CC(s32 level);
extern void func_80059658(s32 mask);
extern void func_80016714(void *dst, s32 size);
extern void func_800142C8(void);

void func_800141F0(void)
{
    func_80059234(0);
    func_800594CC(0);
    func_80059658(0);
    func_80016714(D_800BA118, 152);
    func_800142C8();
}
