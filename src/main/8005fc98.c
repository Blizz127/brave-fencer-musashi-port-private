/* Main-exec range [8005FC98,8005FCB8) from the SLUS executable.
 * SHA256(span)=47e23e7ae13bb0d42c6bc943c42b4d800575dc874ed0af621d980fee2266591d.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

extern void func_80061A80(void);

/* Byte-exact adjacent startup reset range [8005FC98,8005FCB8). */
void func_8005FC98(void) {
    func_80061A80();
}
