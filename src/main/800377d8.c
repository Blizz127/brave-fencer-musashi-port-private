/* Complete retail callback [800377D8,80037CC8). C recovery remains unmatched. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003C438(void *, s16);                          /* static */
s32 func_8003C498(s32);                             /* static */
s32 func_8003C4F0();                               /* static */
s32 func_80043994(void *, s32);                          /* static */
s32 func_80043B1C(void *);                             /* static */
extern u8 D_8006AEF4;
extern void *D_80076228;
extern s32 D_80076238;
extern s32 D_8007623C;
extern s16 D_80076240;
extern u8 D_80076242;
extern u8 D_80076243;
extern s32 *D_80076244;
extern s32 *D_80076248;
extern s32 *D_8007624C;
extern s32 *D_80076250;
extern s32 *D_80076251;
extern s32 D_80076294;
extern s8 D_80076298;
extern s32 *D_800762A0;

void func_800377D8(s32 arg0) {
    s16 temp_v1;
    s16 temp_v1_5;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_6;
    s32 temp_v1_7;
    u8 var_v0;

    temp_s1 = arg0 & 0xFF;
    if ((temp_s1 == 1) && (func_80043994(&D_800762A0, 3) != 0) && (temp_v0 = func_80043B1C(&D_800762A0), (temp_v0 == D_8007623C))) {
        D_8007623C = temp_v0 + 1;
        switch (D_80076243) {                       /* irregular */
        default:
            if (D_80076243 != temp_s1) {
                return;
            }
            if (func_80043994(D_80076228, 0x200) != 0) {
                if ((D_80076240 == 0) && (D_80076228->unk0 != 0x7671732E)) {
                    D_80076298 = 1;
                    *(&D_80076250 + (D_80076294 * 0x10)) = 2;
                    goto block_39;
                }
                temp_v1 = (u16) D_80076240 + 1;
                D_80076240 = temp_v1;
                D_80076228 += 0x800;
                if (temp_v1 == 0xE) {
                    temp_v1_2 = D_80076294 * 0x10;
                    if (*(&D_80076248 + temp_v1_2) & 0x1000) {
                        *(&D_80076250 + temp_v1_2) = 1;
                        temp_v1_3 = D_80076294 + 1;
                        D_80076294 = temp_v1_3;
                        temp_v1_4 = temp_v1_3 * 0x10;
                        if ((temp_v1_3 < 5) && (*(&D_80076251 + temp_v1_4) != 0)) {
                            if (*(&D_80076248 + temp_v1_4) & 0x2000) {
                                D_80076243 = 1;
                            } else {
block_35:
                                D_80076243 = 2;
                            }
block_36:
                            D_80076298 = 0;
                            D_80076240 = 0;
                            temp_v0_2 = D_80076294 * 0x10;
                            D_80076228 = *(&D_80076244 + temp_v0_2);
                            D_80076238 = *(&D_8007624C + temp_v0_2);
                            return;
                        }
                        D_80076243 = 4;
                        var_v0 = D_8006AEF4 & 0xFD;
                        goto block_43;
                    }
                    D_80076243 = 2;
                    D_80076240 = 0;
                    return;
                }
            } else {
                goto block_39;
            }
            break;
        case 2:
            if (func_80043994(D_80076228, 0x200) != 0) {
                temp_v1_5 = (u16) D_80076240 + 1;
                D_80076240 = temp_v1_5;
                D_80076228 += 0x800;
                if (temp_v1_5 == 7) {
                    D_80076243 = 3;
                    D_80076240 = 0;
                    if ((D_80076242 != 0) && (func_8003C4F0(0) != 0)) {
                        D_80076242 = 0;
                        return;
                    }
                }
            } else {
                goto block_39;
            }
            break;
        case 3:
            if ((func_80043994(D_80076228, 0x200) != 0) && ((D_80076240 = (u16) D_80076240 + 1, (D_80076242 == 0)) || (func_8003C4F0(0) != 0)) && (func_8003C498(D_80076238) != 0)) {
                if (D_80076240 == D_80076228->unk-4) {
                    func_8003C438(D_80076228, D_80076228->unk-2);
                    D_80076242 = 1;
                    D_8006AEF4 |= 1;
                    *(&D_80076250 + (D_80076294 * 0x10)) = 1;
                    temp_v1_6 = D_80076294 + 1;
                    D_80076294 = temp_v1_6;
                    temp_v1_7 = temp_v1_6 * 0x10;
                    if ((temp_v1_6 < 5) && (*(&D_80076251 + temp_v1_7) != 0)) {
                        if (*(&D_80076248 + temp_v1_7) & 0x2000) {
                            D_80076243 = 1;
                        } else {
                            goto block_35;
                        }
                        goto block_36;
                    }
                    D_80076243 = 4;
                    var_v0 = D_8006AEF4 & 0xFD;
                    goto block_43;
                }
                func_8003C438(D_80076228, 0x800);
                D_80076242 = 1;
                D_8006AEF4 |= 1;
                D_80076238 += 0x800;
                return;
            }
            goto block_39;
        }
    } else {
block_39:
        if ((D_80076243 != 0) && (D_80076243 != 4) && (D_80076243 != 5)) {
            D_80076243 = 5;
            var_v0 = D_8006AEF4 & 0xFD;
block_43:
            D_8006AEF4 = var_v0;
        }
    }
}
