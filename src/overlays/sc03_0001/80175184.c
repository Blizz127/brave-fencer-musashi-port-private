/* sc03_0001: func_80175184 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void (*D_80190B94[])(void*);
extern s32 func_80175268(s32);
s32 func_80175268(s32 param_1);

void func_80175184(s32* arg0) {
    u16 v1 = *(u16*)((u8*)arg0 + 2);
    if (v1 < 2) {
        D_80190B94[v1](arg0);
    } else {
        func_80175268((s32)arg0);
    }
}
