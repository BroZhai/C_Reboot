// 来研究一下C中的各种数据类型
#include<stdio.h>
#define PrintLine printf("\n")

int main(){
    // int研究区
    int baka = 9999; // 默认的int声明被视为一个'有符号数', 4 Byte, 范围 2^-31 - 2^31-1
    // 上述写法等价于 signed int baka = 9999; / signed long int baka = 9999; (long本来就是4Byte嘛 XD)
    unsigned short int short_baka=99; // short强制限定'只用2Byte', 范围 2^-15 - 2^15-1
    unsigned long long int long_baka=99999999; // long是4Byte, 那么4Byte + 4Byte就是64位了, 范围 2^-63 - 2^63-1

    // 小数研究区 (小数并不存在'符号', 且需要较长的bit位'保留精度')
    float genius = 6.123456; // 单精度浮点, 4Byte, 精度为6位有效位
    double super_genius = 11.45141919810; // 双精度浮点, 8Byte, 精度为15位有效位
    long double extra_genius = 9.876543210123456789; // 劲爆混合小数, 16Byte, 精度为19位有效位
    
    printf("The size of int 'baka' is: %ld\n", sizeof(baka)); // 4 Byte
    printf("The size of short int 'baka' is: %ld\n", sizeof(short_baka)); // 2 Byte
    printf("The size of long long int 'baka' is: %lu\n", sizeof(long_baka)); // 8 Byte
    PrintLine;

    printf("The value of float 'genius' is: %f, and the size is: %ld\n", genius, sizeof(genius)); // 4Byte
    printf("The value of double 'super_genius' is: %f, and the size is: %ld\n", super_genius, sizeof(super_genius)); // 8Byte
    printf("The value of long double 'extra_genius' is: %Lf, and the size is: %ld\n", extra_genius, sizeof(extra_genius)); // 16Byte
    // Tips: 上面的%Lf在Linux可以正常显示, Winodws MSVC中不行
}