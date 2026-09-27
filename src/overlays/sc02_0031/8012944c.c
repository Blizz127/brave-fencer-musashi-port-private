/* Complete retail export [8012944C,8012956C). */
extern unsigned int D_8005128C[];
extern short D_80114EE0;
extern unsigned char D_800B9A78[];
extern void func_801298F4(void *);
extern void func_801299C8(int,short,void *);
void func_8012944C(void)
{
    unsigned char *record;
    int i;
    if (D_8005128C[0] == 0x34420200) D_8005128C[0] = 0;
    D_80114EE0 = 1;
    record = D_800B9A78;
    for (i=0;i<2;++i) {
        switch (*(unsigned short *)(record+0x34)) {
        case 0x7FFF: break;
        case 0x7FFD:
            if (!i) func_801299C8(1,1,record);
            break;
        case 0x7FFE:
            func_801299C8(1,i*2,record);
            break;
        default:
            func_801298F4(record);
            *(unsigned short *)(record+0x1E) = *(unsigned short *)(record+0x42) + *(unsigned short *)(record+0x3A);
            func_801299C8(1,i+3,record);
            break;
        }
        record += 84;
    }
}
