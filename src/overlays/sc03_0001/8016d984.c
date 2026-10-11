/* sc03_0001: func_8016D984 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);
extern void func_80146C3C(void);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);

void func_8016D984(s32 *a0) {
    if ((--*(s32 *)((char *)a0 + 0x1C)) == 0) {
        func_80146C3C();
    } else {
        func_800D22E4((s32)a0);
        *(s32 *)((char *)a0 + 0x10) -= *(s32 *)((char *)a0 + 0x10) >> 4;
        *(s32 *)((char *)a0 + 0x14) -= *(s32 *)((char *)a0 + 0x14) >> 4;
        *(s32 *)((char *)a0 + 0x18) -= *(s32 *)((char *)a0 + 0x18) >> 4;
    }
}
