#include<stdio.h>
#define PrintLine printf("\n")

// 专门来研究一下scanf()函数, 处理各种不同的用户输入
// scanf()和printf()使用方法类似, printf()是按'特定格式'输出, scanf()则是要求用户'按指定格式'输入
int main(){
    char input_char;
    int input_int;

    printf("Please enter a char: ");
    scanf("%c", &input_char);
    printf("%c\n", input_char);

    PrintLine;
    printf("Plesae enter a decimal | octal | hexadecimal number(e.g., ): ");
    scanf("%i", &input_int);
    printf("%d\n", input_int);

    return 0;
}