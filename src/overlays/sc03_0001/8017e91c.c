/* sc03_0001: func_8017E91C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
typedef struct {
    u8 unk00[0x16];
    s16 unk16;
    u8 unk18[4];
    s32 unk1C;
    u8 unk20[4];
} Ent_8017D6EC;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A018(s32 a, s32 b);
extern void func_8017E204(void *arg0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
extern void func_8012A018(s32 a, s32 b);
extern void func_8012A094(s32 a0);
extern void func_8017E9E0(void *a0);
void func_8017E9E0(void *a0);

void func_8017E91C(void) {
    extern u8 D_80126948[];
    extern s32 D_80126950;
    extern s32 D_80126954;
    extern s32 D_8012695C;
    extern s16 D_80126968;
    extern s16 D_8012696A;
    extern s16 D_8012696C;
    extern s16 D_80126976;
    extern s16 D_80126978;
    extern s16 D_8012697A;
    extern u8 D_801269E8;
    u8 tmp = D_801269E8;
    D_80126954 = 0x1F4;
    D_80126950 = 0x1F4;
    D_8012695C = 0x4B0;
    D_80126968 = 0x238;
    D_8012696A = 0;
    D_8012696C = 0;
    D_80126976 = 0;
    D_80126978 = 0;
    D_8012697A = 0;
    func_8012A018((s32)func_8017E9E0, 0);
    D_801269E8 = tmp;
    func_8012A094((s32)D_80126948);
    func_8017E9E0(D_80126948);
    func_8012A094((s32)D_80126948);
    func_8017E9E0(D_80126948);
}
