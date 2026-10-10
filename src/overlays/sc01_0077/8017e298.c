/* sc01_0077: func_8017E298 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern u8 D_80078EC1;
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern s32 func_8013767C(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern s32 D_8012695C;
extern s32 D_8012695C;
void func_8017D8DC(void);
extern s32 D_8012695C;
extern s32 D_8012695C;
extern s32 func_8013767C(s32 a0);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern s32 func_8013767C(s32 a0);
extern void func_8017D8DC(void);
extern u8 D_80078EC1;
extern u8 D_801B1720;
extern s32 D_8012695C;

void func_8017E298(void *arg0) {
    s16 temp_v0;
    void *temp_a0;
    temp_v0 = func_80012B04((*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x20)))) + (0x12))), 0x800, 4);
    temp_a0 = (*(void **)((s8 *)(arg0) + (0x20)));
    (*(s16 *)((s8 *)(temp_a0) + (0x12))) = (s16) (((u16) (*(s16 *)((s8 *)(temp_a0) + (0x12))) + temp_v0) & 0xFFF);
    if (temp_v0 == 0) {
        if (D_80078EC1 == 8) {
            (*(s32 *)((s8 *)(arg0) + (0x198))) = func_8013767C((s32) &D_801B1720);
            (*(u8 *)((s8 *)(arg0) + (0x214))) = 0xB;
        } else {
            s32 t;
            func_8017D8DC();
            t = D_8012695C;
            (*(s32 *)((s8 *)(arg0) + (0x204))) = 0x20;
            (*(s32 *)((s8 *)(arg0) + (0x208))) = t;
            (*(u8 *)((s8 *)(arg0) + (0x214))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x214))) + 1);
        }
    }
}
