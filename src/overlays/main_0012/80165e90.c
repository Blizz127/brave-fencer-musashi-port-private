/* Overlay range [80165E90,80165FA4) from MAIN.CD member 0012.
 * SHA256(span)=a333e8cb00dfd8aa5c4395585cb5d118b4e81b4ec8c1666c334844ceec9cf00a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801484B0(void *, void *);        /* static */
void func_80148534(void *, void *);        /* static */
void func_80165FA4(void *, void *, void *); /* static */
void func_80167AE0(void *, void *, void *); /* static */
void func_80167DBC(void *, void *, void *); /* static */
extern s32 *D_80126B58;
extern void *D_80126B78;
extern s32 D_80126B9C;

void func_80165E90(void) {
    s32 sp18;
    s32 sp10;
    if ((D_80126B9C & 0x10000400) == 0x10000000) {
        if (M2C_FIELD(D_80126B78, s32 *, 4) >= 0) {
            if (M2C_FIELD(D_80126B78, s32 *, 0x20) != 0) {
                func_801484B0(&sp10, &sp18);
                func_80165FA4(&D_80126B58, &sp10, &sp18);
                func_80167DBC(&D_80126B58, &sp10, &sp18);
            }
        }
    }
    if (((M2C_FIELD(&D_80126B58, s32 *, 0x44) & 0x20020400) == 0x20000000) && (M2C_FIELD(M2C_FIELD(&D_80126B58, void **, 0x20), s32 *, 4) >= 0) && (M2C_FIELD(M2C_FIELD(&D_80126B58, void **, 0x20), s32 *, 0x20) != 0)) {
        func_80148534(&sp10, &sp18);
        func_80165FA4(&D_80126B58, &sp10, &sp18);
        func_80167AE0(&D_80126B58, &sp10, &sp18);
    }
}
