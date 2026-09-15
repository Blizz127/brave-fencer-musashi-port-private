/* Overlay range [80145EE8,80146014) from MAIN.CD member 0012.
 * SHA256(span)=a95498e1aa71dc94ff5ad139116abfa584d67d12641eae0b00b21cb7c10001f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                               /* extern */
extern s32 D_8017FD40;
extern s32 D_8017FD70;
extern s32 D_8017FDC0;
extern s32 D_8017FDF0;
extern s32 D_8017FE20;
void func_80146014(s32 (*)());                           /* static */

void func_80145EE8(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        if (func_80029178(0x1F) & 0xFF) {
            func_80146014(D_8017FD40);
        }
        if (func_80029178(0x21) & 0xFF) {
            func_80146014(D_8017FD70);
        }
        if (func_80029178(0x1E) & 0xFF) {
            func_80146014(D_8017FDC0);
        }
        if (func_80029178(0x1D) & 0xFF) {
            func_80146014(D_8017FDF0);
        }
        if (func_80029178(0x20) & 0xFF) {
block_14:
            func_80146014(D_8017FE20);
        }
        return;
    case 1:
        func_80146014(D_8017FD40);
        func_80146014(D_8017FD70);
        func_80146014(D_8017FDC0);
        func_80146014(D_8017FDF0);
        goto block_14;
    }
}
