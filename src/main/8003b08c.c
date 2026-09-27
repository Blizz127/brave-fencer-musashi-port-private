/* Exact retail word export for [8003B08C,8003B0B8); EXE and assembly verified. */
/* Full retail main leaf, 11 words; DMA write direction. */
extern volatile unsigned int *D_8006B560;
void func_8003B08C(void)
{
    *D_8006B560 = (*D_8006B560 & 0xf0ffffff) | 0x20000000;
}
