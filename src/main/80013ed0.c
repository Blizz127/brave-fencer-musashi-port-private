/* Main-exec helper [80013ED0,80013F3C): interleaves three u16 triples.
 * SHA256(span)=0adba29b1ddfd12cac90b885bed5a9dee2458b3f0185597a9c8d9a6e34f7e8e4. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80013ED0(void *arg0, void *arg1, void *arg2, void *arg3) {
    M2C_FIELD(arg0, u16 *, 0) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg2, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(arg3, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 8) = (u16) M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(arg3, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 0xC) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg2, u16 *, 4);
    M2C_FIELD(arg0, u16 *, 0x10) = (u16) M2C_FIELD(arg3, u16 *, 4);
}
