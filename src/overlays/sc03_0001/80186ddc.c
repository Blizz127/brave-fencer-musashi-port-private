/* sc03_0001: func_80186DDC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012B2CC(s32 a0);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern s32 func_80178BF8();
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012E8E0(s32, s32);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern s32 func_801788B8(s32 a0, s32 a1);
extern void func_8001C214(s32 a0, s32 a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF80186828(void *a0) __asm__("func_80186828");
extern void func_8012E8E0(s32, s32);
extern s32 func_80029504(void);
extern void func_8012E8E0(s32, s32);
extern void func_8001C214(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern void func_8012B2CC(s32 arg);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012B2CC(s32 a0);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg);
extern void func_80186F88(void);

void func_80186DDC(void *arg0) {
    extern u8 D_801C0404[];
    extern u8 D_801C04F4[];
    extern u8 D_801C04FC[];
    extern u8 D_801C050C[];
    s32 v0;
    s32 t;
    s32 *p;
    v0 = ((s32 (*)(void *))func_8012C1B8)(arg0);
    *(s32 *)((char *)arg0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(arg0);
    } else {
        func_8001C214(v0, *(s16 *)((char *)arg0 + 0x70) == 0 ? (s32)&D_801C0404[0] : (s32)&D_801C04F4[0]);
        *(s16 *)((char *)arg0 + 0x5C) = 0x800;
        *(s32 *)((char *)arg0 + 0x58) =
            (s32)&D_801C050C[*(s16 *)((char *)arg0 + 0x70) * 0x10] | 0x40000000;
        func_8012E8E0((s32)arg0, (s32)&D_801C04FC[*(s16 *)((char *)arg0 + 0x70) * 8]);
        *(s16 *)(*(s32 *)((char *)arg0 + 0x68) + 0xC) = 0x7FFF;
        t = func_80029504();
        if ((func_80029178(0xF6) & 0xFF) == 0 && t < 0xE6) {
            if (*(s16 *)((char *)arg0 + 0x70) == 0) {
                *(s16 *)((char *)arg0 + 0x2) = 1;
                *(s16 *)((char *)arg0 + 0x34) = 0;
                func_801788B8((s32)arg0, (s32)func_80186F88);
            } else {
                s32 *q = *(s32 **)((char *)arg0 + 0x20);
                *(s16 *)((char *)arg0 + 0x2) = 3;
                *(s16 *)((char *)arg0 + 0x34) = 0;
                *(s16 *)((char *)q + 0x12) = 0;
                *(s32 *)((char *)arg0 + 0x1C) = 0x30;
            }
        } else {
            if (*(s16 *)((char *)arg0 + 0x70) == 0) {
                p = *(s32 **)((char *)arg0 + 0x20);
                *(s16 *)((char *)arg0 + 0x2) = 2;
                *(s16 *)((char *)p + 0x12) = -0x600;
                func_8012B2CC((s32)arg0);
            } else {
                p = *(s32 **)((char *)arg0 + 0x20);
                *(s16 *)((char *)arg0 + 0x2) = 4;
                *(s16 *)((char *)p + 0x12) = 0x600;
                func_8012B2CC((s32)arg0);
            }
        }
    }
}
