/* sc03_0001: func_80180078 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct {
    u8 unk00[0x16];
    s16 unk16;
    u8 unk18[4];
    s32 unk1C;
    u8 unk20[4];
} Ent_8017D6EC;
extern void func_8017E204(void *arg0);
extern u8 D_80078EB1;
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
void func_8017F258(s32 arg0);
extern s32 D_801EE950[];
void func_8017FC00(void);

void func_80180078(void)
{
    extern u8 D_80078EB0;
    extern u8 D_80078EB1;
    extern s32 D_801EEAEC[];
    extern s32 D_801EF2DC;
    extern s32 D_801EE950[];
    extern void func_8017F258(s32 arg0);
    extern void func_8017FC00(void);
    s32 i;
    s32 mask;
    s32 *ptr;
    i = 0;
    mask = 0x80000000;
    D_801EEAEC[0] = D_80078EB1 * 60 + D_80078EB0;
    ptr = D_801EE950;
    while (i < 6) {
        *(s32 *)(*ptr + 4) |= mask;
        ptr++;
        i++;
    }
    for (i = 2; i < 18; i++) {
        func_8017F258(i);
    }
    func_8017FC00();
    if (D_801EF2DC != 0) {
        D_801EF2DC = D_801EF2DC - 1;
    }
}
