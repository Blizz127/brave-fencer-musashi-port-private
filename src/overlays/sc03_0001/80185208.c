/* sc03_0001: func_80185208 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80178CBC(s32*, s32);
extern void func_80178CBC(s32 *a0, s32 a1);
extern void func_80178CBC(s32 *, s32);
extern void func_80178CBC(s32 *a0, s32 a1);
extern void func_80178CBC(s32 *a0, s32 a1);
extern short D_80192740;

void func_80185208(void *a0) {
    *(short *)((char *)a0 + 0x2) = 0xe;
    *(short *)((char *)a0 + 0x34) = 0;
    ((void (*)(int, int))func_80178CBC)((int)a0, (int)&D_80192740);
}
