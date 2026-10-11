/* sc03_0001: func_80187584 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern u8 D_80078EB1;

void func_80187584(void *a0) {
    extern u16 D_80078EAC;
    extern u8 D_80078EB1;
    extern short D_800BA2BA;
    u16 idx1 = D_80078EAC;
    u8 idx2 = D_80078EB1;
    s32 ptr = *(s32 *)((char *)a0 + 0xD0);
    s16 offset = *(s16 *)((char *)ptr + 0x10);
    *(short *)((char *)&D_800BA2BA + (offset << 2)) = idx2 + (idx1 * 24);
}
