/* SC02 resident retail span [8013BC7C,8013BCDC). Offset 0x13B24 at base 80128158.
 * SHA256(span)=f2eaee939cb9fa1fdb8de3705dc673f414b53b00ac18236c95197b0116d028e0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E338->D_80184C28.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80184C28[];
typedef struct {
    u8 pad_0[104];
    s32 idx;
} T;
void func_8013BC7C(T *p) {
    D_80184C28[p->idx](p);
}
