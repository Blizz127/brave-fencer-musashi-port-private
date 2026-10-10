/* SC02.CD member35: func_8017F2A0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_80198DE0[])(void *);
extern void func_8012C0EC(void *a0);

void func_8017F2A0(void *a0) {
    D_80198DE0[*(u16 *)((s32)a0 + 0x2)](a0);
    if (*(u16 *)((s32)a0 + 0x0) != 0) {
        void *ptr = *(void **)((s32)a0 + 0x20);
        *(u16 *)((s32)ptr + 0x2C) |= 0x10;
        if (!(*(u16 *)((s32)a0 + 0x70) & 0x20)) {
            func_8012C0EC(a0);
        }
    }
}
