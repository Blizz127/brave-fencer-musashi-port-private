/* Complete SC02 camera calculation [801814E4,801816C0). */
#define H(o) (*(short *)(state+(o)))
#define W(o) (*(int *)(state+(o)))
extern unsigned char D_80126B58[];
extern short D_80188DD4[];
extern int func_80148800(void *);
extern short func_80012C6C(short,short,int);
extern short func_80012ABC(short,short,int);
extern void func_80049CAC(void *,void *);
extern void func_8012F14C(void *,void *,void *);
void func_801814E4(unsigned char *state, short *position)
{
    struct { short m[3][3]; short pad; int t[3]; } matrix;
    short vector[4],result[4];
    if (func_80148800(D_80126B58) & 3) {
        state[5] = (state[5]+1)&1;
        W(0x14) = D_80188DD4[state[5]];
    }
    W(8) = func_80012C6C(H(8),H(12),4);
    W(16) = func_80012C6C(H(16),H(20),4);
    H(24) = func_80012ABC(H(24),H(32),4);
    H(26) = func_80012ABC(H(26),H(34),4);
    H(28) = func_80012ABC(H(28),H(36),4);
    H(40) = func_80012C6C(H(40),H(46),16);
    H(42) = func_80012C6C(H(42),H(48),16);
    H(44) = func_80012C6C(H(44),H(50),16);
    W(72) = H(40)+position[0];
    W(76) = H(42)+position[1];
    W(80) = H(44)+position[2];
    func_80049CAC(state+24,&matrix);
    matrix.t[0] = H(40)+position[0];
    matrix.t[1] = H(42)+position[1];
    matrix.t[2] = H(44)+position[2];
    vector[0] = 0;
    vector[1] = 0;
    vector[2] = W(16);
    func_8012F14C(&matrix,vector,result);
    W(60) = result[0];
    W(64) = result[1];
    W(68) = result[2];
}
