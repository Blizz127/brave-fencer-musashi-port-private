/* Exact retail word export for [800596F4,80059760); EXE and assembly verified. */
#include "psx_types.h"

/* Byte-exact dispatch recovery. The opaque prefix preserves a PS1 offset;
 * this function-pointer layout is not a native deserialization structure. */
typedef struct SyncDispatchView {
    u8 opaque00[0x3C];
    s32 (*sync)(s32);
} SyncDispatchView;
extern SyncDispatchView *D_80072780;
extern s32 (*D_80072784)(const char *, ...);
extern u8 D_8007278A;
extern char D_80074140[];

s32 func_800596F4(s32 mode) {
    if (D_8007278A >= 2U) {
        D_80072784(D_80074140, mode);
    }
    return D_80072780->sync(mode);
}
