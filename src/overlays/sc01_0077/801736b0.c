/* sc01_0077: func_801736B0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 D_80126B58;
extern s32 func_8014C118(void * a0, s32 a1, s32 a2);
extern void func_8012A568(void (*a0)(void));
extern void func_80174684(void *);
extern s32 D_80127508;
void func_80174684(void *);
extern s32 func_8014C118(void *a0, s32 a1, s32 a2);
extern void func_80174684(void *);
extern s32 func_801736FC();
extern s32 D_80126B58;
extern s32 D_80127508;
s32 func_801736FC(void *a0);
void func_80174684(void* a0);

void func_801736B0(s32 a0, s32 a1) {
    D_80127508 = func_8014C118(&D_80126B58, a0, (s16)a1);
    func_80174684(func_801736FC);
}
