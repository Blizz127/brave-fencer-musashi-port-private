/* sc02_0037: func_80128A28 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011C10(void);
extern void func_80011B7C(int);
extern void func_80011C10(void);

void func_80128A28(void) {
    extern u16 D_800B99F6;
    extern s16 D_800B9A00;
    extern M2C_UNK (*D_80183BE0)();
    extern s16 (*D_80183BE4)();
    s16 temp_v0;
    switch (D_800B99F6) {
    case 1:
        D_80183BE0();
    case 0:
        func_80011C10();
        return;
    case 2:
        temp_v0 = D_80183BE4();
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
