/* sc03_0001: func_801843DC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern void func_8017E1B4(void *a0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
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
extern s32 func_80188D1C(void *);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_80178BF8(void);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_80178BF8(void);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern void func_80184350(void *a0);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_80178BF8(void);
s32 aF80184350(void *arg0) __asm__("func_80184350");
s32 aF80184350(void *arg0) __asm__("func_80184350");
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);

s32 func_801843DC(param_1)
s32 param_1;
{
        register s32 obj __asm__("$16") = param_1;
        s32 ptr;
        s32 ptr2;
        s32 result;
        ptr = *(s32 *)((char *)obj + 0x64);
        if (*(u16 *)((char *)ptr + 0x2) != 6) {
            return 0;
        }
        result = func_8012BD14(ptr);
        if (result >= 0x2401) {
            return 0;
        }
        ptr2 = *(s32 *)((char *)obj + 0x64);
        *(u16 *)((char *)ptr2 + 0x2) = 0xB;
        func_80178BF8();
        return (s32)func_80172710;
    }
