/* Complete SC02 entry dispatcher; independently matched ordinary C. */
/* Complete SC02 member 31 [80181F20,80181F5C), 15 words. */
typedef struct CallbackState { unsigned short id, state; } CallbackState;
typedef int (*Callback)(CallbackState *);
extern Callback D_80188E50[];
int func_80181F20(CallbackState *object)
{
    return D_80188E50[object->state](object);
}
