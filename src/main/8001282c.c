/* PSY-Q library routine [8001282C,800128B4) from the SLUS executable.
 * SHA256(span)=cc4d6b1325599fe604328d90fedbdf2d4878525f79804f08351b5292e6f5eeb4.
 * Word export only: the native seam needs the retail instruction stream so the
 * guest can execute the library routine it calls. No C match claim yet.
 */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800128B4(void *);                               /* static */
void func_80013ED0(s32, void *, void *, void *);                /* static */
void func_80013F98(s32, void *);                          /* static */
void func_80013FBC(s32, void *);                          /* static */
void func_80013FE0(void *);                               /* static */

void func_8001282C(s32 arg0) {
    s32 sp20;
    s32 sp18;
    s32 sp10;
    func_80013FE0(&sp20);
    func_800128B4(&sp20);
    func_80013FBC(arg0, &sp18);
    func_800128B4(&sp18);
    func_80013F98(arg0, &sp10);
    func_800128B4(&sp10);
    func_80013ED0(arg0, &sp10, &sp18, &sp20);
}
