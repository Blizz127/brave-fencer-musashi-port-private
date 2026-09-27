/* Exact retail word export for [80052D90,80052E38); EXE and assembly verified. */
/* Retail [80052D90,80052E0C): copy a default matrix and link coordinates. */
typedef struct Matrix { unsigned int words[8]; } Matrix;
typedef struct Coordinate {
    unsigned int flag;
    Matrix matrix;
    unsigned char padding[0x24];
    struct Coordinate *parent;
    struct Coordinate *child;
} Coordinate;
extern Matrix D_800AE620;
void func_80052D90(Coordinate *parent, Coordinate *coordinate)
{
    coordinate->matrix = D_800AE620;
    coordinate->parent = parent;
    coordinate->flag = 0;
    if (parent != 0 && parent != (Coordinate *)1)
        coordinate->parent->child = coordinate;
}

