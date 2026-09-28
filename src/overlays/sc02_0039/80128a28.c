/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128A28 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern u16 D_800B99F6;
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern s16 D_800B9A00;
extern M2C_UNK (*D_8017F0D0)();
extern s16 (*D_8017F0D4)();

void func_80128A28(void) {
    s16 temp_v0;

    switch (D_800B99F6) {                            
    case 1:
        D_8017F0D0();
         
    case 0:
        func_80011C10();
        return;
    case 2:
        temp_v0 = D_8017F0D4();
        if (temp_v0 != 0) {
            if (temp_v0 < 0) {
                func_80011B7C(0);
                D_800B9A00 = 1;
                return;
            }
            func_80010DE0();
        } else {
            return;
        }
        break;
    }
}
