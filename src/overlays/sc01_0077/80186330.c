/* sc01_0077: func_80186330 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void * a1);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern M2C_UNK D_801D77A8;

void func_80186330(void *arg0) {
    void *temp_v1;
    func_8001C214((*(void **)((s8 *)(arg0) + (0x20))), &D_801D77A8);
    func_8012A828(arg0, &D_80186E48);
    (*(s16 *)((s8 *)(arg0) + (2))) = 3;
    (*(u16 *)((s8 *)(arg0) + (6))) = (u16) (*(u16 *)((s8 *)(arg0) + (0xDC)));
    temp_v1 = (*(void **)((s8 *)(arg0) + (0x20)));
    (*(u16 *)((s8 *)(arg0) + (0xE))) = (u16) (*(u16 *)((s8 *)(arg0) + (0xDE)));
    (*(u16 *)((s8 *)(arg0) + (0x5C))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x5C))) & 0x77FF);
    (*(u16 *)((s8 *)(temp_v1) + (0x2C))) = (u16) ((*(u16 *)((s8 *)(temp_v1) + (0x2C))) & 0xFFEF);
    (*(s32 *)((s8 *)(arg0) + (0x1C))) = 0;
}
