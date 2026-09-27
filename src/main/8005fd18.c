/* Main-exec range [8005FD18,8005FD58) from the SLUS executable.
 * SHA256(span)=af929fa54ef0b5f652aeb17186bd9003c1a97b3920bf73efafa9766794af57b2.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

extern s32 D_80078C80;
extern void func_80042644(s32, void *);
extern void func_80061AA0(void);

/* Byte-exact state poll and dispatch [8005FD18,8005FD58). */
void func_8005FD18(void) {
    volatile s32 *state = &D_80078C80;
    while (*state != 0)
        ;
    func_80042644(7, 0);
    func_80061AA0();
}
