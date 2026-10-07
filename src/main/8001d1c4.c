/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Updates the game state's six object pools with func_8001D388, sharing one
 * running count. Pool 0 always runs; pools 1-5 are skipped while their
 * disable bit (0x04, 0x10, 0x20, 0x40, 0x80) is set in state byte 0xA3E1. */
typedef struct {
    u8 unk0[0x38];
} PoolObject;   /* 0x38 bytes */

extern u8 D_800AF630[];

extern void func_8001D388(PoolObject *obj, s32 *count);

void func_8001D1C4(void)
{
    s32 count = 0;
    u8 flags = D_800AF630[0xA3E1];
    PoolObject *obj;

    for (obj = (PoolObject *)(D_800AF630 + 0x65A8); obj < (PoolObject *)(D_800AF630 + 0x6688); obj++) {
        func_8001D388(obj, &count);
    }
    if (!(flags & 0x04)) {
        for (obj = (PoolObject *)(D_800AF630 + 0x6688); obj < (PoolObject *)(D_800AF630 + 0x66F8); obj++) {
            func_8001D388(obj, &count);
        }
    }
    if (!(flags & 0x10)) {
        for (obj = (PoolObject *)(D_800AF630 + 0x66F8); obj < (PoolObject *)(D_800AF630 + 0x6A78); obj++) {
            func_8001D388(obj, &count);
        }
    }
    if (!(flags & 0x20)) {
        for (obj = (PoolObject *)(D_800AF630 + 0x6A78); obj < (PoolObject *)(D_800AF630 + 0x7338); obj++) {
            func_8001D388(obj, &count);
        }
    }
    if (!(flags & 0x40)) {
        for (obj = (PoolObject *)(D_800AF630 + 0x7338); obj < (PoolObject *)(D_800AF630 + 0x8138); obj++) {
            func_8001D388(obj, &count);
        }
    }
    if (!(flags & 0x80)) {
        for (obj = (PoolObject *)(D_800AF630 + 0x8138); obj < (PoolObject *)(D_800AF630 + 0x9DA8); obj++) {
            func_8001D388(obj, &count);
        }
    }
}
