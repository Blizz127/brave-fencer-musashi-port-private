/* Complete retail export [8012F14C,8012F1A4). */
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern void func_8004945C(void *, void *, int *);
void func_8012F14C(void *matrix, void *input, void *output)
{
    int flags;
    func_8004914C(matrix);
    func_800491AC(matrix);
    func_8004945C(input, output, &flags);
}
