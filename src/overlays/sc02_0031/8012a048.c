/* Complete SC02 member31 [8012A048,8012A094). */
typedef struct { void *callback; unsigned char mode; unsigned char pad[151]; unsigned int counter; unsigned short a,b; } State;
extern unsigned short D_80126B5E,D_80126B62,D_80126B66;
extern unsigned short D_80126940,D_80126942,D_80126944;
void func_8012A048(State *state, void *callback, unsigned char mode)
{
    state->callback = callback;
    state->mode = mode;
    state->counter = 0;
    state->a = 0;
    state->b = 0;
    __asm__("" : : : "memory");
    D_80126940 = D_80126B5E;
    D_80126942 = D_80126B62;
    D_80126944 = D_80126B66;
}
