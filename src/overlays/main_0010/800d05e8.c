/* Complete MAIN10 retail function; mixed C with empty allocation constraint. */
extern int func_80029504(void);
extern int (*D_800D375C)(int);
int func_800D05E8(void)
{
    int value=func_80029504();
    register int result __asm__("$16")=0;
    if (D_800D375C) result=D_800D375C(value);
    __asm__("" : "=r"(result) : "0"(result));
    return result;
}
