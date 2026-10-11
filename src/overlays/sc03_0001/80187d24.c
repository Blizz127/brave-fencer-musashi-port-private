/* sc03_0001: func_80187D24 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012E8E0(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8001D0E8(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012E8E0(s32 a0, s32 a1);

void func_80187D24(s32 a0) {
    extern s32 D_801CA118[];
    extern s32 D_801C0B18[];
    s32 v0;
    s32 result;
    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    func_8001C214(v0, (s32)D_801CA118);
    func_8001D0E8(*(s32 *)(a0 + 0x20), 0x7FFF, 0x7FFF);
    result = *(s32 *)(a0 + 0x20);
    *(s32 *)(result + 0x4) |= 0x40;
    func_8012E8E0(a0, (s32)D_801C0B18);
    *(s16 *)(a0 + 0x2) = 1;
}
