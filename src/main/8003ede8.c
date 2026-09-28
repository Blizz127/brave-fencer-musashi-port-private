/* Exact retail word export for [8003EDE8,8003EEE4); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003EDE8 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s32 mask; s32 pad4[3]; s16 dl, dr; s32 pad14[2]; s16 fl, fr; s32 pad20[2]; } RvAttr;
extern void func_8003C598(RvAttr *);
void func_8003EDE8(u8 which, s16 l, s16 r)
{
    RvAttr at;

    if (which == 0) {
        at.mask = 0xC0;
        if (l >= 128) {
            l = 127;
        }
        if (r >= 128) {
            r = 127;
        }
        at.dl = l * 258;
        at.dr = r * 258;
    }
    if (which == 1) {
        at.mask = 0xC00;
        if (l >= 128) {
            l = 127;
        }
        if (r >= 128) {
            r = 127;
        }
        at.fl = l * 258;
        at.fr = r * 258;
    }
    func_8003C598(&at);
}
