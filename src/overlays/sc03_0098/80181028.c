/* sc03_0098: func_80181028 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012B23C(void *a0);

void func_80181028(void *a0) {
    func_8012B23C(a0);
    *(s32 *)((s32)a0 + 0x1C) = 0x40;
    *(s16 *)((s32)a0 + 0x2) = 2;
    *(s16 *)((s32)a0 + 0x34) = 0;
    *(s32 *)((s32)a0 + 0xE4) = 0;
    *(s32 *)((s32)a0 + 0xE8) = 0x40;
}
