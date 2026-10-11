/* sc03_0001: func_8018B644 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018A3A8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 func_800291B4(s32 arg);

s32 func_8018B644(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    extern s32 func_800291B4(s32 arg);
    extern u8 D_80115140[];
    extern u8 D_80115158[];
    extern u8 D_80115159[];
    extern u8 D_8018E5C0[];
    extern u8 D_801EF290[];
    extern u8 D_801EF298[];
    extern s32 D_8010EDE8[];
    extern s32 D_8010F468[];
    extern s32 D_801C12E8;
    register s32 zr __asm__("$0");
    s32 ret;
    s32 n;
    s32 mode;
    *arg4 = 0x808080;
    n = D_80115159[(s16)arg2 * 2];
    n = n * D_80115158[(s16)arg2 * 2];
    ret = 0;
    mode = arg1 + zr;
    switch ((s16)arg1) {
    case 10:
    case 11:
    case 13: {
        s32 j = arg3 + D_80115140[(s16)arg2];
        if ((s16)arg3 < 6 && (s16)j < (s16)n) {
            ret = ((s32 *)arg0)[(s16)j];
        }
        break;
    }
    case 12: {
        s32 j = arg3 + D_80115140[(s16)arg2];
        if ((s16)arg3 < 6 && (s16)j < (s16)n) {
            ret = ((s32 *)arg0)[D_801EF290[(s16)j]];
        }
        break;
    }
    case 7:
    case 8: {
        s16 v1 = (s16)arg3;
        if (v1 < 0xC) {
            s32 t = func_800291B4(D_8018E5C0[v1]) & 0xFF;
            if (t == 0) {
                return 1;
            }
            ret = D_8010EDE8[t * 3];
        }
        break;
    }
    case 14: {
        s32 j = arg3 + D_80115140[(s16)arg2];
        if ((s16)arg3 < 6 && (s16)j < (s16)n) {
            s32 k = D_801EF298[(s16)j];
            s32 c = k + 0x63;
            if (k < 0 || (func_800291B4(c) & 0x40) == 0) {
                ret = D_801C12E8;
            } else {
                s32 e = k + 1;
                ret = D_8010F468[e * 2];
                n = func_800291B4(c);
                if (n & 0x20) {
                    *arg4 = 0x804040;
                }
            }
        }
        break;
    }
    default: {
        s32 v1 = (s16)arg3;
        s32 ok = ((s16)mode == 5) ? (v1 < 4) : (v1 < 3);
        if (ok) {
            ret = ((s32 *)arg0)[(s16)arg3];
        }
        break;
    }
    }
    return ret;
}
