/* sc03_0001: func_80184DDC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184DDC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80187A64(s32);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187778(s32 *a0, s32 a1);

void func_80184DDC(void *a0)
{
    extern u8 D_801B9544[];
    extern u8 D_801B9550[];
    extern short D_80192640;
    switch (*(u16 *)((s32)a0 + 0x34)) {
    case 0:
        if (func_801886A0(4) == 0) {
            return;
        }
        func_80187994((s32)a0, (s32)D_801B9544, 0, 0x40);
        *(u16 *)((s32)a0 + 0x34) = 1;
        return;
    case 1:
        func_801886A0(4);
        if (func_80187A64((s32)a0) == 0) {
            return;
        }
        func_80187994((s32)a0, (s32)D_801B9550, 0, 0x40);
        *(u16 *)((s32)a0 + 0x34) = 2;
        return;
    case 2:
        *(s32 *)(*(s32 *)((s32)a0 + 0xCC) + 0xB0) = 2;
        if (func_80187A64((s32)a0) != 0) {
            *(u16 *)((s32)a0 + 0x34) = 3;
        }
        return;
    case 3:
        if (func_801886A0(4) == 0) {
            return;
        }
        *(u16 *)((s32)a0 + 0x34) = 4;
        func_80187994((s32)a0, (s32)D_801B9544, 1, 0x40);
        return;
    case 4:
        func_801886A0(4);
        if (func_80187A64((s32)a0) == 0) {
            return;
        }
        *(u16 *)((s32)a0 + 0x2) = 5;
        func_80187778((s32 *)a0, (s32)&D_80192640);
        return;
    }
}
