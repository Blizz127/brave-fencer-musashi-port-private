/* Exact retail word export for [8005AB00,8005AB58); EXE and assembly verified. */
extern unsigned char D_80072788;
unsigned int func_8005AB00(int first,int second,unsigned short mode) {
 unsigned int command;
 register unsigned int bits __asm__("$2");
 if ((unsigned int)(D_80072788-1)<2) {
  command=0xe1000000;
  if(second) command|=0x800;
  bits=mode&0x27ff;
  if(first) bits|=0x1000;
 } else {
  command=0xe1000000;
  if(second) command|=0x200;
  bits=mode&0x9ff;
  if(first) bits|=0x400;
 }
 __asm__("" : "=r"(bits) : "0"(bits));
 return command|bits;
}
