/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Copies size bytes to dest from the stream when it is ready, advancing the
 * stream position; returns 1 on success and 0 (after the failure hook) otherwise. */
extern u8  D_8006AEF4;
extern s32 D_800A46C8;

extern s32  func_8003C4F0(s32 mode);
extern s32  func_8003C498(s32 position);
extern void func_8003C438(s32 dest, s32 size);
extern void func_80037D74(void);

s32 func_8002FC64(s32 size, s32 dest)
{
    s32 *position;

    if ((D_8006AEF4 & 1) && func_8003C4F0(0) == 0) {
        goto fail;
    }
    position = &D_800A46C8;
    if (func_8003C498(*position) == 0) {
fail:
        func_80037D74();
        return 0;
    }
    func_8003C438(dest, size);
    *position += size;
    D_8006AEF4 |= 1;
    return 1;
}
