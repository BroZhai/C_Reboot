#include<stdio.h>
#define PrintLine printf("\n")

// 研究一下scanf()中字符 & 字符串的读取

int main(){
    // 仅读取单个字符
    char a;
    printf("Please enter a char: ");
    scanf("%c", &a);
    printf("char a is: %c\n", a); // 即使输入了一个字符串, 也只会读取'第一个字符'
    // 注: 余下的内容将被被'遗留'到下一个scanf中!
    PrintLine;

    // 读取不含空格的字符串 (将一个长字符串分成'两段'读, 这里仅为演示了解scanf中的'读取buffer')
    char A_buffer[6]; // 存5个字符 (提前定长, 预留一个\0位)
    char B_buffer[101]; // 存100个字符
    printf("Provide any string less than 105 words with NO SPACE: ");
    scanf("\n%5s", A_buffer); // 读前面五个字符, 若仍有剩下的内容, 则会被暂存在scanf的buffer中 等待下一次scanf读取
    // tips: 字符数组变量本身就是'起始字符'的内存地址, 这里就不用'&'再手动取地址啦, 直接传即可 
    scanf("\n%100s", B_buffer); // 读取剩下的字符
    // 数字可以不写, 就是'读全部'

    // 注: %s遇到 '空格'/tab/换行 时将会立即停止读物
    printf("Content in A_buffer: %s\n", A_buffer);
    printf("Content in B_buffer: %s\n", B_buffer);
    PrintLine;

    // 读取含空格的字符串
    char C_buffer[101];
    printf("Type anything but ALL IN CAPITAL LETTER and LESS THAN 100 words! Space is allowed!\n");
    printf("Your input: ");
    scanf("\n%100[A-Z ]", C_buffer); // 规定只读100个字符, 规定只有大写 A-Z, 空格满足'判断条件', 从左到右如遇到'超纲字符'则终止读取
    // e.g. 换行\n, 小写字符 不在上述的'范围中', 故输入小写字符 或 直接换行 则表示'终止读取'
    printf("Content in C_buffer: %s\n", C_buffer);

}