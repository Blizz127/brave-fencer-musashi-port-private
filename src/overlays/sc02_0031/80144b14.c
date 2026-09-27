/* Complete SC02 retail span [80144B14,80144B9C).
 * Matched C: Druthulu shared ov/func_80144B14.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern u16 D_80126B5E;
extern u16 D_80126B66;
extern u16 D_80126B62;
extern s32 func_80013294(void *a0, void *a1);

s32 func_80144B14(s32 obj) {
    u16 local_buf1[3];
    u16 local_buf2[3];
    s32 call_result;

    local_buf1[0] = *(u16 *)((char *)obj + 0x6);
    local_buf1[1] = *(u16 *)((char *)obj + 0xA);
    local_buf1[2] = *(u16 *)((char *)obj + 0xE);
    local_buf2[0] = D_80126B5E;
    local_buf2[1] = D_80126B62;
    local_buf2[2] = D_80126B66;
    call_result = func_80013294(local_buf1, local_buf2);
    if (call_result < *(s16 *)((char *)obj + 0xFC)) {
        return *(s32 *)((char *)obj + 0xCC);
    }
    return 0;
}
