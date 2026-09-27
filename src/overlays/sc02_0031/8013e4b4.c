/* Complete SC02 entry reset; independently matched ordinary C. */
typedef struct { unsigned short pad[3], active, other, flags; unsigned char tail[8]; } Entry;
extern Entry *D_801274C8, *D_801274CC;
extern void func_8012C750(Entry *);
void func_8013E4B4(void)
{
    Entry *entry = D_801274C8;
    if (entry) {
        while (entry->active) {
            func_8012C750(entry);
            entry++;
        }
    }
    entry = D_801274CC;
    if (entry) {
        while (entry->active) {
            entry->flags &= 0x7fff;
            entry++;
        }
    }
}
