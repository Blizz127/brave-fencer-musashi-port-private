/* SC02.CD member31 [801468C8,80146924); exact word export. */
/* SC02 member31 [801468C8,80146924): register in the first free of two slots. */
typedef struct Slot { unsigned char active; unsigned char pad[3]; void *value; unsigned char rest[0x24]; } Slot;
extern Slot D_8011F750[];
Slot *func_801468C8(void *value, unsigned char active)
{
    int i;
    for (i=0;i<2;++i) {
        if (!D_8011F750[i].active) {
            D_8011F750[i].value=value;
            D_8011F750[i].active=active;
            return &D_8011F750[i];
        }
    }
    return 0;
}
