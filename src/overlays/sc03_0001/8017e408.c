/* sc03_0001: func_8017E408 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    u8 unk00[0x16];
    s16 unk16;
    u8 unk18[4];
    s32 unk1C;
    u8 unk20[4];
} Ent_8017D6EC;
extern void func_800183E0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_8017E204(void *arg0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
extern u32 D_801EE918;
extern u16 D_801910AC[];
extern u16 D_801EE91C[];
extern s32 D_801910CC;
extern void func_800183E0(s32 a0);

void func_8017E408(void)
{
    u32 i;
    u16 *p;
    u32 base;
    u16 *tbl;
    i = 0;
    tbl = D_801910AC;
    base = D_801EE918 >> 8;
    p = D_801EE91C;
    do {
        *p = tbl[(base + i) & 0xF] | 0x8000;
        i = i + 1;
        p = p + 1;
    } while (i < 0x10);
    func_800183E0((s32)&D_801910CC);
    D_801EE918 = D_801EE918 + 0x100;
}
