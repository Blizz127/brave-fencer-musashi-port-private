/* Overlay range [8017BD50,8017BE60) from MAIN.CD member 0012.
 * SHA256(span)=db033eb94c298c42c48730c33c5dbb7f62a5c799810fdffe666fb961b3aa9ba3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017BD50 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012A4BC(void);
void func_8017B0E4(int param_1, int param_2);
extern void func_8017B0E4(int, int);

void func_8017BD50(int param_1)
{

    extern s16 D_8018534C;
    extern void (*D_80185390)(void);
    extern short D_801853D4;
    extern short D_801853D6;
    extern short D_801853D8;
    extern s16 D_80185C08;
    extern s32 aD80114F24 __asm__("D_80114F24");
    extern s32 D_80114F28;
    extern s32 D_80114F2C;
    extern s32 D_80114F30;
    extern s32 D_80114F34;
    extern s32 D_80114F38;
    func_8017B0E4(param_1, 6);
    D_8018534C = D_8018534C + 1;
    if (D_8018534C >= 0x19) {
        if (D_80185390 != 0) {
            (*D_80185390)();
        } else {
            D_80114F30 = D_80114F30 + D_801853D4;
            D_80114F34 = D_80114F34 + D_801853D6;
            D_80114F38 = D_80114F38 + D_801853D8;
            aD80114F24 = aD80114F24 + D_801853D4;
            D_80114F28 = D_80114F28 + D_801853D6;
            D_80114F2C = D_80114F2C + D_801853D8;
            func_8012A4BC();
        }
        D_80185C08 = 0;
    }
}
