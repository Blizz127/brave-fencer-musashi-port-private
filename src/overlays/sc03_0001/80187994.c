/* sc03_0001: func_80187994 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B744(void *a0, void *a1);
extern void func_8012B200(u8 *a0);
extern s32 func_80029504(void);
s32 aF801877C0(void) __asm__("func_801877C0");
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_8012B744(void *a0, void *a1);
extern void func_8012B200(u8 *a0);

void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 idx;
    s32 base;
    u16 vals[3];
    s32 result;
    s32 *v1;
    *(u8*)(a0 + 0x108) = a2;
    a2 = a2 & 0xFF;
    *(s32*)(a0 + 0xE8) = a1;
    *(u8*)(a0 + 0x109) = a3;
    idx = *(s16*)a1;
    if (a2 == 0) {
        *(u16*)(a0 + 0x106) = 2;
        *(u16*)(a0 + 0x6) = *(u16*)(a1 + 4);
        *(u16*)(a0 + 0xE) = *(u16*)(a1 + 6);
        vals[0] = *(u16*)(a1 + 8);
        vals[2] = *(u16*)(a1 + 10);
    } else {
        base = idx;
        base = base * 4 + a1;
        *(u16*)(a0 + 0x106) = (u16)(idx - 1);
        *(u16*)(a0 + 0x6) = *(u16*)(base);
        *(u16*)(a0 + 0xE) = *(u16*)(base + 2);
        vals[0] = *(u16*)(base - 4);
        vals[2] = *(u16*)(base - 2);
    }
    result = func_8012B744((void*)(a0 + 4), vals);
    v1 = (s32*)(a0 + 0x20);
    *(u16*)(*v1 + 0x12) = (u16)result;
    func_8012B200((u8*)a0);
}
