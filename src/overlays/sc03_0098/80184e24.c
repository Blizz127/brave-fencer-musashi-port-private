/* sc03_0098: func_80184E24 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80184E24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
typedef struct { s32 w[4]; } Blk16_8018A8B8;
extern void func_8002850C(s32, s32, s32);
extern void func_80028620(s32, void *);
extern void func_8012A568(void (*a0)(void));
typedef struct { s32 w[4]; } LBlk16;

void func_80184E24(void *a0)
{
    extern void func_8002850C(s32 a0, s32 a1, s32 a2);
    extern void func_8012AD44(s32 *a0, s16 a1);
    extern void func_80028620(s32 a0, void *a1);
    extern s16 D_801C29AC, D_801C29AE, D_801C29B0;
    extern LBlk16 D_801C29B4;
    extern s16 D_801C29E4, D_801C29E6, D_801C29E8;
    extern LBlk16 D_801C29EC;
    extern s16 D_801C2A1C, D_801C2A1E, D_801C2A20;
    extern Blk16_8018A8B8 D_801C2A24;
    extern s16 D_801C2A54, D_801C2A56, D_801C2A58;
    extern Blk16_8018A8B8 D_801C2A5C;
    extern Blk16_8018A8B8 D_800A5E88;
    s32 v1 = *(s16 *)((s32)a0 + 0xFC);
    LBlk16 *s0;
    *(s16 *)((s32)a0 + 0xFE) = 0;
    switch (v1) {
    case 0:
        func_8002850C(D_801C29AC, D_801C29AE, D_801C29B0);
        s0 = &D_801C29B4;
        func_8012AD44((s32 *)a0, 1);
        break;
    case 1:
        func_8002850C(D_801C29E4, D_801C29E6, D_801C29E8);
        s0 = &D_801C29EC;
        func_8012AD44((s32 *)a0, 2);
        break;
    case 2:
        func_8002850C(D_801C2A1C, D_801C2A1E, D_801C2A20);
        s0 = &(*(LBlk16 *)&D_801C2A24);
        func_8012AD44((s32 *)a0, 3);
        break;
    case 3:
        func_8002850C(D_801C29AC, D_801C29AE, D_801C29B0);
        s0 = &D_801C29B4;
        func_8012AD44((s32 *)a0, 4);
        break;
    case 4:
        func_8002850C(D_801C2A54, D_801C2A56, D_801C2A58);
        s0 = &(*(LBlk16 *)&D_801C2A5C);
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
