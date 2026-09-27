/* Overlay range [80155150,801552F4) from MAIN.CD member 0012.
 * SHA256(span)=8c483e020b14e2fe42f0d1477c9416178a6b22c7ac60906e2cd9d7e5d794c5c6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001D130(s32, s32);                /* extern */
void func_8001D150(s32, s32);                /* extern */
s32 func_8014BEF8(void *);                          /* static */

void func_80155150(void *arg0) {
    s32 temp_v1;

    func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x19);
    func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x18);
    func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x16);
    func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x15);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x44);
    if (!(temp_v1 & 0x400)) {
        if (!(temp_v1 & 0x20000)) {
            if (temp_v1 & 0x20000000) {
                func_8001D130(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x19);
                goto block_7;
            }
            if (func_8014BEF8(arg0) != 0) {
                func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x19);
                func_8001D130(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x18);
            } else {
                func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x19);
block_7:
                func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x18);
            }
        }
        if (M2C_FIELD(arg0, s32 *, 0x44) & 0x10000000) {
            func_8001D130(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x16);
            goto block_11;
        }
        func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x16);
        func_8001D130(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x15);
        if (M2C_FIELD(arg0, s32 *, 0x44) & 4) {
block_11:
            func_8001D150(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x24), 0x15);
        }
    }
}
