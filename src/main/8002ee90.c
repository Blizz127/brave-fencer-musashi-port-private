/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Calls func_80036EE8, then func_8002EC10. */
extern void func_80036EE8(void);
extern void func_8002EC10(void);

void func_8002EE90(void)
{
    func_80036EE8();
    func_8002EC10();
}
