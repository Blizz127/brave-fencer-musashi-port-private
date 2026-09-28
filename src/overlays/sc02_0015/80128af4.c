/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128AF4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern u16 D_800B99F6;
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern void func_8002AEF8(void);
extern void func_800CFBBC(void);
extern M2C_UNK (*D_8017E224)();
extern s32 (*D_8017E228)();
extern s32 D_8018EFF0;

void func_80128AF4(void) {
    switch (D_800B99F6) {                            
    case 0:
        D_8018EFF0 = func_8002AF08();
        func_80011C10();
        return;
    case 1:
        D_8017E224();
        func_80011C10();
        return;
    case 2:
        if ((D_8017E228() << 0x10) != 0) {
            if (D_8018EFF0 == 1) {
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
