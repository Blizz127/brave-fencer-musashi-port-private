/* Exact retail word export for [800538EC,80053978); EXE and assembly verified. */
/* Retail [800538EC,80053978): accept modes 0..3, diagnose invalid modes. */
extern int D_800C6DC8;
extern char D_80073B54[];
extern void func_8005C604(char *, ...);
void func_800538EC(int mode)
{
    switch (mode) {
    case 0:
        D_800C6DC8 = 0;
        break;
    case 1:
        D_800C6DC8 = mode;
        break;
    case 2:
        D_800C6DC8 = mode;
        break;
    case 3:
        D_800C6DC8 = mode;
        break;
    default:
        func_8005C604(D_80073B54, mode);
        break;
    }
}

