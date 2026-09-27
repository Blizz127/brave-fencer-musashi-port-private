/* Complete SC02 retail span [80131FDC,80132018); independently matched ordinary C. */
/* Complete SC02 member 31 [80131FDC,80132018), 15 words. */
typedef struct CallbackState { unsigned short id, state; } CallbackState;
typedef int (*Callback)(CallbackState *);
extern Callback D_801851F8[];
int func_80131FDC(CallbackState *object)
{
    return D_801851F8[object->state](object);
}
