/* SC02.CD member35: func_80183FD4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80183FD4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2, rodata 0x801BD580). */
typedef short s16;
typedef int s32;
typedef struct { s32 w[4]; } Blk16_8018A8B8;
extern void func_8002850C(s32, s32, s32);
extern void func_80028620(s32, void *);
extern void func_8012A568(void (*a0)(void));
typedef struct { s32 w[4]; } LBlk16;

void func_80183FD4(void *a0)
{
    extern void func_8002850C(s32 a0, s32 a1, s32 a2);
    extern void func_8012AD44(s32 *a0, s16 a1);
    extern void func_80028620(s32 a0, void *a1);
    extern s16 D_801BBDBC, D_801BBDBE, D_801BBDC0;
    extern LBlk16 D_801BBDC4;
    extern s16 D_801BBDF4, D_801BBDF6, D_801BBDF8;
    extern LBlk16 D_801BBDFC;
    extern s16 D_801BBE2C, D_801BBE2E, D_801BBE30;
    extern Blk16_8018A8B8 D_801BBE34;
    extern s16 D_801BBE64, D_801BBE66, D_801BBE68;
    extern Blk16_8018A8B8 D_801BBE6C;
    extern Blk16_8018A8B8 D_800A5E88;
    s32 v1 = *(s16 *)((s32)a0 + 0xFC);
    LBlk16 *s0;
    *(s16 *)((s32)a0 + 0xFE) = 0;
    switch (v1) {
    case 0:
        func_8002850C(D_801BBDBC, D_801BBDBE, D_801BBDC0);
        s0 = &D_801BBDC4;
        func_8012AD44((s32 *)a0, 1);
        break;
    case 1:
        func_8002850C(D_801BBDF4, D_801BBDF6, D_801BBDF8);
        s0 = &D_801BBDFC;
        func_8012AD44((s32 *)a0, 2);
        break;
    case 2:
        func_8002850C(D_801BBE2C, D_801BBE2E, D_801BBE30);
        s0 = &(*(LBlk16 *)&D_801BBE34);
        func_8012AD44((s32 *)a0, 3);
        break;
    case 3:
        func_8002850C(D_801BBDBC, D_801BBDBE, D_801BBDC0);
        s0 = &D_801BBDC4;
        func_8012AD44((s32 *)a0, 4);
        break;
    case 4:
        func_8002850C(D_801BBE64, D_801BBE66, D_801BBE68);
        s0 = &(*(LBlk16 *)&D_801BBE6C);
        func_8012AD44((s32 *)a0, 5);
        break;
    }
    {
        LBlk16 *dst = &(*(LBlk16 *)&D_800A5E88);
        LBlk16 *src = s0;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        func_80028620(0, &dst[0]);
        func_80028620(1, &dst[1]);
        func_80028620(2, &dst[2]);
    }
}
