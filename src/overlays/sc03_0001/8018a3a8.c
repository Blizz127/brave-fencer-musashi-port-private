/* sc03_0001: func_8018A3A8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018A3A8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80029124(s32, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80029124(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_801399F0(s32);
extern s32 func_801399F0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern short D_800B9A02;
extern s16 D_800B9A02;
extern int func_8001AAA0(void);
extern s32 func_8017ADE8(s32 a0);
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern s16 D_801EEB10;
extern s16 D_800B9A02;
extern s32 D_801151D0;
extern s16 D_80115126;
extern u8 D_80115138[];
extern u8 D_80115148[];
extern u16 D_801EF1EC;
extern s16 D_801EF1F0;
extern s16 D_801EF274;
extern s16 D_801EF278;
extern s16 D_801EF27C;
extern s16 D_801EF280;
extern s16 D_801EF284;
extern s16 D_801EF288;
extern s16 D_801EF28C;
extern s32 D_801EF258;
extern s16 D_801EEB10;
extern s32 D_801F4334;
extern s32 D_801F0D18;
extern s32 D_801F1374;
extern u8 D_801C1884[];
extern s32 D_801C184C[];
extern s32 D_800A654C;
extern s32 func_8005C49C(void);
extern int func_8001AAA0(void);
extern s32 func_800149E0(s32 a0);
extern void func_80029124(s32, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80137B80(void);
extern s32 func_801376E8(s32 a0, s32 a1);
extern void func_80139954(void);
extern void func_80139A68(s32 a0, u16 a1);
extern s32 func_801399F0(s32 a0);
extern s16 func_8014168C(s16 a0);
extern s32 func_8017ADE8(s32 a0);
extern void func_8018B238(void);
extern s32 func_8018C000(s32 a0, s16 a1);
extern s16 func_8018C914(s32 a0);
void func_8018B238(void);

void func_8018A3A8(void) {
    extern u8 D_801151C8[];
    extern s16 D_801EF1E8;
    extern u8 D_800B9A15;
    extern u16 D_80115112;
    extern s32 D_801EF1E0;
    extern s32 D_80115130;
    extern s32 D_801C17F0;
    extern s16 D_801EF270;
    extern s32 D_801EF1E4;
    extern u16 D_8011511A;
    s32 s0;
    s32 pad[2];
    (void)&pad;
    D_801151D0 = *(s32 *)&D_801151C8[(u16)D_800B9A02 * 4];
    if (D_80115126 == 4) {
        if (func_801399F0(D_801EF1E4) != 0) {
            if (D_80115148[0] == 0) {
                if (D_801EF1E0 == (s32)&D_801F4334) {
                    D_801EF1E8 = 0x60;
                    D_801EF1F0 = 0;
                    D_801EF1EC = 0;
                    D_801EF1E0 = 0;
                    if (D_800A654C == 0x16) {
                        D_801EF270 = 1;
                        ((s32 (*)(s32))func_8001AAA0)(0x35);
                    } else {
                        D_801EF270 = 0;
                    }
                    D_80115112 = 6;
                } else {
                    D_80115112 = D_80115112 - 1;
                }
            } else {
                D_801EF1E0 = 0;
                func_8017ADE8(0x12);
                func_8002D4C8(0x46F, 0);
                D_8011511A = 0;
                D_80115112 = D_80115112 - 1;
            }
            if (D_801EF1E0 != 0) {
                D_80115130 = D_801EF1E0;
                func_80139954();
                D_801EF1E4 = func_801376E8(D_801EF1E0, (s32)&D_801C17F0);
            }
        }
    } else if (D_80115126 == 5) {
        if (D_801EF1E0 != 0) {
            if ((D_801EF28C = func_801399F0(D_801EF1E4)) != 0) {
                D_801EF1E0 = 0;
            }
        } else if ((func_800149E0(0) & 0x50) != 0 || D_801EF28C > 0) {
            switch (D_801EF274) {
            case 0:
                D_801EF274 = -1;
                break;
            case 1:
                if (D_801EF28C < 0) {
                    D_801EF1E0 = (s32)&D_801F0D18;
                } else if (D_801EF28C == 1) {
                    u16 *p = &D_80115112;
                    D_801EEB10 = 1;
                    func_80139954();
                    D_800B9A15 = 0;
                    *p = *p + 1;
                } else {
                    D_801EF274 = -2;
                }
                break;
            case 2:
                D_801EF288 = 0;
                D_801EF278 = 0;
            case 5:
            case 6:
                D_801EF274 = ((u16)D_801EF274 + 1) | 0x100;
                break;
            case 3:
                if (D_801EF28C == 1) {
                    D_801EF274 = (u16)D_801EF274 + 1;
                    if (D_801EF288 == 0) {
                        if (func_8018C914(-0xA) != 0) {
                            func_8002D4C8(0x472, 0);
                            D_801EF274 = 0x10C;
                            break;
                        }
                        func_8002D4C8(0x5EE, 0);
                        D_801EF278 = 0;
                        D_801EF288 = 0;
                        D_801EF27C = func_8005C49C() % 9 + 3;
                        func_80139A68(D_801EF27C, 0);
                    } else {
                        func_80139A68(D_801EF27C, 0);
                        D_801EF274 = 0x106;
                        break;
                    }
                }
                D_801EF274 = ((u16)D_801EF274 + 1) | 0x100;
                break;
            case 4:
            case 12:
            case 13:
                if (D_801EF278 != 0) {
                    func_8018C914(D_801EF278);
                    func_8002D4C8(0x5EE, 0);
                }
                D_801EF274 = -1;
                break;
            case 7:
                D_801EF284 = (u16)D_801EF28C - 1;
                D_801EF280 = func_8005C49C() % 13 + 1;
                func_80139A68(D_801EF280, 0);
                D_801EF274 = ((u16)D_801EF274 + 1) | 0x100;
                break;
            case 8:
            case 9:
                if (D_801EF27C == D_801EF280) {
                    D_801EF280 = func_8005C49C() % 13 + 1;
                    func_80139A68(D_801EF280, 0);
                    D_801EF274 = 0x109;
                    break;
                }
                if (D_801EF284 == 0 ? D_801EF27C < D_801EF280 : D_801EF280 < D_801EF27C) {
                    if (D_801EF278 == 0) {
                        D_801EF278 = 0xA;
                    }
                    D_801EF278 = (u16)D_801EF278 * 2;
                    func_80139A68(D_801EF278, 0);
                    func_8002D4C8(0x5EE, 0);
                    if (D_801EF278 >= 0x2800) {
                        func_80029124(0x11A, 1);
                        D_801EF274 = 0x10D;
                        *(s32 *)(D_801EF258 + 4) = (s32)&D_801F1374;
                    } else {
                        s32 r;
                        D_801EF288 = (u16)D_801EF288 + 1;
                        s0 = D_801C1884[D_801EF288];
                        r = func_8005C49C() % (9 - s0 * 2);
                        s0 = s0 + 3;
                        D_801EF27C = r + s0;
                        func_80139A68(D_801EF278, 0);
                        D_801EF274 = 0x10A;
                    }
                } else {
                    D_801EF278 = 0;
                    D_801EF288 = 0;
                    D_801EF274 = 0x10B;
                    func_8002D4C8(0xC62, 0);
                }
                break;
            case 10:
            case 11:
                D_801EF274 = 0x103;
                break;
            }
            if (D_801EF274 < 0) {
                func_8017ADE8(0xA);
                if (D_801EF274 == -1) {
                    func_8002D4C8(0x46F, 0);
                }
                {
                    u16 *p = &D_80115112;
                    D_801EF274 = 0;
                    *p = *p - 1;
                }
            }
            if (D_801EF274 >= 0x100) {
                s32 t = D_801EF274 & 0xFF;
                D_801EF274 = t;
                D_801EF1E0 = D_801C184C[t];
            }
            if (D_801EF1E0 != 0) {
                D_80115130 = D_801EF1E0;
                func_80139954();
                D_801EF1E4 = func_801376E8(D_801EF1E0, (s32)&D_801C17F0);
            }
        }
    } else {
        if (D_801EF1E0 != 0) {
            if (func_801399F0(D_801EF1E4) != 0) {
                D_801EF1E0 = 0;
            }
        } else if ((func_800149E0(0) & 0x50) != 0) {
            u16 idx = D_8011511A;
            if (D_80115138[idx] == 8) {
                func_8018C000(0xF, func_8014168C((s16)idx));
            }
            if (D_801EEB10 != 0) {
                func_80139954();
                D_800B9A15 = 0;
                func_8002D4C8(0x474, 0);
                D_80115112 = D_80115112 + 1;
            } else {
                func_8002D4C8(0x46F, 0);
                D_80115112 = D_80115112 - 1;
            }
        }
    }
    func_8018B238();
    func_80137B80();
}
