/* Main-exec range [80029EC0,80029ED4) from the SLUS executable.
 * SHA256(span)=b3752c1f3bed9a24be6fbcb93cea3d467dd01f5fcdb5815934700aaf1724c124.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Guest pointers held as u32 for the 64-bit native lane. */
#include "psx_types.h"
typedef struct { u8 pad[0x2E]; s16 v; } Inner;
typedef struct { u8 pad[0x78]; u32 p; /* guest Inner * */ } T;
s16 func_80029EC0(T *t) { return ((Inner *)t->p)->v; }
