/* Main-exec range [8003602C,80036130) from the SLUS executable.
 * SHA256(span)=f0cb22c2f006b8cf007fff763341a46fc2748aa94e25bf8eeec75ed9fb85132e.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8003602C - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_80076214;
extern void func_800434BC(void);
extern s32 func_8004355C(s32 mode, u8 *result);
extern s32 func_80043704(u8 com, u8 *param);
extern void func_8003621C(void);

void func_8003602C(s32 arg0) {
    u8 result[8];
    u8 state;
    s32 sync;

    switch (*(u8 *)(arg0 + 3)) {
    case 0:
    case 1:
    default:
        *(u8 *)(arg0 + 2) = 0;
        break;
    case 2:
        *(u8 *)(arg0 + 2) = 1;
        func_800434BC();
        *(u8 *)(arg0 + 3) += 2;
        break;
    case 3:
        *(u8 *)(arg0 + 2) = 1;
        func_800434BC();
        *(u8 *)(arg0 + 3) += 1;
        /* fall through */
    case 4:
        func_80043704(9, 0);
        func_8003621C();
        state = *(u8 *)(arg0 + 3);
        *(u8 *)(arg0 + 2) = 1;
        *(u8 *)(arg0 + 3) = state + 1;
        break;
    case 5:
        sync = func_8004355C(1, result);
        if (sync == 0) {
            *(u8 *)(arg0 + 2) = 1;
            return;
        }
        if (sync == 5 && (result[0] & 0x10)) {
            D_80076214 = 1;
        }
        *(u8 *)(arg0 + 2) = 0;
        break;
    }
}
