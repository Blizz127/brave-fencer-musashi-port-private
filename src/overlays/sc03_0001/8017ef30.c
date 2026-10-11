/* sc03_0001: func_8017EF30 from Druthulu/BFM-decomp
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
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern void func_8017E204(void *arg0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern void func_80172710(void);

s32 func_8017EF30(a0)
void *a0;
{
        s32 field;
        s32 *p;
        s32 v0;
        field = *(s32 *)((s32)a0 + 0x64);
        if (*(u16 *)(field + 0x2) != 2) {
            return 0;
        }
        if (func_8012BD14(field) >= 0x6401) {
            return 0;
        }
        if (*(s16 *)&D_80126B5E >= 0x281) {
            return 0;
        }
        if (*(s16 *)&D_80126B66 < -0x380) {
            return 0;
        }
        p = *(s32 **)((s32)a0 + 0x64);
        v0 = *(u16 *)((s32)p + 0x2) + 1;
        *(u16 *)((s32)p + 0x2) = v0;
        func_80178BF8();
        return (s32)func_80172710;
    }
