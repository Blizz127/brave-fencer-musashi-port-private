/* sc03_0001: func_8012D664 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct S8012D664_8012D664 { short a, b, c; };
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u16 D_80126B66;
extern u16 D_80126B5E;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 func_800132BC(s32 a0, s32 a1);

int func_8012D664(int arg0, int arg1, int arg2) {
    extern int func_8012F568();
    extern int D_8018D848;
    struct S8012D664_8012D664 s;
    int ret;
    int t;
    s.a = (*(unsigned short*)&D_80126B5E);
    s.b = (*(unsigned short*)&D_80126B62) - 0x40;
    s.c = (*(unsigned short*)&D_80126B66);
    ret = ((int(*)())func_800132BC)(arg0, &s);
    t = arg1 + 0x20;
    if (ret < t * t) {
        func_8012F568(1, 1, 0, arg2, arg0, &D_8018D848);
        return 1;
    }
    return 0;
}
