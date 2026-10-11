/* sc03_0001: func_8015E344 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80147078(s32 *a0, s16 a1);
extern int func_80161208();
extern s32 func_80161208();
extern void func_80159BE4(s32);
extern void func_80159BE4(s32 arg0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159BE4(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void (*D_8018FBA8[])(void *);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void (*D_8018FBA8[])(void*);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern s32 func_80161208();
extern s32 func_80161B18(void *);
extern s32 func_80161B84(void *);
extern s32 func_80161208();
extern void func_80147078(s32*, s16);
extern void (*D_8018FBA8[])(void *);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void (*D_8018FBA8[])(void *);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80161208();
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void (*D_8018FBA8[])(void *);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80161208();
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80161208();
extern void func_8015E40C(s32 a0);
extern void func_8015E40C(s32 a0);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern s32 func_80161208();
extern void func_8015E5B0(u8*);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159BE4(s32 arg0);
extern void (*D_8018FBA8[])(void*);
void func_8015E40C(s32 a0);
void func_8015E5B0(u8 *self);
s32 func_80161B18(void *a0);
s32 func_80161B84(void *a0);

void func_8015E344(u16 *param_1)
{
    ((s32 (*)(void))func_8015E40C)();
    if (((s32 (*)(u16 *))func_80161B18)(param_1) == 0 &&
        ((s32 (*)(u16 *))func_80161B84)(param_1) == 0 &&
        ((s32 (*)(u16 *))func_80161208)(param_1) == 0) {
        if ((param_1[0x5c] & 0x4000) != 0) {
            ((void (*)(u16 *))func_8015E5B0)(param_1);
            *(s32 *)((char *)param_1 + 0x234) = 1;
        }
        if ((param_1[0x5c] & 0x8000) != 0) {
            ((void (**)(u16*))D_8018FBA8)[param_1[0]](param_1);
            ((s32 (*)(u16 *, s32))func_80147078)(param_1, 0);
            ((s32 (*)(u16 *))func_80159BE4)(param_1);
        }
    }
}
