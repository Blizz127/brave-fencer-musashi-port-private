/* Complete retail export [8013B83C,8013BC7C); C built at -O0. */
typedef struct { int a; short b,c,d,pad; int e,f,g,h; } Record;
extern Record D_801B79E8[];
extern int D_801B7AA0,D_801B7A8C,D_801B7A88,D_801B7A84,D_801B7B00,D_801B7B04,D_801B7B08;
extern unsigned char D_801B7AB0[];
extern short D_800B9A0E;
extern void func_80052D90(int,void *);
extern void func_8013BD74(void *,void *);
extern void func_8013C08C(void *,void *);
void func_8013B83C(unsigned char *first,unsigned char *second,int value)
{
    int i;
    D_801B7AA0=0; D_801B7A8C=0; D_801B7A88=0; D_801B7A84=0;
    func_80052D90(0,D_801B7AB0);
    if (!first) return;
    D_801B7B00=value+500; D_801B7B04=value;
    for(i=0;i<4;++i) {
        D_801B79E8[i].a=0;
        D_801B79E8[i].b=D_801B79E8[i].c=D_801B79E8[i].d=0x6000;
        D_801B79E8[i].e=0x100;
        D_801B79E8[i].h=0;
    }
    switch(*first) {
    case 0x42:
        if (!D_800B9A0E) func_8013BD74(&D_801B7AA0,first);
        else func_8013BD74(&D_801B7AA0,second);
        D_801B7B08=0;
        break;
    case 0x43:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=1;
        break;
    case 0x44:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=2;
        break;
    case 0x45:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=3;
        break;
    case 0x46:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=4;
        break;
    case 0x47:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=5;
        break;
    case 0x48:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=6;
        break;
    case 0x49:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=9;
        break;
    case 0x4A:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=12;
        break;
    case 0x4B:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=13;
        break;
    case 0x4C:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=14;
        break;
    case 0x4D:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=15;
        break;
    case 0x4E:
        func_8013C08C(&D_801B7AA0,first);
        D_801B7B08=16;
        break;
    }
}
