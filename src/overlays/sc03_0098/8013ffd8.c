/* sc03_0098: func_8013FFD8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8013FFD8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern s32 func_80029178(s32);
extern short D_80115128;
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern short D_80115128;

s32 func_8013FFD8(s16 arg0, s32 arg1, s32 *arg2) {
    extern u8 D_801863BC[];
    extern s16 D_801863D4;
    extern u8 D_801863E0[];
    extern u8 D_801863E7[];
    extern u8 D_801863E8[];
    extern unsigned char D_80186310[];
    extern unsigned short D_80186328[];
    extern M2C_UNK D_801862E4;
    extern s32 D_801862F8[];
    extern s32 D_80186368;
    extern u8 D_8018636C;
    extern u8 *D_80186378;
    extern s32 D_8010F3C4[];
    extern s32 D_8010EDE8[];
    extern u8 D_80115143;
    extern void * D_801C42D4;
    extern void * D_801C42D0;
    s32 ret;
    *arg2 = 0x808080;
    ret = 0;
    switch (arg0) {
    case 0: {
        s16 s0 = (s16) arg1;
        if (s0 < 6) {
            if ((((s32 (*)(u8))func_80029178)(D_801863BC[s0]) & 0xFF) == 0) {
                return 1;
            }
            ret = ((s32 *)D_80186310)[s0];
        }
        break;
    }
    case 1: {
        s16 v1 = (s16) arg1;
        if (v1 < 4) {
            ret = ((s32 *)D_80186328)[v1];
        }
        break;
    }
    case 2:
        switch ((*(s16 *)&D_80115128)) {
        case 0: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_801862E4)[v1];
            }
            break;
        }
        case 1: {
            s16 v1 = (s16) arg1;
            if (v1 < 0xC) {
                s32 v3 = ((s32 (*)(u8, s32))func_800291B4)(((u8 *)&D_801863D4)[v1], arg1) & 0xFF;
                if (v3 == 0) {
                    return 1;
                }
                ret = D_8010EDE8[v3 * 3];
            }
            break;
        }
        case 2: {
            s16 s0 = (s16) arg1;
            if (s0 < 6) {
                if ((((s32 (*)(u8))func_80029178)((*(u8 * *)&D_801C42D4)[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = (*(s32 * *)&D_801C42D0)[s0];
            }
            break;
        }
        case 3: {
            s16 s0 = (s16) arg1;
            if (s0 < 6) {
                if ((((s32 (*)(u8))func_80029178)(D_801863E0[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = D_801862F8[s0];
            }
            break;
        }
        case 4: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_80186378)[v1];
            }
            break;
        }
        }
        break;
    case 3: {
        s16 t = (s16) arg1;
        if (t <= 0) {
            s16 s0 = t + D_80115143;
            if (s0 != 0) {
                if ((((s32 (*)(u8, s32))func_800291B4)(D_801863E7[s0], arg1) & 0xFF) == 0) {
                    *arg2 = 0x804040;
                }
                ret = D_8010F3C4[s0];
            } else {
                ret = D_80186368;
            }
        }
        break;
    }
    case 5: {
        s16 v1 = (s16) arg1;
        if (v1 < 3) {
            ret = ((s32 *)&D_8018636C)[v1];
        }
        break;
    }
    case 6: {
        s16 s0 = (s16) arg1;
        if (s0 < 0x28) {
            s32 idx;
            if ((((s32 (*)(u8, s32))func_800291B4)(D_801863E8[s0], arg1) & 0xFF) == 0) {
                *arg2 = 0x804040;
            }
            idx = s0 + 1;
            ret = D_8010F3C4[idx];
        }
        break;
    }
    case 7: {
        s16 v1 = (s16) arg1;
        if (v1 < 5) {
            ret = ((s32 *)&D_80186378)[v1];
        }
        break;
    }
    }
    return ret;
}
