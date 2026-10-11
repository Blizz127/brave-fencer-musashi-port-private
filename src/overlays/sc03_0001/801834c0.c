/* sc03_0001: func_801834C0 from Druthulu/BFM-decomp
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
extern void func_8017E1B4(void *a0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
void aF80180B5C(void *arg0) __asm__("func_80180B5C");
extern s32 func_80180B5C(void *a0);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern void func_8018166C(void *);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF8018166C(void *arg0) __asm__("func_8018166C");
s32 aF8018166C(void *arg0) __asm__("func_8018166C");
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);

s32 func_801834C0(void *a0)
{
    extern s16 D_801EEB00;
    extern s16 D_801EEB02;
    void *p;
    u16 st;
    if (func_8012BD14(*(s32 *)((s32)a0 + 0x64)) > 0x4000) {
        __asm__ __volatile__("");
        return 0;
    }
    p = *(void **)((s32)a0 + 0x64);
    st = *(u16 *)((s32)p + 0x2);
    switch (st) {
    case 3:
        *(s16 *)((s32)p + 0x2) = 8;
        break;
    case 2:
        if (*(u16 *)((s32)p + 0x34) != 1) {
            return 0;
        }
        goto hit;
    case 4:
        if (*(u16 *)((s32)p + 0x34) != 0) {
            return 0;
        }
    hit:
        D_801EEB00 = st;
        D_801EEB02 = *(u16 *)((s32)p + 0x34);
        *(s16 *)(*(s32 *)((s32)a0 + 0x64) + 0x2) = 10;
        break;
    default:
        return 0;
    }
    func_80178BF8();
    return (s32)func_80172710;
}
