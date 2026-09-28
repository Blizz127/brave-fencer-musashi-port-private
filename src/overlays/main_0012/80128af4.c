/* Overlay range [80128AF4,80128C14) from MAIN.CD member 0012.
 * SHA256(span)=c1e4d951e65138b64a458d2bfc71a0ab5e64c57d98e1e6f51dbdf76d8073322c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128AF4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern void func_8002AEF8(void);
extern void func_800CFBBC(void);

void func_80128AF4(void) {

    extern u16 D_800B99F6;
    extern M2C_UNK (*D_8017E360)();
    extern s32 (*D_8017E364)();
    extern s32 D_801840B0;
    switch (D_800B99F6) {                            
    case 0:
        D_801840B0 = func_8002AF08();
        func_80011C10();
        return;
    case 1:
        D_8017E360();
        func_80011C10();
        return;
    case 2:
        if ((D_8017E364() << 0x10) != 0) {
            if (D_801840B0 == 1) {
                if (func_800CFBE8() != 0) {
                    func_800CFBBC();
                    func_80011B7C(0x13);
                } else {
                    func_80011B7C(4);
                }
            } else {
                func_80010DE0();
            }
            func_8002AEF8();
        }
        return;
    }
}
