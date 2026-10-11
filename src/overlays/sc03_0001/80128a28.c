/* sc03_0001: func_80128A28 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern u16 D_800B99F6;
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern u16 D_800B99F6;
extern s16 D_800B9A00;
extern M2C_UNK (*D_8018D4D8)();
extern s16 (*D_8018D4DC)();

void func_80128A28(void) {
    s16 temp_v0;
    switch (D_800B99F6) {
    case 1:
        D_8018D4D8();
    case 0:
        func_80011C10();
        return;
    case 2:
        temp_v0 = D_8018D4DC();
        if (temp_v0 != 0) {
            if (temp_v0 < 0) {
                func_80011B7C(0);
                D_800B9A00 = 1;
                return;
            }
            func_80010DE0();
        } else {
            return;
        }
        break;
    }
}
