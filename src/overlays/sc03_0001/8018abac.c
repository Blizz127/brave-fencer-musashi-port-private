/* sc03_0001: func_8018ABAC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018A3A8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8014B2A8(void);
extern void func_8014B944(s32 a0, s32 a1, s32 a2);
extern void func_8014BB24(s32 a0, s32 a1, s32 a2);
extern void func_8014BD24(s32 a0, s32 a1);
extern s32 func_801399F0(s32);
extern s32 func_801399F0(s32 a0);
extern s32 func_801621CC(s32 arg0);
extern void func_801622C4(void);
extern void func_8012A568(void (*a0)(void));
extern short D_800B9A02;
extern s16 D_800B9A02;
extern int func_8001AAA0(void);
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern s16 D_800B9A02;
extern s32 D_801151D0;
extern u16 D_801EF1EC;
extern s16 D_801EF1F0;
extern int func_8001AAA0(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80137B80(void);
extern s32 func_801376E8(s32 a0, s32 a1);
extern void func_80139954(void);
extern s32 func_801399F0(s32 a0);
extern s16 func_8014168C(s16 a0);
extern void func_8018B238(void);
extern s16 func_8014168C(s16 a0);
extern void func_8014BB24(s32 a0, s32 a1, s32 a2);
extern void func_8014B944(s32 a0, s32 a1, s32 a2);
extern void func_8014B2A8(void);
extern void func_801F1A24(s32 a0);
extern void func_8014BD24(s32 a0, s32 a1);
extern void func_8018C960(void);
extern s32 func_801621CC(s32 arg0);
extern void func_801622C4(void);
extern void func_80139954(void);
extern void func_8018B238(void);
extern void func_80137B80(void);
extern s32 func_801376E8(s32 a0, s32 a1);
extern int func_8001AAA0(void);
extern s32 func_801399F0(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
void func_8018B238(void);

void func_8018ABAC(void)
{
    extern s32 D_80126B58;
    extern u8 D_801151C8[];
    extern s16 D_801EF1E8;
    extern s16 D_801C17F4[];
    extern u8 D_800B9A15;
    extern u16 D_80115112;
    extern s32 D_801EF1E0;
    extern s32 D_801F437C;
    extern s32 D_80115130;
    extern s32 D_801C17F0;
    extern s16 D_801EF270;
    extern s32 D_801EF1E4;
    extern u16 D_8011511A;
    s16 s0;
    s32 s1;
    s32 s2;
    s32 base;
    s32 pad[2];
    (void)&pad;
    D_801151D0 = *(s32 *)&D_801151C8[(u16)D_800B9A02 * 4];
    base = (s32)&D_80126B58;
    if (D_801EF1E8 != 0) {
        D_801EF1E8 = D_801EF1E8 - 1;
        s0 = func_8014168C((s16)D_8011511A);
        if ((s16)s0 != 3) {
            s2 = 8;
            s1 = 0x3E7;
        } else {
            s2 = 3;
            s1 = 0x18;
        }
        if (D_801EF1E8 >= 0x3F) {
            if ((s16)D_801EF1EC != 0xFF) {
                D_801EF1EC += 0x10;
                if ((s16)D_801EF1EC >= 0x100) {
                    D_801EF1EC = 0xFF;
                }
            } else {
                D_801EF1F0 = *(u16 *)&D_801EF1F0 + 0x10;
                if (D_801EF1F0 >= 0x100) {
                    D_801EF1F0 = 0xFF;
                }
            }
        } else {
            if (D_801EF1E8 < 0x20) {
                if (D_801EF1F0 != 0) {
                    D_801EF1F0 -= 0x10;
                    if ((s16)D_801EF1F0 < 0) {
                        D_801EF1F0 = 0;
                    }
                } else {
                    D_801EF1EC -= 0x10;
                    if ((s16)D_801EF1EC < 0) {
                        D_801EF1EC = 0;
                    }
                }
            } else if (D_801EF1E8 == 0x30) {
                s0 = (s16)s0;
                func_8014BB24(base, D_801C17F4[s0], 1);
                func_8014B944(base, 0x1000000, 1);
                if (s0 == 2) {
                    func_8014B2A8();
                }
                func_801F1A24(s2);
                func_8014BD24(base, s1);
            }
        }
        func_8018C960();
        if (D_801EF1E8 == 0) {
            if (func_801621CC(s2) != 0) {
                func_801622C4();
                func_80139954();
                D_800B9A15 = 0;
                D_80115112 = 4;
                return;
            }
        }
    } else {
        if (D_801EF1E0 == 0) {
            D_801EF1E0 = (s32)&D_801F437C;
            D_80115130 = (s32)&D_801F437C;
            func_80139954();
            D_801EF1E4 = func_801376E8(D_801EF1E0, (s32)&D_801C17F0);
            if (D_801EF270 != 0) {
                ((s32 (*)(s32))func_8001AAA0)(0x16);
            }
        } else {
            if (func_801399F0(D_801EF1E4) != 0) {
                D_801EF1E0 = 0;
                func_8002D4C8(0x46F, 0);
                D_8011511A = 0;
                D_80115112 = 2;
            }
        }
    }
    func_8018B238();
    func_80137B80();
}
