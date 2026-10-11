/* sc03_0001: func_80128AF4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
typedef s32 M2C_UNK;
extern u16 D_800B99F6;
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern void func_8002AEF8(void);
extern void func_800CFBBC(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern u16 D_800B99F6;
extern u16 D_800B99F6;
extern M2C_UNK (*D_8018D4E4)();
extern s32 (*D_8018D4E8)();
extern s32 D_801ED340;

void func_80128AF4(void) {
    switch (D_800B99F6) {
    case 0:
        D_801ED340 = func_8002AF08();
        func_80011C10();
        return;
    case 1:
        D_8018D4E4();
        func_80011C10();
        return;
    case 2:
        if ((D_8018D4E8() << 0x10) != 0) {
            if (D_801ED340 == 1) {
                if (func_800CFBE8() != 0) {
                    func_800CFBBC();
                    func_80011B7C(0x13);
                } else {
                    func_80011B7C(4);
                }
            } else {
                func_80010DE0();
            }
            func_8002AEF8();
        }
        return;
    }
}
