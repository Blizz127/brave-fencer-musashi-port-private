/* Main-exec range [8001903C,80019064) from the SLUS executable.
 * SHA256(span)=da433ee7e770c147252312ec9b6241a12093b448ae1b0deecf03e4aa10399cdf.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

extern u8 D_800747C0[];
void func_80016714(u8 *, s32);

/* Recovered from retail and verified byte-exact with gcc-2.7.2-psx -O2. */
void func_8001903C(void) {
    func_80016714(D_800747C0, 8);
}
