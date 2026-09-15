/* Native retail instruction export [8005D8B4,8005D980).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072960();                               /* static */
extern s32 D_80072990;
extern s32 D_80072994;
extern s32 D_800729BC;
void func_8005CF08();                            /* static */
void func_8005CF18();                            /* static */
void func_8005CF58(s32, s32);            /* static */
void func_8005E168(s32, void *);          /* static */
void func_8005E178(s32, void *);          /* static */
extern s32 *D_80078988;
extern s32 *D_80078998;

void func_8005D8B4(void) {
    D_80072994 = 0;
    func_8005CF08();
    func_8005E178(2, &D_80078988);
    func_8005E168(2, &D_80078988);
    M2C_FIELD(D_800729BC, s32 *, 0) = -2;
    M2C_FIELD(D_800729BC, s32 *, 4) = (s32) (M2C_FIELD(D_800729BC, s32 *, 4) | 1);
    func_8005CF58(3, 0);
    func_8005CF18();
    D_80072960(D_80072990);
    D_80072960(D_80072990 + 0xF0);
    M2C_FIELD(&D_80078998, s32 *, 4) = 0;
    M2C_FIELD(&D_80078998, s32 *, 0) = 0;
    D_80072994 = 1;
}
