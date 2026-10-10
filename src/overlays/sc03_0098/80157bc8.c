/* sc03_0098: func_80157BC8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_80146D90(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_80147460(s32 a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80148038(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014ED28(s32 _arg0);
extern void func_801473EC(s32 *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_8014ED28();
extern void func_80146D90(s32 a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801473EC(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
s32 aF80156600(void) __asm__("func_80156600");
s32 func_80156600(void* _arg0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014ED28();
extern s32 func_801725A4(u8 *a0);
extern void func_801473EC(s32 *a0);
extern void func_80148038(int, int);
extern void func_80147460(int);
extern void func_8014ED28(s32 _arg0);
extern void func_80146D90(int);
extern s32 func_801725A4(u8 *a0);
extern void func_80161D20();
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801473EC(s32 *a0);
extern void func_8016706C(s32 a0);
extern s32 func_801725A4(u8 *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_801473EC(s32 *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_8014ED28();
extern void func_80146D90(s32 a0);
extern void func_8016158C(void *a0);
extern void func_80161D20();
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8016706C(s32 a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8015BE04(s32 *a0);
extern s32 func_801725A4(u8 *a0);

void func_80157BC8(s32 a0) {
    s32 s1;
    func_80147AD4(a0, 0, 0, 0x10000);
    func_801473EC((s32 *)a0);
    func_80148038(a0, 0x1A000);
    func_80147460(a0);
    {
        register s32 ret __asm__("$2");
        func_8014ED28(a0);
        if (ret != 0) {
            func_80146D90(a0);
        }
    }
    {
        register s32 r __asm__("$2");
        func_8016158C((void *)a0);
        s1 = r;
    }
    if ((s1 & 5) != 0) {
        func_80161D20(a0, *(u16 *)(a0 + 0x16E));
        func_8014C010(a0, 1);
        func_8016706C(4);
        func_8016706C(5);
        func_801599A4((void *)a0);
        func_80159B3C((void *)a0);
    }
    if (s1 != 0) {
        return;
    }
    if (*(s32 *)(a0 + 0x34) > 0) {
        func_801599A4((void *)a0);
        func_80146D90(a0);
        func_8015BE04((s32 *)a0);
    } else {
        func_801725A4((u8 *)a0);
    }
}
