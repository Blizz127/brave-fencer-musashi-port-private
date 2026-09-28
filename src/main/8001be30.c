/* Main-exec range [8001BE30,8001BFA0) from the SLUS executable.
 * SHA256(span)=8809a183b5e72629bc72787be6c9673714adb2f1b988acc595c4fab87d373f2d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001BE30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define CdQueueBusy func_80034B98
#define cdReq_curSector D_800AE708

extern s32 D_800747EC;
extern s32 D_800747E4;
extern s32 D_800747E8;
extern s32 D_800BA1B4;
extern s32 cdReq_curSector;
extern s32 CdQueueBusy(void);
extern void func_8002D4C8(int arg0, int arg1);

s32 func_8001BE30(void) {
    s32 state = D_800747EC;
    s32 busy;
    s32 v0;

    if (state == 1) {
        goto L_case1;
    }
    if (state < 2) {
        if (state != 0) {
            return 0;
        }
        goto L_case0;
    }
    if (state == 2) {
        goto L_case2;
    }
    if (state == 3) {
        goto L_case3;
    }
    return 0;

L_case0:
    busy = CdQueueBusy();
    if (D_800BA1B4 != 5) {
        goto L_busy;
    }
    if (D_800747E4 != 0) {
        func_8002D4C8(0x16, 0);
    }
    D_800BA1B4 = 0;
    D_800747E8 = 0;
    D_800747E4 = 0;
    D_800747EC = 3;
    goto L_ret0;

L_busy:
    if (busy == 1 || busy == 4 || busy == 2) {
        func_8002D4C8(0x16, 0);
        D_800747EC = D_800747EC + 1;
        goto L_ret0;
    }
    if (cdReq_curSector == 0) {
        return 1;
    }
    D_800747EC = 2;
    return 0;

L_case1:
    v0 = CdQueueBusy();
    goto L_shared;

L_case2:
    v0 = cdReq_curSector;
    goto L_shared;

L_case3:
    v0 = D_800747E8;

L_shared:
    if (v0 == 0) {
        __asm__ __volatile__("");
        return 1;
    }
L_ret0:
    return 0;
}
