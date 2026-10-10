/* sc01_0077: func_80144B14 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern u16 D_80115116;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern short D_800B9A02;
extern u16 D_80115116;
extern short D_800B9A02;
extern u16 D_80115116;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern u16 D_80126B62;
extern s32 func_80013294(void *a0, void *a1);

int func_80144B14(int param_s0)
{
    u16 local_buf1[3];
    u16 local_buf2[3];
    s32 call_result;
    local_buf1[0] = *(u16 *)((char *)param_s0 + 0x6);
    local_buf1[1] = *(u16 *)((char *)param_s0 + 0xA);
    local_buf1[2] = *(u16 *)((char *)param_s0 + 0xE);
    local_buf2[0] = D_80126B5E;
    local_buf2[1] = D_80126B62;
    local_buf2[2] = D_80126B66;
    call_result = func_80013294(local_buf1, local_buf2);
    if (call_result < *(s16 *)((char *)param_s0 + 0xFC)) {
        return *(u32 *)((char *)param_s0 + 0xCC);
    }
    return 0;
}
