/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Calls func_80034844, then func_80031B7C. */
extern void func_80034844(void);
extern void func_80031B7C(void);

void func_8002EFD0(void)
{
    func_80034844();
    func_80031B7C();
}
