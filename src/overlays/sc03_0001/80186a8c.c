/* sc03_0001 func_80186A8C: own C written from the retail words (no known
 * source definition). Verified byte-exact against retail by
 * tools/verify_registry.py. Types and signatures are whatever reproduces the
 * bytes; they are not evidence of the original declaration. */
#include "psx_types.h"

extern s32 func_8018727C(u8 *obj, void *a1);
extern s32 func_80029504(void);
extern void func_8012CAE4(u8 *obj);
extern void func_8012E8E0(u8 *obj, void *a1);
extern void func_80187750(u8 *obj);
extern void func_8012A828(u8 *obj, void *a1);
extern void func_8001C97C(void *a0);
extern s32 func_801788B8(u8 *obj, void *fn);
extern void func_80186C54();
extern u8 D_80192A6C[];
extern u8 D_80192A64[];
extern u8 D_801C3C90[];
extern u8 D_801EB318[];

void func_80186A8C(u8 *obj) {
    s32 v;
    s16 st;
    if (func_8018727C(obj, D_80192A6C) == 0) return;
    v = func_80029504();
    if (v < 30) {
        *(s16 *)(obj + 2) = 1;
    } else if (v < 70) {
        *(s16 *)(obj + 2) = 4;
    } else {
        func_8012CAE4(obj);
        return;
    }
    func_8012E8E0(obj, D_80192A64);
    func_80187750(obj);
    func_8012A828(obj, D_801C3C90);
    func_8001C97C(D_801EB318);
    *(s16 *)(*(u8 **)(obj + 0x68) + 0xC) = 0x7FFF;
    *(s32 *)(obj + 0xD4) = func_801788B8(obj, func_80186C54);
}
