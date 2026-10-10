/* sc03_0098: func_8016E5F4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015954(s32 a0, s32 a1);
extern void func_8012EFB8(s32 a0);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80146C3C();
extern void func_8012EFB8(s32 a0);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80146C3C();
extern void func_80015954(s32 a0, s32 a1);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012EFB8(s32 a0);
extern void func_80146C3C();
extern void func_80015954(s32 a0, s32 a1);

void func_8016E5F4(s32 arg0) {
    s32 sp10;
    func_80015978(arg0 + 4, &sp10);
    if ((((s32 (*)(s32, s32))func_8012EFB8)((s32)&sp10, (s32)&sp10) & 0xFFFFEFFF) != 0) {
        ((void (*)(s32))func_80146C3C)(arg0);
    } else {
        func_80015954((s32)&sp10, arg0 + 4);
        *(s16 *)((u8 *)arg0 + 0x10) = 0x100;
        *(s16 *)((u8 *)arg0 + 0x12) = 0;
        *(s16 *)((u8 *)arg0 + 0x14) = 0;
        *(s16 *)((u8 *)arg0 + 0x16) = 0x80;
        *(s16 *)((u8 *)arg0 + 2) = *(u16 *)((u8 *)arg0 + 2) + 1;
    }
}
