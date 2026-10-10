/* sc03_0098: func_80180EBC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern s32 func_8012C354(s32 a0, s32 a1);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012CAE4(void *a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_80181F34(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012E8A8(u8 *a0);
extern void func_8012B2CC(s32 a0);
extern s32 func_8005C49C(void);
s32 func_80181F34(void);

void func_80180EBC(s32 a0) {
    extern u8 D_8019E0F4[];
    extern u8 D_8019E194[];
    s16 state;
    s16 flag;
    s32 p;
    s32 dst;
    if ((*(u16 *)(a0 + 0x70) & 0xF) == 0 && func_80181F34() == 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    state = *(u16 *)(a0 + 0x70) & 0xF;
    if (func_8012C354(a0, (s32)(D_8019E0F4 + state * 0x34)) == 0) {
        return;
    }
    *(u8 *)(a0 + 0xC0) = 1;
    *(s32 *)(a0 + 0xBC) = (s32)D_8019E194;
    *(s32 *)(a0 + 0xB4) = -2;
    *(s32 *)(a0 + 0xC4) |= 1;
    *(s16 *)(a0 + 0xFE) = (func_8005C49C() % 16) + 8;
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x2C) |= 0x10;
    flag = *(s16 *)(a0 + 0x70);
    if ((flag & 0x8000) == 0) {
        if ((flag & 0x800) != 0) {
            *(s16 *)(a0 + 0x2) = 5;
            func_8012E8A8((u8 *)a0);
        } else {
            *(s16 *)(a0 + 0x2) = 1;
        }
    } else {
        p = *(s32 *)(a0 + 0x64);
        *(s16 *)(a0 + 0x2) = 3;
        *(s16 *)(a0 + 0x5C) = 0;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) = *(u16 *)(*(s32 *)(p + 0x20) + 0x12);
        dst = *(s32 *)(a0 + 0x20);
        *(s16 *)(dst + 0x18) = *(s16 *)(dst + 0x1A) = *(s16 *)(dst + 0x1C) = 1;
        func_8012B2CC(a0);
    }
}
