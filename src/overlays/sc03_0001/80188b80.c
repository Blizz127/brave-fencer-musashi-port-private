/* sc03_0001: func_80188B80 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80188830.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);

void func_80188B80(void *a0)
{
    extern s32 D_801C0E0C;
    s32 v0;
    u16 v0_2;
    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)((u8 *)a0 + 0x20) = v0;
    if (v0 == 0) {
        ((void (*)(void *))func_8012CAE4)(a0);
    } else {
        ((void (*)(s32, s32))func_8001C214)(v0, 0);
        *(s32 *)((u8 *)a0 + 0x58) = (s32)&D_801C0E0C | 0x40000000;
        v0_2 = *(u16 *)((u8 *)a0 + 0x2);
        *(u16 *)((u8 *)a0 + 0x34) = 0;
        *(s32 *)((u8 *)a0 + 0x1C) = 0;
        *(u16 *)((u8 *)a0 + 0x5C) = 0x800;
        *(u16 *)((u8 *)a0 + 0x2) = v0_2 + 1;
    }
}
