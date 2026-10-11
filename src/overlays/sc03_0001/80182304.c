/* sc03_0001: func_80182304 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_801886A0(s32 arg0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
void func_80181D8C(short *a0);
extern void func_80181D8C(short *a0);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_801886A0(s32);
extern void func_80181D8C(short*);

void func_80182304(void *arg0) {
    extern short D_801B9348;
    if (*(u16 *)((char *)arg0 + 0x34) == 0) {
        if (((s32 (*)(void))func_80187A64)() != 0) {
            func_80187994((s32)arg0, (s32)&((u8 *)&D_801B9348)[0], 1, 0x40);
            *(s16 *)((char *)arg0 + 0x34) = 1;
            *(s32 *)((char *)arg0 + 0x1C) = 0x20;
        }
    } else if (func_801886A0(6) != 0) {
        if (func_80187A64((s32)arg0) != 0) {
            ((void (*)(void *))func_80181D8C)(arg0);
        }
    }
}
