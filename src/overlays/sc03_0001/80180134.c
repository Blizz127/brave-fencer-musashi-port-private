/* sc03_0001: func_80180134 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
void func_8017F13C(void);
extern void func_8001C214(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012C588(s32, s32);
extern void func_8012CAE4(void *a0);
extern void func_8017F13C(void);

void func_80180134(void *a0) {
        s32 v0;
        u16 val;
        v0 = ((s32 (*)(void *))func_8012C1B8)(a0);
        *(s32 *)((char *)a0 + 0x20) = v0;
        if (v0 == 0) {
            func_8012CAE4(a0);
            return;
        }
        func_8001C214(v0, 0);
        func_8012C588(0x13F, 0);
        func_8012C588(0x66, 0);
        func_8012C588(0x65, 0);
        func_8012C588(0x14C, 0);
        func_8012C588(0x335, 0);
        func_8012C588(0x3D9, 0);
        val = *(u16 *)((char *)a0 + 0x72);
        *(u16 *)((char *)a0 + 0x2) = 1;
        val |= 0x1000;
        *(u16 *)((char *)a0 + 0x72) = val;
        func_8017F13C();
    }
