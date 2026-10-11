/* sc03_0001: func_8017EDB8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8017E1B4(void *a0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
extern void func_80187778(s32 *a0, s32 a1);
extern short D_801913D4;
extern s32 func_80029504(void);
extern s32 func_801877C0(s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern s32 func_8017EF30();
s32 func_8017EF30();

void func_8017EDB8(void *a0) {
    extern short D_801913D4;
    void *s0 = a0;
    s32 v0;
    s32 v1;
    void *v1p;
    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)((u8 *)s0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(s0);
    }
    func_8001C214(*(s32 *)((u8 *)s0 + 0x20), 0);
    v1 = func_80029504();
    if (v1 < 0xC8) {
        v0 = ((s32 (*)(void))func_801877C0)();
        if (v0 == 3) {
            v0 = 2;
        } else {
            v0 = func_8018766C(0xA, 0x10);
            if (v0 != 0) {
                v0 = 1;
            } else {
                v0 = 2;
            }
        }
    } else if (v1 < 0x258) {
        func_8012CAE4(s0);
        return;
    } else if (v1 < 0x384) {
        if (v1 < 0x276) {
            func_8012CAE4(s0);
            return;
        }
        v0 = 1;
    } else {
        v0 = 1;
    }
    *(s16 *)((u8 *)s0 + 0x2) = (s16)v0;
    __asm__ __volatile__("");
    func_80187778((s32 *)s0, (s32)&D_801913D4);
    v1p = *(void **)((u8 *)s0 + 0x68);
    *(s16 *)((u8 *)v1p + 0xC) = 0x7FFF;
    *(s32 *)((u8 *)s0 + 0xD4) = func_801788B8((s32)s0, (s32)&func_8017EF30);
}
