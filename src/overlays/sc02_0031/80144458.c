/* Complete SC02 retail span [80144458,80144558).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void func_80016714(void *a0, s32 a1);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern s32 D_8018659C;

void func_80144458(void *arg0) {
    s32 temp_s0;
    void *temp_s2;
    void *temp_v0;
    s32 obj = (s32)arg0;

    temp_s2 = *(void **)(obj + 0xCC);
    if (*(s16 *)(obj + 0x70) == 0) {
        temp_v0 = *(void **)(*(s32 *)(obj + 0x64) + 0x20);
        if (temp_v0 != 0) {
            temp_s0 = (*(s16 *)((s32)temp_v0 + 0x12) - 0x400) & 0xFFF;
            *(s32 *)(obj + 0x10) = func_80047948(temp_s0) * D_8018659C * 0x10;
            *(s32 *)(obj + 0x18) = func_8004787C(temp_s0) * -D_8018659C * 0x10;
            func_8012AD80(obj);
        }
    }
    *(u16 *)((s32)temp_s2 + 8) = *(u16 *)(obj + 6);
    *(u16 *)((s32)temp_s2 + 0xA) = *(u16 *)(obj + 0xA);
    *(u16 *)((s32)temp_s2 + 0xC) = *(u16 *)(obj + 0xE);
    if (func_80128ED8((s32)temp_s2, (s32 *)(obj + 0xD0)) != 0) {
        func_80016714(temp_s2, 0x38);
        func_8012C218(arg0);
    }
}
