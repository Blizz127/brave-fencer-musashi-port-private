/* sc03_0001: func_8017E874 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
struct S;
struct S {
    u8 pad0[0x7E];
    u16 f7E;
};
extern s32 func_801472C8(struct S *a0);
extern void func_80165770(void);
extern void func_80175414(s32 _arg0);
extern void func_8016F0E4(void);
extern void func_8012A568(void (*a0)(void));
extern void func_80175414(s32 _arg0);
extern void func_80175414(s32 _arg0);
extern void func_8016F0E4(void);
extern void func_80165770(void);

void func_8017E874(void *a0) {
    ((void (*)(void *))func_80175414)(a0);
    ((s32 (*)(struct S *))func_8016F0E4)((struct S *)a0);
    ((void (*)(void *))func_80165770)(a0);
}
