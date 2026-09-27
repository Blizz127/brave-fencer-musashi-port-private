/* Overlay range [80155E30,80155EA4) from MAIN.CD member 0012.
 * SHA256(span)=b3dd4656303a00bd4a12b98d5fbde0ad4b28f1a1a73e131da843325c25fc068b.
 * Word export for the native seam; the body below is a
 * verified MATCH (29/29 words at 0x80155E30, -O2). */
#include "psx_types.h"
#include "m2c_macros.h"

/* Verified byte-exact against retail by tools/match_function.py
 * (29/29 words at 0x80155E30). Retail's 40-byte frame needs 16 dead
 * bytes with zero $sp traffic: a dead address-taken `s32 du[4]` (12
 * bytes also works; the frame rounds). Same family as the `(void) &du`
 * idiom — a codegen constraint, not a source claim. Other types and
 * signatures are whatever reproduces the bytes; they are not evidence
 * of the original declaration. */

void func_80155FF8(void *, u8);                  /* static */
void func_801599A4();                            /* static */
void func_80159B3C(void *);                      /* static */
s32 func_80161208(void *);                          /* static */

void func_80155E30(void *arg0) {
    s32 du[4];
    (void) &du;
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    if (M2C_FIELD(arg0, u16 *, 0xB8) == 0x8000) {
        func_801599A4();
        func_80159B3C(arg0);
        return;
    }
    if (func_80161208(arg0) == 0) {
        func_80155FF8(arg0, M2C_FIELD(arg0, u8 *, 0x1AA));
    }
}
