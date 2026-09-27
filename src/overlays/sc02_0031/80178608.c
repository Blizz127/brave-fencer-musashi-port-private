/* Complete SC02 retail span [80178608,8017869C); independently matched ordinary C. */
typedef struct { short active, zero, enabled; unsigned char flag, mode; unsigned char buffer[0x400]; } State;
extern unsigned char D_801202A0[];
extern State D_801270C0;
extern unsigned int D_801274D8, D_801274DC, D_801274E0;
extern void func_80016714(void *, int), func_8013E4B4(void);
void func_80178608(void)
{
    func_80016714(D_801202A0, 0x6480);
    D_801270C0.active = 1;
    D_801270C0.enabled = 1;
    D_801274D8 = 0x240000;
    D_801270C0.zero = 0;
    D_801270C0.flag = 0;
    D_801270C0.mode = 0;
    D_801274DC = 0x271000;
    D_801274E0 = 0x400000;
    func_80016714(D_801270C0.buffer, 0x400);
    func_8013E4B4();
}
