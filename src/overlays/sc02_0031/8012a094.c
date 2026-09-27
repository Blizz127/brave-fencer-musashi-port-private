/* Complete SC02 member31 [8012A094,8012A0E0). */
typedef struct { unsigned char data[8]; } Block;
typedef struct { unsigned char pad[8]; int a,b,c,d; Block previous,current; unsigned short old[3],now[3]; } State;
void func_8012A094(State *state)
{
    state->a = state->b;
    state->c = state->d;
    state->previous = state->current;
    state->old[0] = state->now[0];
    state->old[1] = state->now[1];
    state->old[2] = state->now[2];
}
