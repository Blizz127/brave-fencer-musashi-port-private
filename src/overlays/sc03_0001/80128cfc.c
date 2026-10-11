/* sc03_0001: func_80128CFC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct {
    s32 word0;
    s32 word4;
} CdFileLoc;
typedef CdFileLoc CdFileLoc_80128C98;
extern s32 D_801EBC68;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern s32 D_801EBC68;
extern int D_801EBC68;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern s32 D_801EBC68;
extern s32 D_801EBC68;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern s32 D_801EBC68;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);
extern CdFileLoc_80128C98 D_800AE830[];
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);
extern CdFileLoc D_800AE830[];
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4);

s32 func_80128CFC(s32 arg0) {
    extern s16 D_8018D7CC[];
    s16 idx = D_8018D7CC[arg0];
    if (idx >= 0) {
        func_8001ABBC(0, 0, (u8 *)&D_800AE830[idx], D_801EBC68, 0);
    } else {
        return 1;
    }
}
