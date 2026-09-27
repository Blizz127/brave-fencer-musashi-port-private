/* Main-exec range [80014ED4,80015018) from the SLUS executable.
 * SHA256(span)=fa729ec315e68ada62d4a44756399804b6de8911a3db7e2a3b039a4267d2755e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

#if defined(__mips__)
__asm__(
    ".set\tnoreorder\n"
    ".globl\tfunc_80014ED4\n"
    ".ent\tfunc_80014ED4\n"
    ".type\tfunc_80014ED4, @function\n"
    "func_80014ED4:\n"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end\tfunc_80014ED4\n"
    ".size\tfunc_80014ED4, .-func_80014ED4\n"
);
#else
void func_80015118(u16 *);
extern s32 *D_80078D98;

u16 func_80014ED4(s32 arg0) {
    u16 sp16;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 var_v1;
    u16 var_v0;
    u8 temp_v1_2;
    void *temp_v0;
    void *temp_v1;

    temp_v1 = ((arg0 & 0xFF) * 0x4C) + &D_80078D98;
    var_v0 = M2C_FIELD(temp_v1, u16 *, 0x3A);
    if ((var_v0 == 0) && ((temp_v1_2 = M2C_FIELD(temp_v1, u8 *, 0), (temp_v1_2 == 0x53)) || ((var_v0 = 0, (((s32) temp_v1_2 < 0x54) == 0)) && (var_v0 = 0, (temp_v1_2 == 0x73))))) {
        temp_v0 = ((arg0 & 0xFF) * 0x4C) + &D_80078D98;
        sp10 = (u16) M2C_FIELD(temp_v0, u8 *, 0x47);
        sp12 = (u16) M2C_FIELD(temp_v0, u8 *, 0x46);
        sp14 = (u16) M2C_FIELD(temp_v0, u8 *, 0x37);
        sp16 = (u16) M2C_FIELD(temp_v0, u8 *, 0x36);
        func_80015118(&sp10);
        func_80015118(&sp12);
        func_80015118(&sp14);
        func_80015118(&sp16);
        var_v1 = 0;
        if ((sp10 == 0x80) && (sp14 != sp10)) {
            var_v1 = 0x1000;
            if (sp14 >= 0x80U) {
                var_v1 = 0x4000;
            }
        }
        var_v0 = var_v1 & 0xFFFF;
        if (sp12 == 0x80) {
            if (sp16 != sp12) {
                if (sp16 < 0x80U) {
                    var_v1 |= 0x8000;
                } else {
                    var_v1 |= 0x2000;
                }
            }
            var_v0 = var_v1 & 0xFFFF;
        }
    }
    return var_v0;
}
#endif
