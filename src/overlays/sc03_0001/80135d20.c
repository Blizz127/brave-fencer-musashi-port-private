/* sc03_0001: func_80135D20 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_801345F8(s32 arg);
extern s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4);
extern s16 func_80135480(void*, s32, s16*, s16*);
extern s32 func_80135EB0(void *arg0, s32 arg1_);
extern s32 func_801345F8(s32 arg);
extern s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 D_801ED3C4;
extern s32 D_801ED3E4;
s32 func_80135EB0(void *arg0, s32 arg1_);
s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_80135D20(s32 arg0, s32 arg1, u16 *arg2)
{
    u8 dead[96];
    u16 sp[3];
    s32 *p;
    s32 flag;
    s32 q;
    sp[0] = arg2[0];
    sp[1] = arg2[1] + 0x300;
    sp[2] = arg2[2];
    switch (((s32 (*)(void *, s32, s16 *, s16 *))func_80135480)((void *)arg0, arg1, (s16 *)arg2, (s16 *)sp)) {
    case 0:
        return 0;
    case 1:
        q = arg0 + 0x34;
        p = (s32 *)((arg1 & 0xFFFFFFF) | 0x80000000);
        do { flag = 0; } while (0);
        break;
    case 2:
        q = arg0 + 0x34;
        p = (s32 *)((arg1 & 0xFFFFFFF) | 0x80000000);
        flag = 1;
        break;
    case 3:
        q = arg0 + 0x34;
        p = &D_801ED3E4;
        flag = 0;
        break;
    case 4:
        q = (s32)&D_801ED3C4;
        p = &D_801ED3E4;
        flag = 1;
        break;
    }
    if (arg1 >= 0) {
        goto elsepath;
    }
    if (func_80135EB0(p, 0) != 0) {
        goto hit;
    }
    p = (s32 *)*p;
    if (p == ((void *)0)) {
        return 0;
    }
loop:
    if (func_80135EB0(p, 0) == 0) {
        goto body;
    }
hit:
    func_80136A94(flag, arg0, (s32)arg2, q);
    return 1;
body:
    p = (s32 *)*p;
    if (p != ((void *)0)) {
        goto loop;
    }
    return 0;
elsepath:
    if (func_801345F8(arg1) != 0) {
        goto hit;
    }
    return 0;
}
