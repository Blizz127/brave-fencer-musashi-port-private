/* Complete SC02 callback dispatch [8018133C,80181378). */
extern void (*D_80188DD0[])(void *);
void func_8018133C(unsigned char *state)
{
    D_80188DD0[state[4]](state);
}
