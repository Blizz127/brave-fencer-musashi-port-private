/* sc03_0098: func_8017CDF8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct Ent_8017BFE0_8017CDF8 {
    u8 pad00[2];
    u16 f02;
    u8 pad04[0x18];
    s32 f1c;
    u8 pad20[0xA];
    u16 f2a;
    u16 f2c;
    u8 pad2e[2];
    s32 f30;
} Ent_8017BFE0_8017CDF8;
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80147324(s32 arg0);
extern void func_8017D030(int);
extern void func_80147324(s32 arg0);
extern void func_8017D030(int);
void func_8017D030(int param_1);

void func_8017CDF8(Ent_8017BFE0_8017CDF8 *param_1)
{
    s32 t;
    t = param_1->f1c;
    param_1->f1c = t + 1;
    if (t < 0x20) {
        param_1->f2a = param_1->f2a - 0x10;
    } else {
        if (param_1->f30 == 0) {
            func_80147324(param_1->f2c);
        }
        param_1->f1c = 0;
        param_1->f02 = param_1->f02 + 1;
    }
    ((void (*)(Ent_8017BFE0_8017CDF8 *))func_8017D030)(param_1);
}
