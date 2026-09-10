/* Exact retail word export for [80054514,800547D8); EXE and assembly verified. */
/* Complete retail main [80054514,800547D8). */
typedef struct Matrix { int word[8]; } Matrix;
typedef struct Coordinate {
    int flag;
    Matrix local, cached;
    struct Coordinate *child, *parent;
} Coordinate;
extern Coordinate *D_800C6D48[];
extern int D_800C7C70;
extern void func_80053050(Matrix *, Matrix *);
void func_80054514(Coordinate *input, Matrix *result)
{
    Matrix *output=result;
    Coordinate *coordinate=input;
    int depth=0, dirty=100;
    for (;;) {
        D_800C6D48[depth]=coordinate;
        if (coordinate->parent==0) {
            if (coordinate->flag==D_800C7C70 || coordinate->flag==0) {
                coordinate->cached=coordinate->local;
                *output=coordinate->cached;
                coordinate->flag=D_800C7C70;
            } else if (dirty==100) {
                *output=D_800C6D48[0]->cached;
                depth=0;
            } else {
                depth=dirty+1;
                *output=D_800C6D48[depth]->cached;
            }
            break;
        }
        if(coordinate->flag==D_800C7C70) {
            *output=coordinate->cached;
            break;
        }
        if(coordinate->flag==0) dirty=depth;
        coordinate=coordinate->parent;
        depth++;
    }
    while(depth>0) {
        func_80053050(output,&D_800C6D48[depth-1]->local);
        D_800C6D48[depth-1]->cached=*output;
        D_800C6D48[depth-1]->flag=D_800C7C70;
        depth--;
    }
}
