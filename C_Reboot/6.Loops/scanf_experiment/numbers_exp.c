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
    // 上面在进行比较时, 有符号数-1 将会被转成对应的无符号数进行对比, C自动将左侧的 signed int 对齐了右侧的 unsigned int
    PrintLine;

    // 读入一个十进制小数(float浮点 %f, 输入精度上限为6位)
    float c;
    printf("Please enter a float within 6 decimals: ");
    scanf("%f", &c);
    printf("The entered float is: %f\n", c);
    PrintLine;

    // 在scanf()中要用户输入一个'%' (scanf消费 & 匹配判定)
    signed int d=0,e=0;
    printf("Please enter a value with the following format, otherwise some value may be fail to be assigned.\n");
    printf("Format: value d is XXX%% and e is XXX%%\n");
    printf("Your input: ");
    scanf("\nvalue d is %d%% and e is %d%%", &d, &e); // 如果没有按照指定的格式写, 那么此时scanf()将在'不匹配'的地方停止读入, 也终止后续的读入
    // 这里因为是自己写的判定格式, 所有要自己'手动处理'上一个scanf输入'遗留下'的\n, 自己放在判定的开头
    printf("The value of int d is: %d, and e is: %d\n", d, e);
}