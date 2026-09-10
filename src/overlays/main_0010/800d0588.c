/* Complete retail function [800d0588,800d05e8); independently matched ordinary C. */
extern short D_800B9A08;
extern int D_8012704C;
extern int func_800D05E8(short);
extern int func_8001ABBC(int,int,int,int,int);
int func_800D0588(void)
{
    int request=func_800D05E8(D_800B9A08);
    int result;
    if (request) result=func_8001ABBC(1,request,0,0,0);
    else result=1;
    if (result) D_8012704C=0;
    return result;
}
