/* SC02.CD member35: func_8016BF50 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_80015954(s32 a0, s32 a1);
extern void func_80149350(s32 arg0);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80149350(s32 arg0);
extern void func_80015954(s32 a0, s32 a1);

s32 func_8016BF50(s32 param)
{
    u16 buf[3];
    s32 arg;
    arg = *(s32 *)(param + 0x34);
    buf[0] = *(u16 *)(param + 0x12);
    buf[1] = *(u16 *)(param + 0x16);
    buf[2] = *(u16 *)(param + 0x1a);
    ((void (*)(s32, void *, void *))func_80149350)(arg, buf, buf);
    ((void (*)(void *, s32))func_80015954)(buf, param + 4);
}
