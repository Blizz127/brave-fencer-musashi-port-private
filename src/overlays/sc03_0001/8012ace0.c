/* sc03_0001: func_8012ACE0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { int a; short cmd; short b; } Elem_8012ACE0_8012ACE0;
typedef struct { char pad[0x90]; Elem_8012ACE0_8012ACE0 *list; } Owner_8012ACE0_8012ACE0;

s32 func_8012ACE0(void *o) {
    int i;
    for (i = 0; ; i++) {
        switch (((Owner_8012ACE0_8012ACE0 *)o)->list[i].cmd) {
            case -2:
            case -1:
            case 0:
                return i;
            case -50: case -45: case -40: case -35: case -30:
            default:
                break;
        }
    }
}
