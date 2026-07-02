// 来研究一下C中char类型和printf函数
#include<stdio.h>
#define PrintLine printf("\n")

int main(){
    // 字符 & 字符串实验区
    char letter_A = 65; // 等效于 char letter_A = 'A', 在char的'表示范围'内即可
    printf("The value of char 'letter_A' is %d, Its size is %zu Byte. The next letter is '%c'\n", letter_A, sizeof(letter_A), letter_A+1);
    printf("The address of letter_A is now: %p\n", &letter_A);

    // C中的字符串本质上就是'字符数组',但是它的声明可以用各种各样奇怪的方式
    char letter_str[] = "ABCD"; // 常规char数组声明, (可以修改)
    // 以上声明等价于 char letter_str[] = {'A','B','C','D','\0'}, 长度为5, 数组最后一定有个'\0'当'结束符'    
    printf("The address of letter_str is: %p, its size is %zu, the content is: %s\n", (void*)letter_str, sizeof(letter_str), letter_str);
    letter_str[0] = 'E'; // 直接通过下标修改'第0个元素'
    printf("letter_str after changing: %s\n", letter_str); // "EBCD"

    char* single_letter_ptr = &letter_A;
    printf("single_letter_ptr: %c, the address is: %p \n", *single_letter_ptr, single_letter_ptr);

    char* letter_str_ptr = "XYZ"; // 在内存的某个区域中声明一个'只读字符串' (不可修改)
    printf("The address of letter_str_ptr is: %p, its content is: %s, the size is %zu byte\n", (void*)letter_str_ptr, letter_str_ptr, sizeof(letter_str_ptr));

    
    PrintLine;
    // printf 数字输出
    unsigned int hex_num = 0x1bf52; // 定义一个十六进制无符号整数
    printf("The decimal value is: %u\n", hex_num); // %u 无符号十进制整数
    double accuracy_num = 3.14159;
    printf("The fomated accuracy_num is: %5.2f\n", accuracy_num); // 同时限定小数保留位 & 总显示位数 (没有数字的地方被'空格'取代, 整体向右对齐)
}