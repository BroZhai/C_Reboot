#include<stdio.h>
#define PrintLine printf("\n")

// 专门来研究一下scanf()函数, 处理各种不同的用户输入
// scanf()和printf()使用方法类似, printf()是按'特定格式'输出, scanf()则是要求用户'按指定格式'输入
// 该文件专门用于研究'整数'的读入

int main(){
    // 常规读入一个有符号十进制整数 %d
    signed int a;
    printf("Please enter a randon decimal number: ");
    scanf("%d", &a); // scanf利用变量a的'地址'将值映射到变量a上去
    printf("The value of signed int a in DECIMAL is: %d\n", a);
    PrintLine;

    // 读入一个无符号十进制整数 %u (输入负值将会得到一个巨大的值)
    unsigned int b;
    printf("Please enter another decimal number (tips: value can be negative): ");
    scanf("%u", &b);
    printf("The value of UNsigned int a in DECIMAL is: %u\n", b);
    PrintLine;

    // (补充)有符号数和无符号数的比较 (数值表现范围更'小'的一方会向'大'的那一方"对齐)
    //  unsigned int > signed int, 所以signed int 在比较时会被强转成 unsigned int
    printf("a is reset to -1, and b is reset to 1.\n");
    a=-1, b=1;
    printf("Is a > b: %s\n", (a>b)? "Yes, since signed int a is converted to unsigned int during the comparision!":"No");

    // 读入一个十进制小数(float浮点 %f, 输入精度上限为6位)
    float c;
    printf("Please enter a float within 6 decimals: ");
    scanf("%f");
}