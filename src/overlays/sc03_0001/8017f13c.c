/* sc03_0001: func_8017F13C from Druthulu/BFM-decomp
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
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001D074(s32, s32);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_8012A568(void (*a0)(void));
extern void func_8017E204(void *arg0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
extern void func_8001D074(s32 a0, s32 a1);
extern void func_800233CC(void *a0, u16 a1);
extern void func_8001CD50(s32 a0, s32 a1);

void func_8017F13C(void) {
    extern s32 D_801EE950[];
    extern s32 D_801EE96C;
    s32 i;
    i = 0;
    do {
        D_801EE950[i] = ((s32 (*)(s32, s32))func_8001D074)(0x3E, 0x7D);
        (&D_801EE96C)[i * 0x10] = 0;
        func_800233CC(&(&D_801EE96C)[i * 0x10] - 1, 0x30);
        func_8001CD50(D_801EE950[i], (s32)(&(&D_801EE96C)[i * 0x10] - 1));
        ((s32 *)D_801EE950[i])[1] |= 0xD0000040;
        i++;
    } while (i < 6);
}
