/* Complete SC02 entry dispatcher; independently matched ordinary C. */
/* Complete SC02 member 31 [80181868,801818A4), 15 words. */
typedef struct CallbackState { unsigned short id, state; } CallbackState;
typedef int (*Callback)(CallbackState *);
extern Callback D_80188DE8[];
int func_80181868(CallbackState *object)
{
    return D_80188DE8[object->state](object);
}
