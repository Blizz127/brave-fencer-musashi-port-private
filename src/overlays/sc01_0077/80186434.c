/* sc01_0077: func_80186434 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32, void *);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(int, void *);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void * a1);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(s32, s32, s32);
extern void func_8012A828(s32 a0, void *a1);
extern u8 D_801D6F6C;
extern u8 D_801D55C0;
extern s32 D_801D55AC[];
extern u8 D_801D5568;
extern u8 D_801D5558;

void func_80186434(s32 arg0) {
    s32 param_1 = arg0;
    register s32 iVar1 __asm__("$17");
    s32 ret;
    s32 iVar2;
    ret = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(param_1 + 0x20) = ret;
    iVar1 = ret;
    if (ret == 0) {
        ((void (*)(s32))func_8012CAE4)(param_1);
    } else {
        ((void (*)(s32, void *))func_8001C214)(iVar1, &D_801D6F6C);
        func_8001D0E8(iVar1, 0x104, 0x190);
        *(u16 *)(iVar1 + 0x1c) = 0x1c00;
        *(u16 *)(iVar1 + 0x1a) = 0x1c00;
        *(u16 *)(iVar1 + 0x18) = 0x1c00;
        *(u16 *)(iVar1 + 0x2c) = *(u16 *)(iVar1 + 0x2c) | 0x10;
        *(u16 *)(param_1 + 0x76) = 4;
        *(s32 *)(param_1 + 0x78) = (s32)&D_801D55C0;
        *(u16 *)(param_1 + 0xdc) = *(u16 *)(param_1 + 6);
        *(u16 *)(param_1 + 0xde) = *(u16 *)(param_1 + 0xe);
        ((void (*)(s32, s32))func_8012A828)(param_1, D_801D55AC[*(s16 *)(param_1 + 0x76)]);
        *(u16 *)(param_1 + 2) = 1;
        if (*(s16 *)(param_1 + 0x70) == 4) {
            *(s32 *)(param_1 + 0x58) = (s32)&D_801D5568;
        } else {
            *(s32 *)(param_1 + 0x58) = (s32)&D_801D5558;
        }
        iVar2 = *(s32 *)(param_1 + 0x20);
        *(u32 *)(param_1 + 0x58) = *(u32 *)(param_1 + 0x58) | 0x60000000;
        *(u16 *)(iVar2 + 0x1c) = 0x1c00;
        *(u16 *)(iVar2 + 0x1a) = 0x1c00;
        *(u16 *)(iVar2 + 0x18) = 0x1c00;
        *(u16 *)(param_1 + 0x5e) = 0;
        *(u16 *)(param_1 + 0x5c) = *(u16 *)(param_1 + 0x5c) | 0x8800;
        *(u16 *)(param_1 + 6) = *(u16 *)(param_1 + 0xdc);
        *(u16 *)(param_1 + 0xe) = *(u16 *)(param_1 + 0xde);
    }
}
