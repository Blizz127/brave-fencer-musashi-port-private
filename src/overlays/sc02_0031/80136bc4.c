/* Complete retail export [80136BC4,80136C1C). */
void func_80136BC4(unsigned int *data)
{
    if (data[2] == 0x20) {
        data[2] = (unsigned int)data + 0x20;
        data[3] += (unsigned int)data;
        data[4] += (unsigned int)data;
        data[5] += (unsigned int)data;
        data[6] += (unsigned int)data;
        data[7] += (unsigned int)data;
    }
}
