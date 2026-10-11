/* sc03_0001: func_8017E648 from Druthulu/BFM-decomp
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
extern void func_8012A568(void (*a0)(void));
extern void func_8017E204(void *arg0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
extern void func_800D1E28(void);
extern void func_800D1E28(void);

s32 func_8017E648(void *a0) {
    s32 *p = (s32 *)((u8 *)a0 + 0x28);
    *p = *p - 1;
    if (*p == -1) {
        func_800D1E28();
        (*(u8 *)((u8 *)a0 + 0x15))++;
    }
    return 0;
}
