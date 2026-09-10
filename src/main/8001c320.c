/* Exact retail [8001C320,8001C448). */
/* Retail [8001C320,8001C448): initialize object and optional resource list.
 * GCC 2.7.2 / ASPSX 2.56 -O2 -G0: exact 74-word match.
 * Empty constraints preserve register allocation and memory scheduling;
 * no instruction assembly is emitted. Names describe observed field use.
 */
typedef struct Object {
 short state, enabled; unsigned char pad[0x1c];
 void *table; unsigned int *resources; unsigned char pad2[6]; short count;
 unsigned char transform[32];
} Object;
extern unsigned char D_800AF630[],D_80063548[],D_800A5BD0[];
extern unsigned short D_800AF7CC;
extern void *D_800AF7C8;
extern void func_8001C9D0(Object *),func_80052D90(int,void *),func_80054514(void *,void *);
extern void func_80053290(void *),func_800553D8(void *,void *,int);
extern void *func_800553F4(void *,void *);
void func_8001C320(Object *object,unsigned int *resources)
{
 unsigned char scratch[32];
 register unsigned char *state __asm__("$20");
 register void *next __asm__("$19");
 func_8001C9D0(object);
 object->state=1; object->enabled=1;
 func_80052D90(0,object->transform);
 func_80054514(object->transform,scratch);
 state=D_800AF630;
 object->resources=resources;
 if(resources) {
  object->table=D_80063548;
  __asm__ volatile("" : : : "memory");
  object->count=D_800AF7CC;
  next=D_800AF7C8;
  __asm__("" : : "r"(state), "r"(next));
  while(*resources) {
   unsigned char *entry=(unsigned char *)((*resources++ & 0x80FFFFFF)+4);
   unsigned char *destination;
   __asm__("" : "=r"(entry) : "0"(entry));
   func_80053290(entry);
   destination=D_800A5BD0+((*(unsigned short *)(state+0x19c))++)*20;
   func_800553D8(entry+8,destination,0);
   next=func_800553F4(destination,next);
  }
  *(void **)(state+0x198)=next;
 }
}

