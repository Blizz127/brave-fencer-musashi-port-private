/* Complete SC02 member31 callback [8018129C,8018133C). */
extern int D_80126950, D_80126954, D_8012695C;
extern short D_80126968,D_8012696A,D_8012696C,D_80126976,D_80126978,D_8012697A;
extern unsigned char D_80126948[];
extern void func_8018133C(void *);
extern void func_8012A018(void (*)(void *), int);
extern void func_8012A094(void *);
void func_8018129C(void)
{
    D_80126950 = D_80126954 = 500;
    D_8012695C = 1200;
    D_80126968 = 0x2AA;
    D_8012696A = 0x600;
    D_8012696C = 0;
    D_80126976 = 0;
    D_80126978 = 0;
    D_8012697A = 0;
    func_8012A018(func_8018133C, 0);
    func_8012A094(D_80126948);
    func_8018133C(D_80126948);
}
