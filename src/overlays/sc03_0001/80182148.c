/* sc03_0001: func_80182148 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32 a0);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32);
extern s32 func_801877C0(s32 a0);
void func_80181C38(void *arg0);
void func_80181D8C(short *a0);
extern s32 func_801877C0(s32 a0);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_801877C0(s32 a0);
extern s32 func_801877C0(s32 a0);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80181D8C(short *a0);
extern void func_80181C38(void *arg0);

void func_80182148(void *a0)
{
    s32 v0;
    *(s32 *)(*(s32 *)((u8 *)a0 + 0xCC) + 0xB0) = 2;
    v0 = ((s32 (*)(void))func_801877C0)();
    if (v0 == 3) {
        v0 = func_8018766C(0xA, 0x16);
        if (v0 != 0) {
            func_80181D8C((short *)a0);
        }
    } else {
        v0 = func_8018766C(0xA, 0x10);
        if (v0 != 0) {
            func_80181C38(a0);
        }
    }
}
