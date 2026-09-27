/* SC02.CD member31 [80146014,80146074); exact word export. */
/* SC02 member31 [80146014,80146074): process terminated 16-byte records. */
typedef struct Record46014 {
    short rectangle[4];
    unsigned int source;
    unsigned int count;
} Record46014;
extern void func_80059A80(void *, unsigned int, unsigned int);
void func_80146014(Record46014 *record)
{
    while (record->count) {
        func_80059A80(record, record->source, record->count);
        ++record;
    }
}
