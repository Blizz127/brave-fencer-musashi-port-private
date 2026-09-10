/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E588,8013E5E8).
 * Offset 0x16430 at overlay base 80128158. SHA256(span)=c1974355bf39c1011caca22fc657139cdaf70e8c2a54dc0f23ebdca2cd017883.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e588.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 func_800D0EC4(void);
extern void func_80141874();
extern void (*D_8011DB24)();
extern s8 D_800B9A15;
extern s8 D_800B9A13;
extern u8 D_80115110[];
extern s16 D_80115112;

/* HAND MODEL of func_8013E588 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): void (void), O2 frame.
 * When func_800D0EC4() returns 0, stamps the init pattern
 * (D_800B9A15 = 1, D_800B9A13 = 2, D_80115110 word = 1,
 * D_80115112 = 0) and vectors D_8011DB24 to func_80141874.
 * Global decl shapes mirror staging/hand/func_8013E958.c (s8,
 * u8[], s16; D_800B9A13 is sb like its B9A15 sibling). Void: no
 * result is produced. */
void func_8013E588(void)
{
    if (func_800D0EC4() == 0) {
        D_800B9A15 = 1;
        D_800B9A13 = 2;
        *(u16 *)D_80115110 = 1;
        D_80115112 = 0;
        D_8011DB24 = func_80141874;
    }
}
