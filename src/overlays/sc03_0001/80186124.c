/* sc03_0001: func_80186124 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
s32 func_80185C9C();
extern void func_8012C1B8(void);
extern s32 func_80185C9C(void *a0);
extern u16 D_801E6640[];
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012CAE4(void *a0);

void func_80186124(void *a0)
{
    s32 v0;
    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C214(v0, (s32)D_801E6640);
    func_80185C9C(a0);
}
