/* Main-exec range [80042BDC,80042C64) from the SLUS executable.
 * SHA256(span)=310f4fbfe05d64f7e76756377d194aee4b880c1a5574cc7b6748e8403bf74874.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80042BDC - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u16 unk0; u8 pad2[0x30]; u16 unk32; u32 unk34; u8 unk38[1]; } IntrEnv;
extern IntrEnv D_8006BAFC;
extern volatile u16 *D_8006CB8C;
extern volatile u32 *D_8006CB90;
extern void func_8005CEF8(void *);
extern void func_8005CF18(void);
void *func_80042BDC(void)
{
    IntrEnv *env = &D_8006BAFC;

    if (env->unk0 != 0) {
        return 0;
    }
    func_8005CEF8(env->unk38);
    env->unk0 = 1;
    *D_8006CB8C = D_8006BAFC.unk32;
    *D_8006CB90 = D_8006BAFC.unk34;
    func_8005CF18();
    return env;
}
