/* func_80010178: func_8001D70C from Druthulu/BFM-decomp
 * src/src/800.c (preprocessed; only the declarations it uses),
 * byte-identical to the func_80010178 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    u8 minute;
    u8 second;
    u8 sector;
    u8 track;
} CdlLOC;
typedef struct {
    CdlLOC pos;
    u32 size;
    char name[16];
} CdlFILE;
extern CdlFILE *func_80045374(CdlFILE *fp, char *name);
extern int func_80043B1C(CdlLOC *p);
extern CdlLOC *func_80043A18(int i, CdlLOC *p);
extern int func_8004239C(int mode);
extern s32 func_80034B98(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern int func_8004239C(int mode);
extern void func_80019990(void);
extern void func_8004978C(s16 *a0, void *a1);
extern u8 D_800747A0;
extern u8 D_800747A4;
extern u8 *D_800747AC;
extern u32 D_800747B0;
extern u16 D_800747B4;
extern u32 D_800C7D24;
s32 func_80018730(u8 *src);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_800747D0;
extern s32 D_800747D0;
extern s32 D_800747D4;
extern s32 D_800747D4;
extern void func_80019990(void);
extern int func_8004239C(int mode);
extern s32 func_80019A24(int *cdlFile, void *dest, s32 size, s32 mode);
extern u8 D_80062C38;
extern u8 D_80062C68;
extern s32 D_800747D0;
extern s32 D_80063074;
extern s32 D_800747D8;
extern u8 D_800AE830[];
extern u8 D_800AE834;
extern void func_80019990(void);
extern int func_8004239C(int mode);
extern s32 func_80019A24(int *cdlFile, void *dest, s32 size, s32 mode);
extern CdlFILE D_80063058;
extern u8 D_80062C38;
extern u8 D_80062C68;
extern s32 D_800747D0;
extern s32 D_800747D4;
extern s32 D_80063074;
extern s32 D_800747D8;
extern u8 D_800AE830[];
extern u8 D_800AE834;
void func_8001971C(void);
extern s32 D_800AE728;
extern s32 D_800AE6F0;
extern s32 D_800AE6F8;
extern s32 D_800AE6FC;
extern s32 D_800AE700;
extern s32 D_800AE748;
extern s32 D_800AE74C;
extern u8 D_800AE798;
extern u8 D_800AE799;
extern s32 D_800AE70C;
extern s32 D_800AE728;
extern s32 D_800AE708;
extern s32 D_800AE6F0;
extern s32 D_800AE6F8;
extern s32 D_800AE6FC;
extern s32 D_800AE700;
extern s32 D_800AE748;
extern s32 D_800AE74C;
extern u8 D_800AE798;
extern u8 D_800AE799;
extern s32 D_800AE70C;
extern s32 func_80034B98(void);
extern void func_80019AF8(int);
extern s32 D_800AE708;
extern void *D_800AE72C;
extern s32 D_800AE7A8;
extern void *D_800AE7A4;
extern s32 D_800AE7B0;
extern s32 D_800AE720;
extern s32 D_800AE724;
s32 func_80019A24(int *cdlFile, void *dest, s32 size, s32 mode);
extern s32 func_800435CC(s32 mode, void *buf, void *param);
extern s32 func_8004355C(s32 mode, u8 *result);
extern void *func_800435B4(void *func);
extern void func_800434BC(void);
extern void func_8001A338(u8);
extern s32 func_8002FD14(s32, s32);
extern void func_8001A0FC(void);
extern s32 func_8001A114(void);
extern s32 D_800AE6F0;
extern s32 D_800AE750;
extern s32 D_800AE7B0;
extern u8 D_800AE738;
extern void *D_800AE7A4;
extern s32 D_800AE7AC;
extern s32 D_800AE754;
extern s32 D_800AE7A8;
extern void *D_800AE72C;
extern s32 D_800AE728;
extern s32 D_800AE748;
extern s32 D_800AE74C;
extern void *D_800AE734;
extern s32 D_800AE708;
extern s32 D_800AE6E8;
extern s32 D_800AE6F8;
extern s32 D_800AE6FC;
extern s32 D_800AE700;
extern s32 D_800AE70C;
extern s32 D_800AE71C;
extern s32 D_800AE724;
extern u8 D_800AE798;
extern u8 D_800AE799;
void func_80019AF8(s32 pauseAfterSeek);
extern s32 D_800AE6F4;
extern s32 D_800AE70C;
void func_8001A0FC(void);
extern void func_800434BC(void);
extern s32 D_800AE6F4;
extern u8 D_800AE738;
extern int D_800AE750;
int func_8001A114(void);
typedef struct XRECT {
           u16 x;
           u16 y;
           u16 w;
           u16 h;
} XRECT;
typedef struct CdReq {
           s32 state;
           s32 unk04;
           s32 phase;
           s32 unk0C;
           s32 unk10;
           s32 texIdx;
           s32 unk18;
           s32 unk1C;
           XRECT rect;
           XRECT *rectp;
           s32 count;
           s32 busy;
           s32 list;
           s32 sink;
           s32 dest;
           s32 unk40[6];
           s32 words;
           s32 drain;
           s32 unk60[2];
           u8 mask[0x40];
           u8 flags;
           u8 unkA9;
           u8 bit;
           u8 byteIdx;
           s32 unkAC[3];
           s32 size;
           s32 posInt;
} CdReq;
extern s32 D_800AE6F0;
extern s32 D_800AE7AC;
extern s32 D_800AE74C;
extern s32 D_800AE6F8;
extern u8 D_80078E40[];
extern u32 D_80079A70[];
extern u8 D_80079A74;
extern u8 D_80079A75;
extern s32 D_80079A78;
extern s32 D_80079A7C;
extern u32 D_8007A280[];
extern void *D_80072C80;
extern s32 func_80043994(void *buf, s32 n);
extern s32 func_8002FB08(s32 a0);
extern s32 func_8002FC64(s32 a0, u32 *a1);
extern void func_8002FDC8(void);
extern void func_80018714(void *);
extern s32 func_80018730(u8 *src);
void func_8001A338(u8 reason);
extern s32 func_80034B98(void);
extern s32 D_800AE708;
extern s32 D_800AE708;
extern u8 D_80062C38;
extern s32 D_800A654C;
extern s32 D_800747F8;
extern u8 D_80063138[];
extern u8 D_8006313C;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_800A6430;
extern s32 D_800A654C;
extern s32 D_800747F8;
extern u8 D_80063138[];
extern u8 D_8006313C;
extern void func_8002D4C8(int arg0, int arg1);
extern s32 D_800AE708;
extern void *D_800AE72C;
extern s32 D_800AE7A8;
extern void *D_800AE7A4;
extern s32 D_800AE724;
extern s32 D_800AE720;
extern s32 D_800AE7B0;
extern s32 D_800A6430;
extern s16 D_800A6430_h __asm__("D_800A6430");
extern s32 func_80034B98(void);
extern void func_80019AF8(int);
extern s32 func_80034B98(void);
extern int func_8001A114(void);
extern s32 D_800C6D34;
extern s32 D_800C6D10;
extern s32 D_800C6D34;
extern s32 D_800C6D10;
extern s32 D_800AE7EC;
extern s32 D_800A654C;
extern s32 D_800747F8;
extern s32 D_800A654C;
extern s32 D_800AE7EC;
extern s32 D_800C6D34;
extern s32 D_800C6D10;
extern void func_8001B3C4(void);
extern int func_8001A114(void);
extern void func_8001B710(void);
extern void func_8002D4C8(int arg0, int arg1);
extern void func_80036D58(s16);
extern int func_800363CC(int arg0, void *loc, int n);
extern s32 func_80034B98(void);
extern s32 func_8001B788(s16 arg0);
extern s32 D_800AE7EC;
extern s32 D_800C6D34;
extern s32 D_800A654C;
extern s32 D_800747F8;
extern s32 D_800C6D10;
extern s32 D_800AE708;
extern u8 D_80063138[];
extern u8 D_8006313A;
extern u8 D_8006313C;
extern u8 D_800AE830[];
extern s32 D_800AE6F4;
extern s32 D_800AE70C;
typedef struct {
    s16 v;
    s16 pad[2];
} ResMapCol;
extern ResMapCol aResourceIdMap[] __asm__("D_80063138");
extern ResMapCol aD_8006313A[] __asm__("D_8006313A");
extern ResMapCol aD_8006313C[] __asm__("D_8006313C");
void func_8001B3C4(void);
void func_8001B710(void);
extern u8 D_80063138[];
extern u8 D_800AE830[];
extern s32 func_80034B98(void);
extern void func_80019AF8(int);
extern s32 D_800AE708;
extern void *D_800AE7A4;
extern s32 D_800AE7B0;
extern s32 D_800AE70C;
extern s32 func_80034B98(void);
extern int func_8004239C(int mode);
extern s32 D_800AE708;
extern s32 func_80034B98(void);
extern void func_8002D4C8(int arg0, int arg1);
extern s32 D_80063074;
extern s32 D_80063074;
extern s32 D_800747D8;
extern s32 D_800747D8;
extern void func_8001CFDC(s32 a0, s32 a1);
void *func_8001CFDC_impl(s32 func_80010000, s32 end) __asm__("func_8001CFDC");
void *func_8001CFDC_impl(s32 func_80010000, s32 end);
extern void func_8001D074(s32 a, s32 b);
s32 func_8001D074_impl(s32 arg0, s32 arg1) __asm__("func_8001D074");
s32 func_8001D074_impl(s32 arg0, s32 arg1);
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro mvmva sf, mx, v, cv, lm\n"
    "    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

void func_8001D70C(s32 param_1)
{
    s32 matrix[8];  /* sp+0x10 */  /* retail 8001D724: addiu a1, sp, 0x10 */
    s16 sc[20];     /* sp+0x30 */  /* retail: sh v0, 0x30(sp); sh zero, 0x32(sp) */
    func_8004978C((s16 *)(param_1 + 0x10), (void *)matrix);
    sc[0] = *(u16 *)(param_1 + 0x18);
    sc[1] = 0;
    sc[2] = 0;
    sc[3] = 0;
    sc[4] = *(u16 *)(param_1 + 0x1A);
    sc[5] = 0;
    sc[6] = 0;
    sc[7] = 0;
    sc[8] = 0x1000;
    __asm__ volatile (
        "lw $12, 0(%0);"
        "lw $13, 4(%0);"
        "ctc2 $12, $0;"
        "ctc2 $13, $1;"
        "lw $12, 8(%0);"
        "lw $13, 12(%0);"
        "lw $14, 16(%0);"
        "ctc2 $12, $2;"
        "ctc2 $13, $3;"
        "ctc2 $14, $4;"
        "addiu $2, $sp, 0x30;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0(%0);"
        "sh $13, 6(%0);"
        "sh $14, 12(%0);"
        "addiu $2, $sp, 0x32;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "addiu $2, $sp, 0x12;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0($2);"
        "sh $13, 6($2);"
        "sh $14, 12($2);"
        "addiu $2, $sp, 0x34;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "addiu $2, $sp, 0x14;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0($2);"
        "sh $13, 6($2);"
        "sh $14, 12($2);"
        : : "r"((s32)matrix) : "$12", "$13", "$14", "$2", "memory");
    *(s32 *)((u8 *)matrix + 0x14) = *(s16 *)(param_1 + 8);
    *(s32 *)((u8 *)matrix + 0x18) = *(s16 *)(param_1 + 10);
    *(s32 *)((u8 *)matrix + 0x1C) = *(s16 *)(param_1 + 12);
    __asm__ volatile (
        "lw $12, 0(%0);"
        "lw $13, 4(%0);"
        "ctc2 $12, $0;"
        "ctc2 $13, $1;"
        "lw $12, 8(%0);"
        "lw $13, 12(%0);"
        "lw $14, 16(%0);"
        "ctc2 $12, $2;"
        "ctc2 $13, $3;"
        "ctc2 $14, $4;"
        "lw $12, 20(%0);"
        "lw $13, 24(%0);"
        "ctc2 $12, $5;"
        "lw $14, 28(%0);"
        "ctc2 $13, $6;"
        "ctc2 $14, $7"
        : : "r"((s32)matrix) : "$12", "$13", "$14", "$2");
}
