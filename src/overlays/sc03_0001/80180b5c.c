/* sc03_0001 func_80180B5C: own C written from the retail words (no upstream
 * definition). Verified byte-exact against retail by tools/verify_registry.py.
 * Types and signatures are whatever reproduces the bytes; they are not
 * evidence of the original declaration. */
#include "psx_types.h"

extern void func_8012E8E0(u8 *obj, void *a1);
extern void func_8012E88C(u8 *obj);
extern void func_8012A828(u8 *obj, void *a1);
extern void func_80187750(u8 *obj);
extern void func_80187994(u8 *obj, void *a1, s32 a2, s32 a3);
extern u8 D_801919AC[];
extern u8 D_801C3B38[];
extern u8 D_801B92EC[];

void func_80180B5C(u8 *obj) {
    *(s16 *)(obj + 2) = 2;
    func_8012E8E0(obj, D_801919AC);
    func_8012E88C(obj);
    func_8012A828(obj, D_801C3B38);
    func_80187750(obj);
    func_80187994(obj, D_801B92EC, 0, 0x60);
}
