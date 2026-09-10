/* Complete SC02 initialization; mixed C with empty register constraints. */
typedef struct { int word[38]; } Block;
typedef struct {
    unsigned char active, mode, pad2[4], level, pad7[5];
    short x0, y0, x1, y1, x2, y2;
    unsigned char pad18[0x30];
    Block first, second;
} State;
extern State D_8011F7A8;
extern Block D_80078E78;
extern short D_800B9A02;
extern void func_80016714(void *, int), func_801757A0(short), func_800596F4(int);
void func_80175308(void)
{
    register State *state __asm__("$8") = &D_8011F7A8;
    short *buffer;
    D_8011F7A8.active = 1;
    D_8011F7A8.mode = 2;
    D_8011F7A8.level = 0x37;
    D_8011F7A8.x0 = D_8011F7A8.x1 = -0x37;
    D_8011F7A8.x2 = D_8011F7A8.y0 = D_8011F7A8.y1 = D_8011F7A8.y2 = 0x37;
    D_8011F7A8.first = D_80078E78;
    __asm__ volatile("" : "=r"(state) : "0"(state));
    func_80016714(&state->second, 0x98);
    buffer = &D_800B9A02;
    __asm__ volatile("" : "=r"(buffer) : "0"(buffer));
    func_801757A0(*buffer);
    func_800596F4(0);
    func_801757A0(*buffer ^ 1);
}
