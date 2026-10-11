/* sc03_0001: func_80182AEC from Druthulu/BFM-decomp
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
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_801886A0(s32);
extern u8 D_801B9360[];
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80187994(s32, s32, s32, s32);
void func_8018260C(short *a0);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 a0);
extern u8 D_801B9360[];
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_801886A0(s32 a0);
extern void func_8018260C(short*);

void func_80182AEC(void *arg0) {
    extern u8 D_801B9360[];
    if (*(u16 *)((char *)arg0 + 0x34) == 0) {
        if (((s32 (*)(void))func_80187A64)() != 0) {
            func_80187994((s32)arg0, (s32)&D_801B9360[0], 1, 0x80);
            *(s16 *)((char *)arg0 + 0x34) = 1;
        }
    } else if (func_801886A0(3) != 0) {
        if (func_80187A64((s32)arg0) != 0) {
            ((void (*)(void *))func_8018260C)(arg0);
        }
    }
}
