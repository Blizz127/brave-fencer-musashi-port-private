/* Exact retail [80053290,80053308). */
/* Retail [80053290,80053308): relocate three offsets per resource entry once. */
typedef struct Entry { unsigned int first, pad0, second, pad1, third, pad2, pad3; } Entry;
void func_80053290(unsigned int *data)
{
    volatile int unused;
    int i, count;
    Entry *entry;
    if (!(data[0] & 1)) {
        data[0] |= 1;
        ++data;
        i = 0;
        count = *data;
        ++data;
        if (count > 0) {
        entry = (Entry *)data;
        do {
            ++i;
            __asm__("" : "=r"(entry) : "0"(entry));
            entry->first += (unsigned int)data;
            entry->second += (unsigned int)data;
            entry->third += (unsigned int)data;
            ++entry;
        } while(i<count);
        }
    }
}

