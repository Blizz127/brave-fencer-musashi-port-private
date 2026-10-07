/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Sets up the 2 KB heap at 0x801FF800 (libapi InitHeap), bracketed by two
 * other libapi calls. */
extern void func_8005CF08(void);
extern void func_8005CE18(u32 addr, s32 size);  /* InitHeap */
extern void func_8005CF18(void);

void func_80014928(void)
{
    func_8005CF08();
    func_8005CE18(0x801FF800, 0x800);
    func_8005CF18();
}
