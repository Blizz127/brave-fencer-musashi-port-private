/* sc03_0098: func_8012A418 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct BigCopy;
struct BigCopy { s32 words[41]; };
struct Q16 { s32 a, b, c, d; };
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern struct BigCopy D_80126DB8;
extern struct BigCopy D_80114EE8;
extern struct BigCopy D_80126DB8;
extern s32 D_801151D4;
extern s32 D_801151D4;
extern struct BigCopy D_80114EE8;

void func_8012A418(void) {
    struct Q16 *src;
    struct Q16 *dst;
    struct Q16 *end;
    src = (struct Q16 *)D_801151D4;
    dst = &D_80114EE8;
    end = src + 10;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (src != end);
    *(s32 *)dst = *(s32 *)src;
}
