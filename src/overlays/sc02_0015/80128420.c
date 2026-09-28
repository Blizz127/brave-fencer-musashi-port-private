/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128420 - byte-exact against retail at -O2 (tools/register_match.py). */
#define SsUtReverbOff func_800285AC
extern void func_80015310(void);
extern void func_801378F0(void);
extern void func_80011C10(void);
extern void func_80129220(void);
extern void func_80011E24(void);
extern void func_80128C14(void);
extern void func_8002AEF8(void);
extern void func_800CFBBC(void);
extern void SsUtReverbOff(void);
extern void func_8013C98C(void);
extern void func_80129C40(s32 a0);
extern void func_800D0630(void);
extern void func_80145CEC(void);
extern void func_80144B9C(void);
extern u8 D_800B9A17;
extern u8 D_800B9A10;

void func_80128420(void) {
    func_80129220();
    func_801378F0();
    func_80011E24();
    func_80128C14();
    func_8002AEF8();
    func_800CFBBC();
    func_80015310();
    SsUtReverbOff();
    D_800B9A17 = 0;
    D_800B9A10 = 0;
    func_8013C98C();
    func_80129C40(0);
    func_800D0630();
    func_80145CEC();
    func_80144B9C();
    func_80011C10();
}
