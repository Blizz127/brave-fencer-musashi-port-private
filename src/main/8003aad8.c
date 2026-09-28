/* Main-exec range [8003AAD8,8003AB84) from the SLUS executable.
 * SHA256(span)=dc1a73e617197db28fdccefc26869e740aa04f693b15952455d2c8574dc1af14.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003AAD8 - byte-exact against retail at -O2 (tools/register_match.py). */

extern volatile u16 *D_8006B54C;
extern volatile u32 *D_8006B550;
extern volatile u32 *D_8006B554;
extern volatile u32 *D_8006B558;
extern s32 D_8006B59C;
extern void func_8003B0E4(void);
extern void func_8003B0B8(void);
void func_8003AAD8(u32 madr, u16 addr, s32 size)
{
    D_8006B54C[0xD3] = addr;
    func_8003B0E4();
    D_8006B54C[0xD5] |= 0x30;
    func_8003B0E4();
    func_8003B0B8();
    *D_8006B550 = madr;
    *D_8006B554 = (size << 16) | 0x10;
    D_8006B59C = 1;
    *D_8006B558 = 0x01000200;
}
