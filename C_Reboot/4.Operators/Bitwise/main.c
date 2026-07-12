#include<stdio.h>
#include"bit_tool.h" // 引入自己写的一个bit操作工具库, 具体实现在'bit_tool.c'

#define PrintLine printf("\n")

int main(){
    // 定义一个 1 Byte长度的负数 (有符号), 再来一个无符号整数, 分别测试右移
    signed char negative = -124; // 补码表示: 1100 0010 (第一个为符号位, 后面7位表示值)
    unsigned char huge_positive = 188; // 二进制表示: 1011 1100 (全8位表示值)

    printf("Original negative value: %d, right shift: %d \n", negative, negative >> 1 );
    printf("Original positive value: %d, right shift: %d \n", huge_positive, huge_positive >> 1 );
    // 在C中, 对所有的'正数'操作都是'逻辑右移', 而有符号负数就是'算术右移'了 XD

    PrintLine;
    // printf("%s\n", show_bin(huge_positive));
    show_bin(2);
}