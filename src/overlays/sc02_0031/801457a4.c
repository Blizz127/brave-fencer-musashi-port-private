/* Complete SC02 member31 selector [801457A4,801458E0). */
extern unsigned int D_80184C24[];
unsigned int func_801457A4(int id)
{
    switch (id) {
    case 0x1010:
    case 0x1052:
    case 0x1077:
    case 0x1094:
    case 0x2013:
    case 0x2015:
    case 0x2016:
    case 0x2017:
    case 0x2018:
    case 0x2019:
    case 0x201A:
    case 0x2055:
    case 0x2056:
    case 0x2057:
    case 0x2058:
    case 0x2059:
    case 0x205A:
    case 0x205B:
    case 0x207A:
    case 0x207B:
    case 0x207C:
    case 0x207D:
    case 0x207E:
    case 0x207F:
    case 0x2080:
    case 0x2097:
    case 0x2098:
    case 0x2099:
    case 0x209A:
    case 0x209B:
    case 0x209C:
    case 0x209D:
        return D_80184C24[id & 0xFFFF0FFF];
    default:
        return D_80184C24[0];
        break;
    }
}
