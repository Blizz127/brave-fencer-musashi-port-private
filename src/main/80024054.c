/* Complete retail span [80024054,800241C0); mixed C independently matched. */
/* Retail main [80024054,800241C0): convert double-byte text to glyphs.
 * Full 91-word pinned match, GCC 2.7.2 / ASPSX 2.56, -O2 -G0.
 * Mixed C: the fixed input register and empty offset identity constraints
 * preserve retail allocation and table indexing without emitted assembly.
 */
extern unsigned short D_80063818[], D_800636D8[], D_80063770[];
short func_80024054(unsigned char *src, short *dst)
{
    short adjustment=0;
    unsigned char lead;
    register unsigned char input __asm__("$2");
    unsigned short glyph;
    short index;
    int offset;
    while ((input=*src++) != 0) {
        switch (input) {
        case 0x81: offset=*src-0x40; __asm__("" : "=r"(offset) : "0"(offset)); glyph=D_80063818[offset]; break;
        case 0x82:
            if (*src<0x9f) { offset=*src-0x4f; __asm__("" : "=r"(offset) : "0"(offset)); glyph=D_800636D8[offset]; }
            else { offset=*src-0x9f; __asm__("" : "=r"(offset) : "0"(offset)); glyph=D_80063770[offset]; }
            break;
        case 0x83:
            lead=*src;
            if (lead<0x80) index=lead-0x40;
            else index=lead-0x41;
            glyph=D_80063770[index]+0x2000;
            break;
        default: goto done;
        }
        switch (glyph&0xc000) {
        case 0x8000:
            *dst++=0x1858;
            *dst++=glyph&0x3fff;
            adjustment+=4;
            break;
        case 0xc000:
            *dst++=0x1850;
            *dst++=glyph&0x3fff;
            adjustment+=4;
            break;
        default: *dst++=glyph; break;
        }
        adjustment-=4;
        src++;
    }
done:
    *dst=-1;
    return adjustment;
}
