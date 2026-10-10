/* sc01_0077: func_8013DBE4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern void *D_801D9578;
extern void func_8013DD68(void);
extern s32 D_801D958C;
extern void *D_801D9578;
extern s16 *D_801D957C;
extern void *D_801D9578;
extern s16 *D_801D957C;
extern s32 D_801D958C;
extern s32 D_801D95AC;
extern s32 D_801D95B0;
extern s32 D_801D95B4;
extern void func_8013DD68(void);
void func_8013DD68();

void func_8013DBE4(int param_1)
{
    int *p;
    int x, y, z;
    int flag;
    if (D_801D957C != 0) {
        D_801D958C = 0;
        p = (int *)(param_1 * 12 + (int)D_801D9578);
        x = p[0];
        y = p[1];
        z = p[2];
        flag = 0;
        if (D_801D95AC != x) {
            flag = 1;
            if (D_801D95AC < x) {
                if (x - D_801D95AC < 5) {
                    D_801D95AC = x;
                } else {
                    D_801D95AC = D_801D95AC + 4;
                }
            } else {
                if (D_801D95AC - x < 5) {
                    D_801D95AC = x;
                } else {
                    D_801D95AC = D_801D95AC - 4;
                }
            }
        }
        if (D_801D95B0 != y) {
            flag = 1;
            if (D_801D95B0 < y) {
                if (y - D_801D95B0 < 5) {
                    D_801D95B0 = y;
                } else {
                    D_801D95B0 = D_801D95B0 + 4;
                }
            } else {
                if (D_801D95B0 - y < 5) {
                    D_801D95B0 = y;
                } else {
                    D_801D95B0 = D_801D95B0 - 4;
                }
            }
        }
        if (D_801D95B4 != z) {
            flag = 1;
            if (D_801D95B4 < z) {
                if (z - D_801D95B4 < 5) {
                    D_801D95B4 = z;
                } else {
                    D_801D95B4 = D_801D95B4 + 4;
                }
            } else {
                if (D_801D95B4 - z < 5) {
                    D_801D95B4 = z;
                } else {
                    D_801D95B4 = D_801D95B4 - 4;
                }
            }
        }
        if (flag != 0) {
            func_8013DD68();
        }
        D_801D958C = flag;
    }
}
