/* Complete SC02 retail span [80146F58,80146FC4).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s16 func_8012A68C(void);
extern s16 func_8012A758(void);
extern void func_8004978C(s16 *a0, void *a1);
extern void ApplyMatrixSV(void *a0, void *a1, void *a2);

void func_80146F58(s32 a0, s32 a1) {
    s16 vec[3];
    u8 mat[0x20];

    vec[0] = func_8012A68C();
    vec[1] = func_8012A758();
    vec[2] = 0;
    func_8004978C(vec, mat);
    ApplyMatrixSV(mat, (void *)a0, (void *)a1);
}
