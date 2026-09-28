s32 func_80013154(s16 arg0, s16 arg1, s32 arg2) {
    s16 var_v0_2;
    s32 temp_a3;
    s32 var_t0;
    s32 var_v0;

    var_t0 = arg2;
    if (arg0 == arg1) {
        return 0;
    }
    temp_a3 = arg1 < arg0;
    var_v0_2 = arg0 + var_t0;
    if (temp_a3 != 0) {
        var_t0 = -arg2;
        var_v0_2 = arg0 + var_t0;
    }
    if ((var_v0_2 >= arg1) && (temp_a3 == 0)) {
        var_v0 = (arg1 - arg0) << 0x10;
    } else {
        var_v0 = var_t0 << 0x10;
        if (arg1 >= var_v0_2) {
            if (arg0 >= arg1) {
                var_v0 = (arg1 - arg0) << 0x10;
            } else {
                var_v0 = var_t0 << 0x10;
            }
        }
    }
    return var_v0 >> 0x10;
}
