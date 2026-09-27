/* Exact retail word export for [8003AE14,8003AE9C); EXE and assembly verified. */
/* Complete retail main [8003AE14,8003AE9C). */
extern int D_8006B568, D_8006B574;
extern unsigned short D_8006B564;
extern int func_8003AB84();
extern int func_8003A84C(void *, int);
int func_8003AE14(void *source, int size)
{
    if (D_8006B568 == 0) {
        func_8003AB84(2, D_8006B564 << D_8006B574);
        func_8003AB84(1);
        func_8003AB84(3, source, size);
    } else {
        func_8003A84C(source, size);
    }
    return size;
}
