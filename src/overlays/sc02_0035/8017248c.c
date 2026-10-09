/* SC02.CD member35: func_8017248C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801724EC(s32 a0);
s32 func_801724EC(s32 a0);

s32 func_8017248C(s32 arg0, s32 arg1)
{
    if (((s32 (*)(void*, void*))func_801724EC)(arg0, arg1) != 0) {
        *(u16*)((u8*)arg0 + 6) = *(u16*)((u8*)arg1 + 0);
        *(u16*)((u8*)arg0 + 0xA) = *(u16*)((u8*)arg1 + 2);
        *(u16*)((u8*)arg0 + 0xE) = *(u16*)((u8*)arg1 + 4);
        return 1;
    }
    return 0;
}
