/* Main-exec range [80014128,80014148) from the SLUS executable.
 * SHA256(span)=6cc04f7fe3524317e0683572a364308e1a2a221181fd81449a5fd12bcb949bfc.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Matched leaf functions from the main executable's first region.
 *
 * The filename is provisional and names the address the file starts at; it is
 * renamed once a real translation-unit boundary is identified.
 */

#include "psx_types.h"

/* Forward declaration only. The callee lives elsewhere in the executable, so
 * this reference is undefined in the compiled object and is resolved at link
 * time from its splat name, which carries its address. */
extern void func_80048FBC(s32, s32, s32);

/* Non-leaf wrapper at vram 0x80014128.
 *
 * Its only purpose in this repository is to prove the link step: the call is a
 * relocation, so bytes taken straight from the object would be meaningless and
 * only become comparable with retail after linking.
 *
 * Signatures and types here are the loosest that reproduce the bytes; they are
 * not evidence of the original declaration.
 */
/* a0-a2 pass straight through to func_80048FBC (the retail words leave
 * them untouched before the jal), so they are parameters here. */
void func_80014128(s32 a0, s32 a1, s32 a2) {
    func_80048FBC(a0, a1, a2);
}
