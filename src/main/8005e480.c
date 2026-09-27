/* Main-exec range [8005E480,8005E528) from the SLUS executable.
 * SHA256(span)=0ab6ac47cacf1cbe608fdab47f3dbedb2cc8f1ada2b65bfc9325e1579dddbdaf.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005EA68(u8);                          /* static */
void func_8005EA88(u8);                          /* static */
void func_8005EAA8(u8);                          /* static */
void func_8005EAC8();                            /* static */

void func_8005E480(void *arg0) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x46);
    switch (temp_v1) {                              /* irregular */
    case 2:
        func_8005EA68(M2C_FIELD(arg0, u8 *, 0x47));
        return;
    case 3:
        func_8005EA88(M2C_FIELD(arg0, u8 *, 0x47));
        return;
    case 4:
        if (M2C_FIELD(arg0, u8 *, 0x48) == 0) {
            func_8005EAA8(M2C_FIELD(arg0, u8 *, 0x47));
            return;
        }
        func_8005EAC8();
        return;
    }
}
