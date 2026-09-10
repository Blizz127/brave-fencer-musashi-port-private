/* Exact overlay word export for [8017BEE4,8017BF38) from MAIN.CD
 * member0012 (extracted/overlays/main/0012.bin offset 0x7BD8C, base 80128158).
 * Live STOP 8017BEE4: D_8017E358 cell. Includes fallthrough 8017BEEC.
 */
#include "psx_types.h"

/* Byte-exact recovery of [8017BEE4,8017BF38), including the fallthrough
 * at 8017BEEC. Table bounds and runtime index validity are not inferred. */
extern s16 D_801853F0;
extern s16 D_801853F2;
extern void (*D_80181D6C[])(void);

s32 func_8017BEE4(void) {
    s32 result;
    D_80181D6C[D_801853F0]();
    result = D_801853F2;
    if (result != 0) {
        return result;
    }
    return 0;
}
