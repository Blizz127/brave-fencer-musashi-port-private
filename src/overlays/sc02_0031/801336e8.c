/* Complete retail export [801336E8,8013373C). */
extern void *D_801B62D8,*D_801B62DC,*D_801B62E0;
extern void func_80136BC4(void *);
void func_801336E8(void *first,void *second,void *third)
{
    if (first) {
        D_801B62D8=first;
        func_80136BC4(first);
    }
    D_801B62DC=second;
    D_801B62E0=third;
}
