/* Overlay range [8017DF40,8017E22C) from MAIN.CD member 0012.
 * SHA256(span)=2f588bba7bca73975724ec4c768f57db23ca1b91150f1a87acfd59cfcaaa0f9f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017DF40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* 152-byte engine block, copied whole (struct assignment -> 9x16B block move + 8B tail).
 * Uniquely suffixed: the host TU already sees `Blk152` from engine_types.h, and a C89
 * re-typedef of a visible name is a redefinition error. Same layout, same codegen. */
typedef struct { u32 w[38]; } Blk152_8017DF40;
/* ALIGN-1 4-byte element => lwl/lwr + swl/swr (cookbook §160a); a u32[] loop is wrong. */
typedef struct { u8 b[4]; } Blk4_8017DF40;

extern u8  D_80078E78[];   /* live: 152-byte block            (host TU declares this identically) */
extern u16 D_800A6588[];   /* live: u16[64]                                                      */
extern u8  D_800AE648[];   /* live: u8[64]                                                       */
extern u8  D_800BA1B8[];   /* live: u8[256]                                                      */
extern u8  D_800BA2B8[];   /* live: 4-byte struct[24], align 1                                   */

extern u8  D_8018581C[];   /* shadow: +0x000 */
extern u16 D_801858B4[];   /* shadow: +0x098 */
extern u8  D_80185934[];   /* shadow: +0x118 */
extern u8  D_80185974[];   /* shadow: +0x158 */
extern u8  D_80185A74[];   /* shadow: +0x258 */

/* Param is declared s32 by the host TU's file-scope prototype (:3695); the true test is
 * 16-bit (`sll $a0,$a0,16 ; bnez`, no sra), so the truncation lives in the test instead. */
void func_8017DF40(s32 arg0) {
    s16 i;

    if ((s16)arg0 == 0) {
        *(Blk152_8017DF40 *)D_80078E78 = *(Blk152_8017DF40 *)D_8018581C;
        for (i = 0; i < 64; i++) {
            D_800A6588[i] = D_801858B4[i];
        }
        for (i = 0; i < 64; i++) {
            D_800AE648[i] = D_80185934[i];
        }
        for (i = 0; i < 256; i++) {
            D_800BA1B8[i] = D_80185974[i];
        }
        for (i = 0; i < 24; i++) {
            ((Blk4_8017DF40 *)D_800BA2B8)[i] = ((Blk4_8017DF40 *)D_80185A74)[i];
        }
    } else {
        *(Blk152_8017DF40 *)D_8018581C = *(Blk152_8017DF40 *)D_80078E78;
        for (i = 0; i < 64; i++) {
            D_801858B4[i] = D_800A6588[i];
        }
        for (i = 0; i < 64; i++) {
            D_80185934[i] = D_800AE648[i];
        }
        for (i = 0; i < 256; i++) {
            D_80185974[i] = D_800BA1B8[i];
        }
        for (i = 0; i < 24; i++) {
            ((Blk4_8017DF40 *)D_80185A74)[i] = ((Blk4_8017DF40 *)D_800BA2B8)[i];
        }
    }
}
