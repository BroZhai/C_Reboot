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
    show_bin(-8);

    PrintLine;
    // 位运算符实验区
    signed char v1=12; // 0000 1100
    signed char v2=9;  // 0000 1001
    show_bin(v1);
    show_bin(v2);

    signed char and_result= v1&v2;
    signed char or_result= v1|v2;
    signed char xor_result= v1^v2;

    PrintLine;
    printf("The result of v1 AND v2 is: %d, which ", and_result); // 8 -> 0000 1000
    show_bin(and_result);
    printf("The result of v1 OR v2 is: %d, which ", or_result);
    show_bin(or_result);
    printf("The result of v1 XOR v2 is: %d, which ", xor_result);
    show_bin(xor_result);
}