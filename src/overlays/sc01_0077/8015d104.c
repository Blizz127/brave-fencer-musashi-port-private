/* sc01_0077: func_8015D104 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80146CA0(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80149FB0(s32 a0);
extern void func_8014E6A0(void);
extern void func_8014FA04(s32 a0);
void func_8014FA04(s32 a0);
extern void (*D_801891B8[])(void *);
extern void func_80159B70(void *a0);
extern void (*D_801891B8[])(void *);
extern s32 func_80149FB0(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80146CA0(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80146CA0(void *a0);
extern void (*D_801891B8[])(void*);
extern s32 func_80149FB0(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80146CA0(void *a0);
extern void (*D_801891B8[])();
extern s32 func_80149FB0(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void (*D_801891B8[])(void*);
void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80146CA0(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80149FB0(s32 a0);
extern void func_8014FA04(s32 a0);
extern void func_80159B70(void *a0);
void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80149FB0(s32 a0);
extern void func_8014FA04(s32 a0);
extern void func_8014E6A0(void);
extern void (*D_801891B8[])(void *);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern s32 func_801725F4(u8 *a0);
extern void func_80146CA0(void *a0);

void func_8015D104(void *arg0) {
    ((void (*)(void))func_80149FB0)();
    ((void (*)(void *))func_8014FA04)(arg0);
    if (((s32 (*)(void *))func_8014E6A0)(arg0) == 0) {
        D_801891B8[*(u16 *)arg0](arg0);
        ((void (*)(void *, s16))func_80147078)(arg0, 0);
        func_80159B70(arg0);
    } else {
        ((void (*)(void *))func_801725F4)(arg0);
        *(s32 *)((u8 *)arg0 + 0x234) = 0xFF1D0000;
        *(u16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x10) = 0x600;
        *(u16 *)((u8 *)arg0 + 0x244) = *(u16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x10);
        func_80146CA0(arg0);
    }
}
