/* Native retail instruction export [80059888,8005991C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* ClearImage, retail [80059888,8005991C).
 * GCC 2.7.2 / ASPSX 2.56 -O2 -G0: exact 37-word retail match.
 * Unsigned-byte color arguments preserve retail argument scheduling.
 * D_80074178 is the retail NUL-terminated string "ClearImage".
 */
typedef struct OperationTable {
    unsigned int unknown[2];
    int (*dispatch)(void *, void *, int, unsigned int);
    void *context;
} OperationTable;
extern OperationTable *D_80072780;
extern char D_80074178[];
extern void func_80059760(char *, void *);
int func_80059888(void *request, unsigned char red, unsigned char green, unsigned char blue)
{
    func_80059760(D_80074178, request);
    return D_80072780->dispatch(D_80072780->context, request, 8,
        ((blue & 255) << 16) | ((green & 255) << 8) | (red & 255));
}

