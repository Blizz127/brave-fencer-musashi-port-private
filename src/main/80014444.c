/* Exact retail word export for [80014444,800144D4); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (36/36 words at 0x80014444). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

void func_800144D4();                                  /* static */
void func_8001455C();                                  /* static */
void func_8002823C();                                  /* static */
void func_8002850C(s32, s32, s32);                           /* static */
void func_80047CB4();                                  /* static */
void func_8004923C();                                 /* static */
void func_80052D90(s32, void *);                         /* static */
void func_80053218();                                  /* static */
void func_800538EC();                                 /* static */
extern u8 D_800AF630[];
extern s32 D_80126950;

void func_80014444(void) {
    u8 *base;
    base = &D_800AF630[0];
    func_80047CB4();
    D_80126950 = 0x3E8;
    func_8004923C(0x3E8);
    func_80053218();
    func_800144D4();
    func_8001455C();
    func_8002850C(0x800, 0x800, 0x800);
    func_8002823C();
    func_80052D90(0, base + 0x1A0);
    func_80052D90(1, base + 0x1F0);
    func_800538EC(0);
}
