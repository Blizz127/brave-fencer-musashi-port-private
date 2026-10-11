/* sc03_0001: func_80181A68 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80178CBC(s32*, s32);
extern void func_80187778(s32*, s32);
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80187778(s32*, s32);
extern void func_80178CBC(s32 *a0, s32 a1);
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80178CBC(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80178CBC(s32 *a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80191C28;

void func_80181A68(void *arg0)
{
    extern s32 func_80128C98(s32);
    extern void func_8001C97C(s32 *);
    extern void func_80178CBC(s32 *, s32);
    extern int func_80178970(void);
    extern void func_80178D18(void);
    extern void func_80187778(s32 *, s32);
    extern s16 D_801F1370;
    extern s16 D_80191C58;
    extern s16 D_80191C28;
    extern s16 D_801E4340;
    switch (*(u16 *)((char *)arg0 + 0x34)) {
    case 0:
        if (func_80128C98(4) != 0) {
            *(u16 *)((char *)arg0 + 0x34) = *(u16 *)((char *)arg0 + 0x34) + 1;
            func_8001C97C(&D_801F1370);
            *(s32 *)(*(s32 *)((char *)arg0 + 0x20) + 0x24) = (s32)&D_801F1370;
            func_80178CBC(arg0, (s32)&D_80191C58);
        }
        break;
    case 1:
        if (((int (*)(s32))func_80178970)(arg0) != 0) {
            ((void (*)(s32))func_80178D18)(arg0);
            *(s32 *)(*(s32 *)((char *)arg0 + 0x20) + 0x24) = (s32)&D_801E4340;
            *(s16 *)((char *)arg0 + 2) = 2;
            func_80187778(arg0, (s32)&D_80191C28);
        }
        break;
    }
}
