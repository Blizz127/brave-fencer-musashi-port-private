/* Exact retail word export for [8001ABBC,8001ACF0); EXE and assembly verified. */
/* Mixed C: one empty compiler barrier; full retail span matched. */
extern int D_800A654C,D_800747F8,D_800BA1B4;
typedef struct { short id,unused,sound; } Entry;
extern Entry D_80063138[];
extern void func_8002D4C8(unsigned short,int);
extern int func_8001AE90(int,int,int),func_8001ACF0(int,int,int,int,int);
int func_8001ABBC(int mode,int index,int a,int b,int c)
{
    if (mode==1) {
        if (index!=D_800A654C) goto check;
return_same:
        __asm__ volatile("" : : : "memory");
        return 1;
check:
        if (D_80063138[index].id==D_800747F8) {
            if (!D_80063138[index].sound) goto return_same;
            func_8002D4C8(D_80063138[index].sound,0);
            D_800A654C=index;
            return 1;
        }
    }
    if (D_800BA1B4) {
        if (D_800BA1B4!=3) return 0;
        if (func_8001AE90(mode,index,a)) goto success;
    }
    if (!func_8001ACF0(mode,index,a,b,c)) return 0;
success:
    D_800BA1B4=0;
    return 1;
}
