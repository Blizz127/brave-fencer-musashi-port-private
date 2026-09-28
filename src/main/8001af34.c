/* Exact retail word export for [8001AF34,8001B0D4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001AF34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define CdQueueBusy func_80034B98
#define CdReadStateMachine func_80019AF8
#define cdReq_cdlFile D_800AE7A4
#define cdReq_curSector D_800AE708
#define cdReq_dest D_800AE72C
#define cdReq_result D_800AE7B0
#define cdReq_size D_800AE7A8

extern s32 D_800BA1B4;
extern s32 D_800AE6E4;
extern s32 D_800BA318;
extern s32 D_800C6D2C;
extern s32 D_800A6550;
extern s32 cdReq_curSector;
extern void *cdReq_dest;
extern s32 cdReq_size;
extern void *cdReq_cdlFile;
extern s32 D_800AE724;
extern s32 D_800AE720;
extern s32 cdReq_result;
extern s32 D_800AE640;
extern s32 D_800A6430;
extern s16 D_800A6430_h __asm__("D_800A6430");
extern s32 D_800747E4;
extern s32 CdQueueBusy(void);
extern void CdReadStateMachine(int);
extern s32 func_8001B394(s32);
extern s32 func_8001B7C4(void *);
extern s32 func_8001B0D4(void *, s32);

void func_8001AF34(void) {
    s32 *cdlFile;
    s32 dest;
    s32 size;
    s32 mode;
    s32 sector;
    s32 ret;

    CdQueueBusy();
    switch (D_800BA1B4) {
    case 0:
        return;
    case 1:
        cdlFile = (s32 *)D_800AE6E4;
        dest = D_800BA318;
        size = D_800C6D2C;
        mode = D_800A6550;
        if (CdQueueBusy() != 0) {
            ret = 0;
            goto chk;
        }
        if (cdReq_curSector == 0) {
            sector = *cdlFile;
        } else {
            sector = *cdlFile;
            if (sector != cdReq_curSector) {
                ret = 0;
                goto chk;
            }
        }
        cdReq_dest = (void *)dest;
        cdReq_size = size;
        cdReq_cdlFile = (void *)cdlFile;
        D_800AE724 = mode;
        D_800AE720 = 0;
        cdReq_curSector = sector;
        if (mode == 0) {
            D_800AE720 = 1;
        }
        CdReadStateMachine(0);
        ret = cdReq_result;
    chk:
        if (ret == 0) {
            return;
        }
        D_800BA1B4 = 3;
        return;
    case 2:
        if (func_8001B394(D_800AE640) == 0) {
            return;
        }
        D_800BA1B4 = 3;
        return;
    case 3:
        return;
    case 4:
        if (func_8001B7C4((void *)D_800AE6E4) == 0) {
            return;
        }
        D_800BA1B4 = 3;
        return;
    case 5:
        if (func_8001B0D4((void *)D_800AE6E4, D_800A6430_h) == 0) {
            return;
        }
        D_800747E4 = 0;
        D_800BA1B4 = 3;
        return;
    }
}
