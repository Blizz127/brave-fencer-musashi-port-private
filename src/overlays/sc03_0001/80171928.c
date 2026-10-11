/* sc03_0001: func_80171928 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
void func_80171A1C(u8 *a0);

void func_80171928(void * a0)
{
    unsigned char idx = *(unsigned char *)((char *)a0 + 0x214);
    unsigned int *base = *(unsigned int **)((char *)a0 + 0x1FC);
    unsigned int cur = *(unsigned int *)((char *)a0 + 0x1F8);
    *(unsigned int *)((char *)a0 + 0x1F8) = base[idx] | (cur & 0x7F000000);
    ((void (*)(void *))func_80171A1C)(a0);
}
