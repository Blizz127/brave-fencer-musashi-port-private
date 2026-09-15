/* Exact retail word export for [800CEEFC,800CEF60); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (25/25 words at 0x800CEEFC). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

void func_800118AC();                                  
void func_80015310();                                  
void func_800167B8();                                 
void func_800183E0(s32 (*)());                           
void func_8001C044();                                  
extern s32 D_800D130C;
extern s32 D_800D1364;
extern s16 D_800B99E8;
extern s8 D_800B9A11;

void func_800CEEFC(void) {
    D_800B9A11 = 1;
    func_8001C044();
    func_80015310();
    D_800D1364 = 0;
    func_800183E0(&D_800D130C);
    func_800167B8(0);
    D_800B99E8 = 0;
    func_800118AC();
}
