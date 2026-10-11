/* sc03_0001: func_80188124 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern int func_80178970(void);
extern void func_80178D18(void);
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80188830(void *a0);
extern int func_80178970(void);
extern void func_80178D18(void);

void func_80188124(void *a0) {
    switch (*(u16 *)((s32)a0 + 0x34)) {
    case 0:
        break;
    case 1:
        func_80188830(a0);
        *(s16 *)((s32)a0 + 0x34) = 2;
        break;
    case 2:
        if (((s32 (*)(s32))func_80178970)((s32)a0) != 0) {
            ((void (*)(s32))func_80178D18)((s32)a0);
            *(s16 *)((s32)a0 + 0x34) = 0;
        }
        break;
    }
}
