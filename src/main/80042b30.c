/* Main-exec range [80042B30,80042BDC) from the SLUS executable.
 * SHA256(span)=2e2555998d1583252b6005222542e9d255355740c95b9c953efcbd39d839afae.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80042B30 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u16 unk0; u8 pad2[0x30]; u16 unk32; u32 unk34; u8 unk38[1]; } IntrEnv;
extern IntrEnv D_8006BAFC;
extern volatile u16 *D_8006CB8C;
extern volatile u32 *D_8006CB90;
extern volatile u16 *D_8006CB88;
extern void func_8005CF08(void);
extern void func_8005CEE8(void);
void *func_80042B30(void)
{
    IntrEnv *env = &D_8006BAFC;

    if (env->unk0 == 0) {
        return 0;
    }
    func_8005CF08();
    D_8006BAFC.unk32 = *D_8006CB8C;
    D_8006BAFC.unk34 = *D_8006CB90;
    *D_8006CB88 = *D_8006CB8C = 0;
    *D_8006CB90 &= 0x77777777;
    func_8005CEE8();
    env->unk0 = 0;
    return env;
}
