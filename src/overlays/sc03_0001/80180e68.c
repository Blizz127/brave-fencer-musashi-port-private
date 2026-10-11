/* sc03_0001: func_80180E68 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
s32 func_80180AC4(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
void func_80180CD4(s32 a0);
extern s32 func_80180AC4(s32 a0);
extern s32 func_80187A64(s32 a0);
extern s32 func_80187A64(s32 a0);
extern s32 func_80180AC4(s32 a0);
extern void func_80180CD4(s32 a0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80180E68(void *arg0)
{
    extern short D_801B92FC;
    s32 v0;
    v0 = func_80187A64((s32)arg0);
    if (v0 != 0) {
        v0 = ((s32 (*)(void))func_80180AC4)();
        if (v0 == 0) {
            func_80180CD4((s32)arg0);
        } else {
            func_80187994((s32)arg0, (s32)&D_801B92FC, 0, 0x40);
        }
    }
}
