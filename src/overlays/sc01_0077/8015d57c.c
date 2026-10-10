/* sc01_0077: func_8015D57C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80146CA0(void *a0);
extern void func_80155440(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80155440(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80155440(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_801746DC(void);

void func_8015D57C(s32 arg0)
{
    s16 *p;
    func_80154150((s32)arg0, 0x19);
    func_801553A8(arg0);
    func_80155440(arg0);
    func_80146CA0(arg0);
    *(s32 *)((s8 *)arg0 + 0x234) = 0;
    p = *(s16 **)((s8 *)arg0 + 0x178);
    if (p != 0) {
        if (*(u16 *)p == 0x1F8) {
            *(s16 *)((s8 *)p + 0xFC) = 1;
            func_801746DC();
        }
    }
}
