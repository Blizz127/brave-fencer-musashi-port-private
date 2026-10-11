/* sc03_0001: func_80185B54 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern void func_8014CB68(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_8012E8E0(s32, s32);
extern void func_8012E88C(s32);
extern void func_8012E88C(s32 a0);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32*, s32);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern s32 func_8018727C(void *a0, void *a1);
extern void func_80187778(s32 *a0, s32 a1);
s32 aF801856A8(void *a0) __asm__("func_801856A8");
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80192864;
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80192864;
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80192864;
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80192864;
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80192864;
extern void func_8012E8E0(s32, s32);
extern void func_8012E88C(s32);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_80029504(void);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012E88C(s32 a0);
extern void func_80187344(void *s0);
extern void func_8014CB68(void);
extern s32 func_8012C588(s32, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern void func_801856A8();

void func_80185B54(void *arg0) {
    extern short D_80192864;
    extern short D_8019286C;
    extern short D_80192874;
    register s32 tc __asm__("$3");
    register s32 p68 __asm__("$2");
    s32 tt;
    void *s0 = arg0;
    if (func_8018727C(arg0, &D_80192874) != 0) {
        tc = ((s32 (*)(void))func_80029504)();
        if (tc < 20) {
            tt = 2;
        } else if (tc < 30) {
            tt = 7;
        } else if (tc < 100) {
            tt = 31;
        } else if (tc < 110) {
            *(s16 *)((char *)s0 + 2) = 12;
            *(s16 *)((char *)s0 + 0x34) = 0;
            func_8012E8E0((s32)s0, (s32)&D_8019286C);
            func_8012E88C((s32)s0);
            func_80187344((void *)s0);
            func_8014CB68();
            func_8012C588(343, (s32)s0);
            goto after;
        } else {
            tt = tc < 130;
            if (tt != 0) {
                tt = 18;
            } else {
                tt = 23;
            }
        }
        *(s16 *)((char *)s0 + 2) = tt;
        func_80187778((s32 *)s0, (s32)&D_80192864);
        goto after;
    after:
        p68 = *(s32 *)((char *)s0 + 0x68);
        *(s16 *)(p68 + 0xC) = 32767;
        tt = func_801788B8((s32)s0, (s32)&func_801856A8);
        *(s32 *)((char *)s0 + 0xD4) = tt;
        func_8012E8E0(tt, (s32)&D_80192864);
    }
}
