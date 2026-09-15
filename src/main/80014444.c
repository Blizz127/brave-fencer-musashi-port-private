/* Exact retail word export for [80014444,800144D4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800144D4();                                  /* static */
void func_8001455C();                                  /* static */
void func_8002823C();                                  /* static */
void func_8002850C(s32, s32, s32);                           /* static */
void func_80047CB4();                                  /* static */
void func_8004923C();                                 /* static */
void func_80052D90(s32, void *);                         /* static */
void func_80053218();                                  /* static */
void func_800538EC();                                 /* static */
extern s32 *D_800AF630;
extern s32 D_80126950;

void func_80014444(void) {
    func_80047CB4();
    D_80126950 = 0x3E8;
    func_8004923C(0x3E8);
    func_80053218();
    func_800144D4();
    func_8001455C();
    func_8002850C(0x800, 0x800, 0x800);
    func_8002823C();
    func_80052D90(0, &D_800AF630 + 0x1A0);
    func_80052D90(1, &D_800AF630 + 0x1F0);
    func_800538EC(0);
}
