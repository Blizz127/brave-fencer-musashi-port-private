/* Exact retail word export for [800460CC,800462E0); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CFA0;
extern s32 D_8006CFA4;
extern s32 D_8006CFA8;
extern s32 D_8006CFAC;
extern s32 D_8006CFB4;
extern s32 D_8006CFB8;
extern s32 D_8006CFBC;
extern s32 D_8006CFC0;
extern s32 D_8006CFD0;
extern s32 D_80073A70;
extern s32 D_80073A88;
s32 func_8004239C();                               /* static */
s32 func_80043410();                                /* static */
s32 func_80043420();                                /* static */
s8 *func_80043440();                                /* static */
void func_800434BC();                                  /* static */
void func_8004359C();                                 /* static */
void func_800435B4(s32 (*)());                           /* static */
s32 func_800435CC(s32, s8 *, s32);                      /* static */
void func_80043704(s32, s32);                              /* static */
void func_800439D4(s32 (*)());                           /* static */
s32 func_80043B1C(s8 *);                            /* static */
extern s32 func_80045D00;
extern s32 func_80045FD0;
void func_8005CD48(s32 (*)());                           /* static */

s32 func_800460CC(s32 arg0) {
    s8 sp10;
    s32 temp_s0;

    func_8004359C(0);
    func_800435B4(0);
    if (D_8006CFD0 & 1) {
        func_800439D4(0);
    }
    if (func_80043410() & 0x10) {
        if (!(func_8004239C(-1) & 0x3F)) {
            func_8005CD48(D_80073A70);
        }
        func_80043704(1, 0);
        D_8006CFBC = func_8004239C(-1);
        D_8006CFB4 = -1;
    } else if ((arg0 != 0) && (func_8005CD48(D_80073A88), func_800435CC(9, 0, 0), (func_800435CC(2, func_80043440(), 0) == 0))) {
        D_8006CFB4 = -1;
    } else {
        func_800434BC();
        sp10 = (s8) D_8006CFAC;
        temp_s0 = D_8006CFAC & 0xFF;
        if (((temp_s0 != func_80043420()) || (arg0 != 0)) && (func_800435CC(0xE, &sp10, 0) == 0)) {
            D_8006CFB4 = -1;
        } else {
            D_8006CFC0 = func_80043B1C(func_80043440());
            func_800435B4(func_80045D00);
            if (D_8006CFD0 & 1) {
                func_800439D4(func_80045FD0);
            }
            D_8006CFA8 = (s32) D_8006CFA4;
            func_80043704(6, 0);
            D_8006CFB4 = (s32) D_8006CFA0;
            D_8006CFB8 = func_8004239C(-1);
        }
    }
    return D_8006CFB4;
}
