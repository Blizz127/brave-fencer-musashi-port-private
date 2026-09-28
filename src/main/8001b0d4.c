/* Exact retail word export for [8001B0D4,8001B22C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001B0D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define CdQueueBusy func_80034B98

/* Vendor typedefs this body depends on (copied from vendor/bfm-decomp). */
typedef struct {
    u8 minute; /* +0x00 */
    u8 second; /* +0x01 */
    u8 sector; /* +0x02 */
    u8 track;  /* +0x03 */
} CdlLOC;

extern s32 D_800747E0;
extern s32 D_800747E4;
extern s32 D_800747E8;
extern void func_80036AF8(CdlLOC *loc, s32 flags);
extern s32 CdQueueBusy(void);
extern int func_8001A114(void);

s32 func_8001B0D4(void *arg0, s32 arg1) {
    s32 t;

    switch (D_800747E4) {
    case 0:
        func_80036AF8((CdlLOC *)arg0, (s16)arg1);
        D_800747E8 = 1;
        D_800747E4 = D_800747E4 + 1;
        goto L_ret0;
    case 1:
        t = CdQueueBusy();
        switch (t) {
        case 0:
            D_800747E0 = 1;
            goto L_ret0;
        case 8:
            D_800747E8 = 4;
            D_800747E4 = 4;
            goto L_ret0;
        case 2:
        case 4:
            D_800747E8 = t;
            D_800747E4 = D_800747E4 + 1;
            goto L_ret0;
        case 1:
            D_800747E8 = t;
            goto L_ret0;
        }
        goto L_ret0;
    case 2:
        t = CdQueueBusy();
        switch (t) {
        case 1:
        case 2:
        case 4:
            D_800747E8 = t;
            goto L_ret0;
        case 0:
        case 8:
            D_800747E8 = 0;
            return 1;
        }
        goto L_ret0;
    case 3:
        if (func_8001A114() == 0) {
            goto L_ret0;
        }
        D_800747E4 = 0;
        goto L_ret0;
    case 4:
        D_800747E8 = 0;
        return 1;
    }
L_ret0:
    return 0;
}
