/* sc03_0001: func_8017DE28 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern u32 D_8019105C;

void func_8017DE28(s32 arg0) {
    s32 v0 = ((s32 (*)(s32))func_8012C1B8)(arg0);
    *(s32*)((u8*)arg0 + 0x20) = v0;
    if (v0 == 0) {
        ((void (*)(s32))func_8012CAE4)(arg0);
    } else {
        func_8001C214(v0, 0);
        *(s16*)((u8*)arg0 + 0x2) = 1;
        *(s16*)((u8*)arg0 + 0x5C) = 0x20;
        *(s32*)((u8*)arg0 + 0x58) = (u32)&D_8019105C | 0x40000000;
        *(s16*)((u8*)(*(s32*)((u8*)arg0 + 0x20)) + 0x12) = *(u16*)((u8*)arg0 + 0xFC);
    }
}
