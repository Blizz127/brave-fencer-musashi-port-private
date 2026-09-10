/* Complete SC02 state-0 body; independently matched ordinary C. */
/* Complete SC02 member 31 [80181BB4,80181C2C), 30 words. */
typedef struct Object { unsigned short id, state; } Object;
extern int func_80181EF0(Object *);
extern void func_80181DEC(unsigned char *, int);
extern void func_8002D4C8(int, int);
extern void func_8012AD50(Object *);
extern unsigned char D_801B7840[];
void func_80181BB4(Object *object)
{
    int i;
    unsigned char *row;
    if (func_80181EF0(object) != 0) {
        i = 0;
        row = D_801B7840;
        do {
            func_80181DEC(row, i);
            i++;
            row += 0x18;
        } while (i < 10);
        func_8002D4C8(0x83E, 0);
        func_8012AD50(object);
    }
}
