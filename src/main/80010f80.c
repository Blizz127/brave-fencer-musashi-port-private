/* Exact retail word export for [80010F80,800110CC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800CEEC8(void *);                   /* extern */
extern s32 D_800629C8;
void func_80011818();                     /* static */
void func_80011B7C();                     /* static */
void func_80015310();                            /* static */
void func_8001C044();                            /* static */
void func_80029514(s32);                         /* static */
extern s32 *D_80078E78;
extern s32 *D_800AF630;

void func_80010F80(void) {
    func_800CEEC8(&D_80078E78);
    if (M2C_FIELD(&D_800AF630, u16 *, 0xA3B6) != 0) {
        func_80011B7C(0);
        func_8001C044();
        func_80015310();
        if (M2C_FIELD(&D_800AF630, s16 *, 0xA3B8) == 4) {
            M2C_FIELD(&D_800AF630, s8 *, 0xA434) = 1;
            func_80011818(0xF);
            return;
        }
        if (M2C_FIELD(&D_800AF630, s16 *, 0xA3B8) < 2) {
            M2C_FIELD(&D_800AF630, s16 *, 0xA3D8) = 0x3005;
            M2C_FIELD(&D_800AF630, s16 *, 0xA3DA) = 0x3000;
            func_80029514(D_800629C8);
            if (M2C_FIELD(&D_800AF630, s16 *, 0xA3B8) == 1) {
                func_80011818(0xA);
                func_80011B7C(0xB);
                return;
            }
            func_80011818(0xA);
        }
    }
}
