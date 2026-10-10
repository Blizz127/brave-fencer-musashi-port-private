/* sc03_0098: func_8015D380 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80187BEC;

void func_8015D380(s32 a0) {
    s16 out[4];
    s32 buf[8];
    s32 s1 = a0;
    s32 *s0 = buf;
    ((void (*)(void *))func_80013F3C)((void *)s0);
    ((void (*)(void *, s32))func_80012558)((void *)s0, *(s16 *)(*(s32 *)(s1 + 0x20) + 0x12));
    ((void (*)(void *, s32))func_800126C4)((void *)s0, *(s16 *)(*(s32 *)(s1 + 0x20) + 0x10));
    func_80048FBC((void *)s0, (void *)&D_80187BEC, (void *)out);
    memcpy((void *)(s1 + 0x138), (void *)out, 8);
}
