/* Complete SC02 object initialization; independently matched ordinary C. */
/* SC02 member 31, full [8013221C,80132288). */
typedef struct Object {
    unsigned short id, state;
    unsigned char pad04[0x1c];
    void *resource;
    unsigned char pad24[0x34];
    void *data;
    unsigned short value;
} Object;
extern void *func_8012C1B8(Object *);
extern void func_8012CAE4(Object *);
extern void func_8001C214(void *, int);
extern unsigned char D_801851D0[];
void func_8013221C(Object *object)
{
    void *resource=func_8012C1B8(object);
    object->resource=resource;
    if (!resource) {
        func_8012CAE4(object);
    } else {
        func_8001C214(resource,0);
        object->data=D_801851D0;
        object->value=0x80;
        object->state++;
    }
}
