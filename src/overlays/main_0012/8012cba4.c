/* Owner re-derivation from retail assembly (clean input set). */
/* Calls func_8012CC88 with mode 0 and the D_800D3918 table. */
extern char D_800D3918[];
void func_8012CC88(int a0, int mode, char *tbl);
void func_8012CBA4(int a0) {
    func_8012CC88(a0, 0, D_800D3918);
}
