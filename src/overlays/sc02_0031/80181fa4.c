/* Complete SC02 record initialization; independently matched ordinary C. */
/* Complete SC02 member 31 [80181FA4,80182070). */
typedef struct Object {
    unsigned short id,state;
    unsigned char pad04[0x1c];
    void *resource;
    unsigned char pad24[0x34];
    void *data;
    unsigned short value;
    unsigned char pad5e[0x7e];
    int variant;
} Object;
extern int func_80029504(void);
extern void *func_8012C1B8(void);
extern void func_8012CAE4(Object *);
extern void func_8001C214(void *, int);
extern int func_80181F5C(Object *, void *);
extern unsigned char D_80188E40[],D_80188E30[],D_80188E20[],D_80188E10[];
void func_80181FA4(Object *object)
{
    int metric=func_80029504();
    void *resource=func_8012C1B8();
    object->resource=resource;
    if (!resource) {
        func_8012CAE4(object);
    } else {
        func_8001C214(resource,0);
        object->data=D_80188E40;
        object->value=0x80;
        object->state++;
        if(metric>=900) object->variant=func_80181F5C(object,D_80188E30);
        else if(metric>=600) object->variant=func_80181F5C(object,D_80188E20);
        else if(metric>=200) object->variant=func_80181F5C(object,D_80188E10);
    }
}
