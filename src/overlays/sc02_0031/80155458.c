/* SC02 resident retail span [80155458,801554B8). Offset 0x2D300 at base 80128158.
 * SHA256(span)=d602244354d657d2eb39b545f471c25adf5a92e7b31fb7beac4d19d1c4a15f8b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910); the C
 * is the Druthulu shared/ov func_80155458 shape (the two published variants
 * differ only in the dispatch table) retargeted to this member's D_80186ADC.
 * Oracle MATCH 24/24. Not MAIN10.
 */
#include "psx_types.h"

typedef int (*CB)(void);
extern CB D_80186ADC[];

s32 func_80155458(s32 param_1)
{
    int idx;

    idx = *(unsigned char *)(param_1 + 0x4e);
    if (idx != 0) {
        idx = idx - 1;
        if ((*D_80186ADC[idx])() == 0) {
            *(unsigned char *)(param_1 + 0x4e) = 0;
        }
    }
    return *(unsigned char *)(param_1 + 0x4e);
}
