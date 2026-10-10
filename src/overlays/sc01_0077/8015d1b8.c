/* sc01_0077: func_8015D1B8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 arg0);
extern void func_801477E8(s32 *a0, s32 a1);
extern u16 func_80148800(s32 *a0);
extern void func_80149724(void);
extern s32 func_80149FB0(s32 a0);
extern void func_8014E6A0(void);
extern void func_8014FA04(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
void func_8014FA04(s32 a0);
extern void (*D_801891B8[])(void *);
extern void func_80159B70(void *a0);
extern void (*D_801891B8[])(void *);
extern s32 func_80149FB0(s32 a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147324(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void (*D_801891B8[])(void*);
extern s32 func_80149FB0(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void (*D_801891B8[])();
extern s32 func_80149FB0(s32 a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void (*D_801891B8[])(void*);
void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 arg0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80149724(void);
extern s32 func_80149FB0(s32 a0);
extern void func_8014FA04(s32 a0);
extern void func_80159B70(void *a0);
void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_80149FB0(s32 a0);
extern void func_8014FA04(s32 a0);
extern void func_8014E6A0(void);
extern void (*D_801891B8[])(void *);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern s32 func_801725F4(u8 *a0);
extern s32 func_80149FB0(s32);
extern void func_80147324(s32 a0);
extern u16 func_80148800(s32 *a0);
extern void func_80149724(void);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146DB8(s32*, s32*);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_8014FA04(s32);
extern void func_8014E6A0(void);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void*);
extern void func_8015D380(s32);
extern s32 func_801725F4(u8 *a0);
extern void (*D_801891B8[])(void*);
extern s32 D_80189398;
extern s32 D_8018939C;
extern s32 D_801893E0;
extern s32 D_800D4C14;
void func_8015D380(s32 a0);

void func_8015D1B8(s32 *a0)
{
    s32 sum;
    s32 keep;
    s32 obj;
    s16 cur;
    s16 prev;
    s16 d;
    s32 off;
    s32 *p;
    s32 dummy[2];
    ((void (*)(void))func_80149FB0)();
    obj = *(s32 *)((u8 *)a0 + 0x20);
    sum = *(u16 *)(obj + 0x10) + *(u16 *)((u8 *)a0 + 0x236);
    *(u16 *)(obj + 0x10) = sum & 0xFFF;
    keep = sum;
    cur = *(s16 *)(*(s32 *)((u8 *)a0 + 0x20) + 0x10);
    prev = *(s16 *)((u8 *)a0 + 0x244);
    if (cur - prev >= 0) {
        d = cur - prev;
    } else {
        d = prev - cur;
    }
    if (d > 0x800) {
        func_80147324(0x5E9);
    }
    *(u16 *)((u8 *)a0 + 0x244) = *(u16 *)(*(s32 *)((u8 *)a0 + 0x20) + 0x10);
    if (func_80148800(a0) & 0x40) {
        ((void (**)(s32*))D_801891B8)[*(u16 *)a0](a0);
        ((void (*)(s32 *))func_80149724)(a0);
        func_80154274(a0, (s32)&D_800D4C14);
        func_80146E90(a0, 0x10);
        {
            u32 t = keep & 0xFFF;
            if ((s32)t < 0) {
                t += 0x1FF;
            }
            p = &D_801893E0;
            off = (t >> 9) * 8;
        }
        *p = *(s32 *)((u8 *)&D_80189398 + off);
        ((void (*)(s32 *, s32))func_80146DB8)(a0, (s32)(p - 2));
        func_801477E8(a0, *(s32 *)((u8 *)&D_8018939C + off));
        func_80147324(0x5EA);
    } else {
        ((void (*)(s32 *))func_8014FA04)(a0);
        if (((s32 (*)(s32 *))func_8014E6A0)(a0) == 0) {
            ((void (**)(s32*))D_801891B8)[*(u16 *)a0](a0);
            func_80147078(a0, 0);
            ((void (*)(s32 *))func_80159B70)(a0);
        } else {
            ((void (*)(s32 *))func_8015D380)(a0);
            func_801725F4(a0);
        }
    }
}
