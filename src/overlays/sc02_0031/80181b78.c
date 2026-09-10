/* Complete SC02 entry dispatcher; independently matched ordinary C. */
/* Complete SC02 member 31 [80181B78,80181BB4), 15 words. */
typedef struct CallbackState { unsigned short id, state; } CallbackState;
typedef int (*Callback)(CallbackState *);
extern Callback D_80188E08[];
int func_80181B78(CallbackState *object)
{
    return D_80188E08[object->state](object);
}
