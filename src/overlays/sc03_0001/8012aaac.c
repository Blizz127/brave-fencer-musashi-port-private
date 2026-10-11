/* sc03_0001: func_8012AAAC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;

void func_8012AAAC(void *arg0) {
    void *ptr;
    s32 link;
    s32 next;
    s32 saved;
    s32 cnt;
    s32 back;
    s32 head;
    (*(u16 *)((s8 *)(arg0) + (0x72))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x72))) & 0xBFFF);
    ptr = (void *) ((*(s32 *)((s8 *)(arg0) + (0x90))) + ((*(s32 *)((s8 *)(arg0) + (0x94))) * 8));
    if ((*(s16 *)((s8 *)(ptr) + (4))) < 0) {
        switch ((*(s16 *)((s8 *)(ptr) + (4)))) {
        case -2:
            link = (*(s32 *)((s8 *)(arg0) + (0x9C)));
            if (link == 0) {
                (*(s16 *)((s8 *)(arg0) + (0x98))) = 0;
                break;
            }
            goto pop;
        case -1:
            link = (*(s32 *)((s8 *)(arg0) + (0x9C)));
            if (link != 0) {
pop:
                back = (*(s16 *)((s8 *)(arg0) + (0x9A)));
                (*(s32 *)((s8 *)(arg0) + (0x90))) = link;
                (*(s32 *)((s8 *)(arg0) + (0x9C))) = 0;
                (*(s16 *)((s8 *)(arg0) + (0x9A))) = 0;
                (*(s32 *)((s8 *)(arg0) + (0x94))) = back;
                func_8012AAAC(arg0);
                break;
            }
            (*(s32 *)((s8 *)(arg0) + (0x94))) = 0;
            func_8012AAAC(arg0);
            (*(u16 *)((s8 *)(arg0) + (0x72))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x72))) | 0x4000);
            break;
        case -4:
            head = (*(s32 *)((s8 *)(ptr) + (0)));
            (*(s32 *)((s8 *)(arg0) + (0x94))) = 0;
            (*(s32 *)((s8 *)(arg0) + (0x9C))) = 0;
            (*(s16 *)((s8 *)(arg0) + (0x9A))) = 0;
            (*(s32 *)((s8 *)(arg0) + (0x90))) = head;
            (*(u16 *)((s8 *)(arg0) + (0x72))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x72))) & 0xF9FF);
            func_8012AAAC(arg0);
            break;
        case -3:
            cnt = (*(s32 *)((s8 *)(arg0) + (0x94))) + 1;
            (*(s32 *)((s8 *)(arg0) + (0x94))) = cnt;
            if ((*(s32 *)((s8 *)(arg0) + (0x9C))) != 0) {
                func_8012AAAC(arg0);
                break;
            }
            saved = (*(s32 *)((s8 *)(arg0) + (0x90)));
            next = (*(s32 *)((s8 *)(ptr) + (0)));
            (*(s32 *)((s8 *)(arg0) + (0x94))) = 0;
            (*(s32 *)((s8 *)(arg0) + (0x9C))) = 0;
            (*(s16 *)((s8 *)(arg0) + (0x9A))) = 0;
            (*(s32 *)((s8 *)(arg0) + (0x90))) = next;
            (*(u16 *)((s8 *)(arg0) + (0x72))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x72))) & 0xF9FF);
            func_8012AAAC(arg0);
            (*(s32 *)((s8 *)(arg0) + (0x9C))) = saved;
            (*(s16 *)((s8 *)(arg0) + (0x9A))) = (s16) cnt;
            break;
        case -50:
            (*(s32 *)((s8 *)(arg0) + (0x94))) = (*(s32 *)((s8 *)(arg0) + (0x94))) + 1;
            func_8012AAAC(arg0);
            (*(u16 *)((s8 *)(arg0) + (0x72))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x72))) | 0x2000);
            break;
        case -5:
            (*(u16 *)((s8 *)(arg0) + (0x72))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x72))) | 0x400);
            (*(s32 *)((s8 *)(arg0) + (0x94))) = (*(s32 *)((s8 *)(arg0) + (0x94))) - 1;
            func_8012AAAC(arg0);
            break;
        }
    } else {
        (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x20)))) + (0x20))) = (*(s32 *)((s8 *)(ptr) + (0)));
        (*(s16 *)((s8 *)(arg0) + (0x98))) = (*(s16 *)((s8 *)(ptr) + (4)));
    }
}
