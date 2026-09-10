/* SC02.CD member31 [801659DC,80165A18); exact word export. */
/* SC02 member31 [801659DC,80165A18): dispatch by the object's state byte. */
extern void (*D_80187A4C[])(unsigned char *);
void func_801659DC(unsigned char *object)
{
    D_80187A4C[object[0x1A0]](object);
}
