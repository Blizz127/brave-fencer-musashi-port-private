/* sc03_0098: func_8018095C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void);
extern void func_8012C218(void);
extern void func_8002A04C(s32 a0);
extern void func_8012C218(void);

void func_8018095C(s32 arg0) {
    if (*(s32 *)(arg0 + 0x1C) != 0) {
        *(s32 *)(arg0 + 0x1C) -= 1;
    }
    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x18) -= 0x100;
    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x1A) -= 0x100;
    if (*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x1A) < 0x81) {
        if (*(s16 *)(arg0 + 0x70) == 1) {
            void *temp = *(void **)(arg0 + 0xCC);
            if (arg0 != 0) {
                ((void (*)(void *))func_8012C218)(temp);
            }
        }
        func_8002A04C(arg0);
        ((void (*)(void *))func_8012C218)((void *)arg0);
    }
}
