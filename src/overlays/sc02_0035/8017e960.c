/* SC02.CD member35: func_8017E960 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C354(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);

void func_8017E960(void *a0) {
    extern u8 D_801847FC[];
    extern u8 D_801969B4[];
    extern u8 D_801968D0[];
    if (((s32 (*)(s32, s32))func_8012C354)((s32)a0, (s32)D_801969B4) != 0) {
        void *a2 = *(void **)((char *)a0 + 0x20);
        *(s32 *)((char *)a2 + 0x4) |= 0x80000000;
        *(u8 *)((char *)a0 + 0xC0) = 1;
        *(s32 *)((char *)a0 + 0xBC) = (s32)D_801968D0;
        *(s32 *)((char *)a0 + 0xC4) |= 0x2;
        ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801847FC);
        *(u16 *)((char *)a0 + 0x2) = 1;
        *(u8 *)((char *)a0 + 0x75) = 0;
    }
}
