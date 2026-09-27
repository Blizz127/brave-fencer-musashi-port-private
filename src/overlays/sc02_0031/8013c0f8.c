/* Complete retail export [8013C0F8,8013C360); C built at -O0, rodata 801B5494. */
typedef struct { unsigned int a,b,c,count; unsigned char *entries; } Group;
typedef union { struct { unsigned int word,a,b; } w; struct { unsigned char pad[3],mode; unsigned int a,b; } h; } Entry;
#define WORD(o) (*(unsigned int *)(resource+(o)))
void func_8013C0F8(unsigned char *resource)
{
    unsigned char *base=resource+20;
    unsigned char *relocated;
    unsigned int i,j;
    Entry *entry;
    Group *group;
    if (!resource[4]) {
        relocated=base+WORD(12);
        WORD(12)=(unsigned int)relocated;
        WORD(16)+=(unsigned int)base;
        group=(Group *)base;
        for(i=0;i<WORD(8);++i,++group) {
            group->entries+=(unsigned int)base;
            entry=(Entry *)group->entries;
            for(j=0;j<group->count;++j,++entry) {
                switch (entry->h.mode) {
                case 0x24: case 0x2C: case 0x34: case 0x3C:
                    entry->w.word=(entry->w.word&0xFFFFFF)+(unsigned int)relocated;
                    break;
                case 0x26: case 0x2E: case 0x36: case 0x3E:
                    entry->w.word=(entry->w.word&0xFFFFFF)+(unsigned int)relocated;
                    break;
                }
            }
        }
        resource[4]=1;
    }
}
