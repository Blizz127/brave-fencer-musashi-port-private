/* sc03_0001: func_8017F804 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    u8 unk00[0x16];
    s16 unk16;
    u8 unk18[4];
    s32 unk1C;
    u8 unk20[4];
} Ent_8017D6EC;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8005C49C(void);
extern void func_8017E204(void *arg0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
extern s32 func_8005C49C(void);
void func_8017E204(void *arg0);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8005C49C(void);

void func_8017F804(s32 param_1) {
    extern u8 D_8019190C[][4];
    s32 i;
    s32 v1;
    s32 uVar1;
    if (func_8018766C(7, 0x13) == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (D_8019190C[*(s16 *)(param_1 + 0x100)][i] == *(s32 *)(param_1 + 0x1c)) {
            func_8012C658(0x140,
                          *(u8 *)(param_1 + 0xfc) | ((*(s16 *)(param_1 + 0xfe) << 8) & 0xff00),
                          param_1);
            break;
        }
    }
    if (func_8012BEE8(param_1) == 0) {
        return;
    }
    *(s32 *)(param_1 + 0x1c) = 0x50;
    uVar1 = func_8005C49C();
    v1 = *(u16 *)(param_1 + 0xfe) + (uVar1 & 0xf) - 7;
    v1 &= 0xff;
    *(u16 *)(param_1 + 0xfe) = v1;
    uVar1 = func_8005C49C();
    v1 = *(u16 *)(param_1 + 0xfc) + (uVar1 & 0xf) - 7;
    v1 &= 0xff;
    *(u16 *)(param_1 + 0xfc) = v1;
    uVar1 = func_8005C49C();
    *(s16 *)(param_1 + 0x100) = uVar1 % 7;
}
