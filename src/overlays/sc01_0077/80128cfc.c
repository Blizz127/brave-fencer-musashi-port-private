/* sc01_0077: func_80128CFC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_a.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct {
    s32 word0;
    s32 word4;
} CdFileLoc;
extern s32 D_801D7F90;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern s32 D_801D7F90;
extern int D_801D7F90;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern s32 D_801D7F90;
extern s32 D_801D7F90;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern s32 D_801D7F90;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);
extern CdFileLoc D_800AE830[];
extern s32 D_801D7F90;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);
extern CdFileLoc D_800AE830[];
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);

s32 func_80128CFC(s32 arg0) {
    extern s16 D_80186DDC[];
    s16 idx = D_80186DDC[arg0];
    if (idx >= 0) {
        func_8001ABBC(0, 0, (u8 *)&D_800AE830[idx], D_801D7F90, 0);
    } else {
        return 1;
    }
}
