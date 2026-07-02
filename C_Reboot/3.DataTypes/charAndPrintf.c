// 来研究一下C中char类型和printf函数
#include<stdio.h>
#include<string.h> // "String"字符串的相关操作工具箱 (用了strlen(), 返回 64位unsigned int [size_t宏])
#define PrintLine printf("\n")

int main(){
    // 字符 & 字符串实验区
    char letter_A = 65; // 等效于 char letter_A = 'A', 在char的'表示范围'内即可
    printf("The value of char 'letter_A' is %d, Its size is %zu Byte. The next letter is '%c'\n", letter_A, sizeof(letter_A), letter_A+1);
    printf("The address of letter_A is now: %p\n", &letter_A);
    // char* single_letter_ptr = &letter_A;
    // printf("single_letter_ptr: %c, the address is: %p \n", *single_letter_ptr, single_letter_ptr);

    PrintLine;
    // C中的字符串本质上就是'字符数组',但是它的声明可以用各种各样奇怪的方式
    char letter_str[] = "ABCD"; // 常规char数组声明, (可以修改)
    // 以上声明等价于 char letter_str[] = {'A','B','C','D','\0'}, 长度为5, 数组最后一定有个'\0'当'结束符'    
    printf("The address of letter_str is: %p, its size is %zu, the content is: %s\n", (void*)letter_str, sizeof(letter_str), letter_str);
    letter_str[0] = 'E'; // 直接通过下标修改'第0个元素'
    printf("letter_str after changing: %s\n", letter_str); // "EBCD"

    char* letter_str_ptr = "VWXYZ"; // 在内存的某个区域中声明一个'只读字符串' (不可修改)
    // 细节补充: 在上面声明"XYZ"字面量时, C在内存中会直接'提前分配好'对应的内存地址, 同时左边的char*指针记录下该'自动分配'的内存地址 (首个字符的'起始地址')
    // 字符串在内存中的'存储地址'是连续的, 指针会指向'起始字符'的内存地址
    printf("The address of letter_str_ptr is: %p, its content is: %s, the size of char* POINTER is %zu byte\n", (void*)letter_str_ptr, letter_str_ptr, sizeof(letter_str_ptr));
    // 在printf()中%s输出时, %s期待的就是一个'起始字符'的内存地址, 随后会自动往后继续读'后续的字符', 直至遇到'\0'终止
    
    // 大小为8Byte!? 没错, 因为这里是char*'指针地址'的长度, 在64位的操作系统上就是8Byte, 而不是其'字符串内容'的长度 (字符串内容的长度仍为6Byte {'V','W','X','Y','Z','\0'})
    printf("The real CONTENT SIZE calculated by strlen (letter_str_ptr) is: %zu Byte\n", strlen(letter_str_ptr)); 
    // 这里用到<string.h>中的strlen()方法, 输入一个'起始字符'内存地址, 会自动统计返回'字符串的大小', 类型为 size_t (64位unsigned int)
    // 注: 因为strlen不统计'\0', 故这里实际返回的是 5 Byte, 而sizeof()则会'统计所有'

    printf("The first char in letter_str_ptr is: '%c'\n", *letter_str_ptr);
    // 既然 char* 指向的是首个'起始字符'的内存地址, 我们直接对其'解引用'即可得到对应的'起始字符'

    
    PrintLine;
    // printf 数字输出
    unsigned int hex_num = 0x1bf52; // 定义一个十六进制无符号整数
    printf("The decimal value is: %u\n", hex_num); // %u 无符号十进制整数
    double accuracy_num = 3.14159;
    printf("The fomated accuracy_num is: %5.2f\n", accuracy_num); // 同时限定小数保留位 & 总显示位数 (没有数字的地方被'空格'取代, 整体向右对齐)
}