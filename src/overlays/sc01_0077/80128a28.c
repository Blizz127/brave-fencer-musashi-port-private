/* sc01_0077: func_80128A28 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_a.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
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
M2C_UNK func_80010DE0();
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern u16 D_800B99F6;
extern s16 D_800B9A00;
extern M2C_UNK (*D_80186AF0)();
extern s16 (*D_80186AF4)();

void func_80128A28(void) {
    s16 temp_v0;
    switch (D_800B99F6) {
    case 1:
        D_80186AF0();
    case 0:
        func_80011C10();
        return;
    case 2:
        temp_v0 = D_80186AF4();
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
