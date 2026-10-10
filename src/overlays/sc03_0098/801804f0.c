/* sc03_0098: func_801804F0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);

void func_801804F0(void *a0) {
    extern u8 D_8018564C[];
    extern u8 D_8019BDA8[];
    extern u8 D_8019BCC4[];
    if (func_8012C354((s32)a0, (s32)D_8019BDA8) != 0) {
        void *a2 = *(void **)((char *)a0 + 0x20);
        *(s32 *)((char *)a2 + 0x4) |= 0x80000000;
        *(u8 *)((char *)a0 + 0xC0) = 1;
        *(s32 *)((char *)a0 + 0xBC) = (s32)D_8019BCC4;
        *(s32 *)((char *)a0 + 0xC4) |= 0x2;
        func_8012A828((s32)a0, (s32)D_8018564C);
        *(u16 *)((char *)a0 + 0x2) = 1;
        *(u8 *)((char *)a0 + 0x75) = 0;
    }
}
