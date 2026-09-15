/* Main-exec range [80060030,8006023C) from the SLUS executable.
 * SHA256(span)=52780858b9b83b963a62bcb4006cb989bc10a5b4ce17adcbf123d753828470f4.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8005FDD4;
void func_8006289C(void *);                   /* static */
extern s32 D_80078C30;
extern s32 D_80078C34;
extern s32 D_80078C38;

s32 func_80060030(u32 *arg0) {
    u32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 < 0x20U) {
        switch (temp_v1) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        case 0:
            D_80078C38 = 0;
            D_80078C34 = 0;
            D_80078C30 = 0;
            func_8006289C(&D_8005FDD4);
            *arg0 = 0xA;
            break;
        }
    }
    return 0;
}
