/* Exact retail word export for [80045D00,80045FD0); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_8006CF9C();                                     /* static */
extern s32 D_8006CFA8;
extern s32 D_8006CFB0;
extern s32 D_8006CFB4;
extern s32 D_8006CFB8;
extern s32 D_8006CFBC;
extern s32 D_8006CFC0;
extern s32 D_8006CFC4;
extern s32 D_8006CFC8;
extern s32 D_8006CFCC;
extern s32 D_8006CFD0;
extern s32 D_8006CFD4;
extern s32 D_80073A58;
s32 func_8004239C();                               /* static */
void func_8004359C(s32);                               /* static */
void func_800435B4(s32);                               /* static */
void func_80043704(s32, s32);                              /* static */
void func_80043994(void *, s32);                          /* static */
void func_800439B4(void *, s32);                          /* static */
void func_800439D4(s32 (*)());                           /* static */
void func_800439F8();                                 /* static */
s32 func_80043B1C(void *);                             /* static */
extern s32 func_80045FD0;
void func_800460CC();                                 /* static */
void func_8005CD48(s32 (*)());                           /* static */

void func_80045D00(s32 arg0, s32 arg1) {
    s32 sp10;
    s32 var_a0;
    D_8006CFD4 = arg1;
    if ((arg0 & 0xFF) == 1) {
        if (D_8006CFB4 > 0) {
            if (D_8006CFB0 == 0x200) {
                if (D_8006CFD0 & 1) {
                    func_800439D4(0);
                    func_800439B4(&sp10, 3);
                    func_800439F8(0);
                    func_800439D4(func_80045FD0);
                } else {
                    func_80043994(&sp10, 3);
                }
                if (func_80043B1C(&sp10) != D_8006CFC0) {
                    func_8005CD48(D_80073A58);
                    D_8006CFB4 = -1;
                }
            }
            if (D_8006CFD0 & 1) {
                func_800439B4(D_8006CFA8, D_8006CFB0);
            } else {
                func_80043994(D_8006CFA8, D_8006CFB0);
                D_8006CFA8 = (void *) (D_8006CFA8 + (D_8006CFB0 * 4));
                D_8006CFB4 = (s32) (D_8006CFB4 - 1);
                D_8006CFC0 = (s32) (D_8006CFC0 + 1);
            }
        }
    } else {
        D_8006CFB4 = -1;
    }
    D_8006CFB8 = func_8004239C(-1);
    if (D_8006CFB4 < 0) {
        func_800460CC(1);
    }
    if ((D_8006CFBC + 0x4B0) < func_8004239C(-1)) {
        D_8006CFB4 = -1;
    }
    if ((D_8006CFB4 == 0) || ((D_8006CFBC + 0x4B0) < func_8004239C(-1))) {
        func_8004359C(D_8006CFC4);
        func_800435B4(D_8006CFC8);
        if (D_8006CFD0 & 1) {
            func_800439D4(D_8006CFCC);
        }
        func_80043704(9, 0);
        if (D_8006CF9C != 0) {
            var_a0 = 5;
            if (D_8006CFB4 == 0) {
                var_a0 = 2;
            }
            D_8006CF9C(var_a0, arg1);
        }
    }
}
