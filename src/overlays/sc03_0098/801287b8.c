/* sc03_0098: func_801287B8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct S8014FDF4;
struct S8014FDF4 {
    s16 pad0[3];
    s16 f6;
    s16 pad8;
    s16 fA;
    s16 padC;
    s16 fE;
    s16 pad[0x3C];
    s16 f88;
    s16 f8A;
    s16 f8C;
};
extern u8 D_800B9A64;
extern s32 D_80126B58;
extern s32 D_801C5848;
extern u16 D_800B99DA;
extern u8 D_800B9A64;
extern void func_80129CF8(void);
extern void func_8017849C(void);
extern void func_8014FDF4(struct S8014FDF4 *a0);
extern s32 func_801505FC(s32 a0);
extern void func_801508B4(void *a0);
extern void func_80165E90(void);
extern void func_801627E8(void);
extern void func_80162B1C(void);
extern void func_80165CA0(void);
extern void func_80129010(void);
extern void func_8013CA14(void);
extern void func_800190AC(void);
extern void func_8012956C(void);
extern void func_8016E95C(void);
extern void func_801754A8(void);
extern void func_8013BC7C(void *);
extern void func_8013BCDC(void);
extern void func_801379FC(void);
extern void func_8001212C(void);
void func_80129010(void);
void func_8012956C(void);
void func_80129CF8(void);

void func_801287B8(void) {
    func_80129CF8();
    func_8017849C();
    ((void (*)(void *))func_8014FDF4)(&D_80126B58);
    ((void (*)(void *))func_801505FC)(&D_80126B58);
    func_801508B4(&D_80126B58);
    func_80165E90();
    func_801627E8();
    func_80162B1C();
    func_80165CA0();
    func_80129010();
    func_8013CA14();
    func_800190AC();
    func_8012956C();
    func_8016E95C();
    func_801754A8();
    {
        register volatile s32 *p __asm__("$4") = &D_801C5848;
        if (*p == 0) {
            func_8013BC7C((void *)p);
        }
    }
    func_8013BCDC();
    func_801379FC();
    D_800B99DA++;
    if (D_800B9A64 != 0) {
        func_8001212C();
    }
}
