/* Complete SC02 entry dispatcher; independently matched ordinary C. */
/* Complete SC02 member 31 [801819E8,80181A24), 15 words. */
typedef struct CallbackState { unsigned short id, state; } CallbackState;
typedef int (*Callback)(CallbackState *);
extern Callback D_80188E00[];
int func_801819E8(CallbackState *object)
{
    return D_80188E00[object->state](object);
}
