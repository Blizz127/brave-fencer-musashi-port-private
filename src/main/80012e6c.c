#include "psx_types.h"

s16 func_80012E6C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 *arg4) {
    s16 temp_a1;
    s16 var_a0;
    s16 var_v0;
    s16 var_v1;
    s32 var_v0_2;
    s32 var_v0_3;

    temp_a1 = arg1 - arg0;
    var_v1 = temp_a1;
    var_a0 = var_v1;
    if ((*arg4 == 0) || (arg2 == 0)) {
        var_v0_2 = var_a0 << 0x10;
        if (temp_a1 >= 0x801) {
            var_a0 = temp_a1 - 0x1000;
            var_v0_2 = var_a0 << 0x10;
        }
        if ((var_v0_2 >> 0x10) < -0x800) {
            var_a0 += 0x1000;
        }
        return var_a0;
    }
    var_v0_3 = var_v1 << 0x10;
    if (temp_a1 >= 0x801) {
        var_v1 = temp_a1 - 0x1000;
        var_v0_3 = var_v1 << 0x10;
    }
    if ((var_v0_3 >> 0x10) < -0x800) {
        var_v1 += 0x1000;
    }
    var_v0 = (s16) ((s32) (var_v1 * arg3) / arg2);
    if (var_v0 == 0) {
        var_v0 = -1;
        if (temp_a1 > 0) {
            var_v0 = 1;
        }
    }
    return var_v0;
}
