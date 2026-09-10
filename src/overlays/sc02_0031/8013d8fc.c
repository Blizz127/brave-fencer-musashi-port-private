/* Complete retail export [8013D8FC,8013D9B0). */
/* SC02 member 31 [8013D8FC,8013D9B0): upload type-9 rectangles. */
typedef struct Record { unsigned short type, pad; short x,y,w,h; unsigned char *pixels; } Record;
typedef struct Rect { short x,y,w,h; } Rect;
extern Record *D_801B6364;
extern int func_800599B8(Rect *, void *);
void func_8013D8FC(void) {
    Record *record=D_801B6364;
    Rect rect;
    unsigned char *pixels;
    if (record) {
        while(record->type!=255) {
            if(record->type==9) {
                pixels=record->pixels+record->w*2;
                rect.x=record->x;
                rect.y=record->y;
                rect.w=record->w;
                rect.h=record->h;
                func_800599B8(&rect,pixels);
            }
            record++;
        }
    }
}
