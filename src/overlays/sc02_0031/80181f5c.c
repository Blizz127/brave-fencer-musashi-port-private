/* Complete SC02 table lookup; independently matched ordinary C. */
/* Complete SC02 member 31 [80181F5C,80181FA4), 18 words. */
typedef struct Object { unsigned char pad[0xdc]; int variant; } Object;
typedef struct Entry { int key, value; } Entry;
int func_80181F5C(Object *object, Entry *entry)
{
    int key=object->variant;
    while (entry->key!=key) {
        entry++;
        if (entry->key==0) return key;
    }
    return entry->value;
}
