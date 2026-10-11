/* sc03_0001: func_80182BB8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
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
void func_8018268C(void * arg0);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 a0);
extern u8 D_801B9360[];
extern u8 D_801B93A4[];
extern u8 D_801B93F4[];
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 a0);
extern u8 D_801B9360[];
extern u8 D_801B93A4[];
extern u8 D_801B93F4[];
extern void func_80187994(s32, s32, s32, s32);
extern void func_8018268C(void *arg0);

void func_80182BB8(void *arg0)
{
    switch (*(u16 *)((s32)arg0 + 0x34)) {
    case 0:
        if (func_801886A0(3) == 0) {
            return;
        }
        *(u16 *)((s32)arg0 + 0x34) = 1;
        func_80187994((s32)arg0, (s32)D_801B9360, 0, 0x80);
        return;
    case 1:
        func_801886A0(3);
        if (func_80187A64((s32)arg0) == 0) {
            return;
        }
        *(u16 *)((s32)arg0 + 0x34) = 2;
        func_80187994((s32)arg0, (s32)D_801B93A4, 0, 0x80);
        return;
    case 2:
        if (func_80187A64((s32)arg0) == 0) {
            return;
        }
        *(u16 *)((s32)arg0 + 0x34) = 3;
        return;
    case 3:
        if (func_801886A0(0xD) == 0) {
            return;
        }
        *(u16 *)((s32)arg0 + 0x34) = 4;
        func_80187994((s32)arg0, (s32)D_801B93F4, 0, 0x80);
        return;
    case 4:
        func_801886A0(0xD);
        if (func_80187A64((s32)arg0) == 0) {
            return;
        }
        func_8018268C(arg0);
        return;
    }
}
