/* Complete SC02 state increment; independently matched ordinary C. */
/* Complete SC02 member 31 [8012AD50,8012AD64), 5 words. */
typedef struct Object { unsigned short id, state; unsigned char pad[0x30]; unsigned short flag; } Object;
void func_8012AD50(Object *object)
{
    object->flag = 0;
    object->state++;
}
