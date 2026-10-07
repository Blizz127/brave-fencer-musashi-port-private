/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Per-session reset at the top of main's outer loop: heap setup, GPU reset,
 * display off, VSync(0), clears the 0xA444-byte game state block, re-runs the
 * subsystem inits, then turns the display back on. */
extern u8 D_800AF630[];

extern void func_80014928(void);
extern void func_80059234(s32 mode);
extern void func_80059658(s32 on);  /* SetDispMask */
extern s32  func_8004239C(s32 mode);  /* VSync */
extern void func_80016714(u8 *dst, s32 size);
extern void func_800143AC(void);
extern void func_80014444(void);
extern void func_8001C044(void);
extern void func_80014588(void);
extern void func_80015310(void);
extern void func_80028A48(void);
extern void func_80028C50(void);
extern void func_800142C8(void);

void func_80014238(void)
{
    func_80014928();
    func_80059234(1);
    func_80059658(0);
    func_8004239C(0);
    func_80016714(D_800AF630, 0xA444);
    func_800143AC();
    func_80014444();
    func_8001C044();
    func_80014588();
    func_80015310();
    func_80028A48();
    func_80028C50();
    func_800142C8();
    func_80059658(1);
}
