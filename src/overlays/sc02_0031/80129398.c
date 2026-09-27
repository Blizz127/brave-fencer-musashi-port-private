/* Complete retail export [80129398,80129428). */
typedef struct { unsigned short a,b,c,d,e,f,g,h; unsigned char pad[68]; } Record;
extern Record D_800B9AAC[];
void func_80129398(void)
{
    int i;
    for (i=0;i<2;++i) {
        D_800B9AAC[i].a = 0x7FFF;
        D_800B9AAC[i].b = 0;
        D_800B9AAC[i].c = 0xFFFF;
        D_800B9AAC[i].d = 0;
        D_800B9AAC[i].e = 320;
        D_800B9AAC[i].f = 238;
        D_800B9AAC[i].g = 0;
        D_800B9AAC[i].h = 0;
    }
}
