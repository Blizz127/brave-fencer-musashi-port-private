/* SC02.CD member35: func_80155B9C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80147460(s32 a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 a0);
extern s32 D_800D4DB4;

void func_80155B9C(s32 a0) {
    *(s32 *)(a0 + 0x44) |= 2;
    func_80148038(a0, 0x30000);
    func_80147460(a0);
    if (*(s32 *)(a0 + 0x34) >= 0) {
        func_80154274((s32 *)a0, (s32)&D_800D4DB4);
        func_80146CA0((void *)a0);
        func_80147324(0x447);
    }
}
