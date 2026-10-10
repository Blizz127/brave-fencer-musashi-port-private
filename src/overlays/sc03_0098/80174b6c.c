/* sc03_0098: func_80174B6C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern u8 D_80126948[];
extern void func_8012A568(void (*a0)(void));
extern void func_8012A018(s32 a, s32 b);
extern void func_80174BBC(void *a0);
extern void func_8012A018(s32 a, s32 b);
extern void func_8012A0E0(void);
extern void func_80174BF4(void *a0);
extern u8 D_80126948[];
void func_80174BBC(void *a0);
void func_80174BF4(void * arg0);

void func_80174B6C(void) {
    func_80174BBC(D_80126948);
    func_8012A018((s32)func_80174BF4, 0);
    func_8012A0E0();
    func_80174BF4(D_80126948);
}
