/* SC02.CD member35 [80158BB0,80158C40): twin of main_0012 80158BB0 (src/overlays/main_0012/80158bb0.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80158BB0,80158C40) from MAIN.CD member 0012.
 * SHA256(span)=de25155abdb319ae387f49d94b966083ff8c9ba32ac8512cb5d9af16ef4216c2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801BD770;
void func_80146CA0(void *);                      /* static */
void func_801472C8(void *);                      /* static */
void func_80147324();                     /* static */
void func_801474D8(void *);                      /* static */
void func_801474EC(void *);                      /* static */
void func_80154274(void *, void *);           /* static */
void func_80154A74(void *, s32);             /* static */
extern s32 *D_800D58D8;

void func_80158BB0(void *arg0) {
    if (D_801BD770 == 0) {
        D_801BD770 = 1;
    }
    func_80147324(0x456);
    func_80154274(arg0, &D_800D58D8);
    func_80154A74(arg0, 0x16);
    M2C_FIELD(arg0, s32 *, 0x234) = 0xE30000;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x10) = 0;
    func_801474EC(arg0);
    func_801474D8(arg0);
    func_801472C8(arg0);
    func_80146CA0(arg0);
}
