/* Complete retail export [8013C08C,8013C0F8); C built at -O0. */
typedef struct { unsigned char pad[8]; unsigned char *resource,*data; } State;
extern void func_8013C0F8(void *);
void func_8013C08C(State *state,unsigned char *resource)
{
    unsigned char *base=resource;
    state->resource=resource;
    state->data=base+20;
    func_8013C0F8(resource);
}
