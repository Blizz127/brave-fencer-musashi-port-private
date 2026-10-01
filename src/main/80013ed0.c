/* Main-exec helper [80013ED0,80013F3C): interleaves three u16 triples.
 * SHA256(span)=0adba29b1ddfd12cac90b885bed5a9dee2458b3f0185597a9c8d9a6e34f7e8e4. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80013ED0(void *arg0, void *arg1, void *arg2, void *arg3) {
    (*(u16 *) ((s8 *) (arg0) + (0))) = (u16) (*(u16 *) ((s8 *) (arg1) + (0)));
    (*(u16 *) ((s8 *) (arg0) + (2))) = (u16) (*(u16 *) ((s8 *) (arg2) + (0)));
    (*(u16 *) ((s8 *) (arg0) + (4))) = (u16) (*(u16 *) ((s8 *) (arg3) + (0)));
    (*(u16 *) ((s8 *) (arg0) + (6))) = (u16) (*(u16 *) ((s8 *) (arg1) + (2)));
    (*(u16 *) ((s8 *) (arg0) + (8))) = (u16) (*(u16 *) ((s8 *) (arg2) + (2)));
    (*(u16 *) ((s8 *) (arg0) + (0xA))) = (u16) (*(u16 *) ((s8 *) (arg3) + (2)));
    (*(u16 *) ((s8 *) (arg0) + (0xC))) = (u16) (*(u16 *) ((s8 *) (arg1) + (4)));
    (*(u16 *) ((s8 *) (arg0) + (0xE))) = (u16) (*(u16 *) ((s8 *) (arg2) + (4)));
    (*(u16 *) ((s8 *) (arg0) + (0x10))) = (u16) (*(u16 *) ((s8 *) (arg3) + (4)));
}
