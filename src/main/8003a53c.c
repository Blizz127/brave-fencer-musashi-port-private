/* Exact retail word export for [8003A53C,8003A5B8); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (31/31 words at 0x8003A53C). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern s32 D_8006B0E0;
extern s32 D_8006B548;
extern s32 func_8003AA18;
void func_8003B14C(s32 (*)());                           
s32 func_8005CE78(s32, s32, s32, s32);                      
void func_8005CEB8(s32);                               
void func_8005CF08();                                  
void func_8005CF18();                                  

void func_8003A53C(void) {
    s32 temp_v0;

    if (D_8006B548 == 0) {
        D_8006B548 = 1;
        func_8005CF08();
        func_8003B14C(&func_8003AA18);
        temp_v0 = func_8005CE78(0xF0000009, 0x20, 0x2000, 0);
        D_8006B0E0 = temp_v0;
        func_8005CEB8(temp_v0);
        func_8005CF18();
    }
}
