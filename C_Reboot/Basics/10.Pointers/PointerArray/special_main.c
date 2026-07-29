#include<stdio.h>
#define PrintLine printf("\n")

// 这里来专门研究一下main的另一种形式
// 之前写的main()都不带形参, 这里main同时带了两个形参, 用于获取'命令行'的额外输入
// int argc = 额外指令的共计数目
// char* argv[] 指针数组: 因为命令行每个输入的指令'长度不确定', 但都是char, 这里便可以用 char*指针数组来 灵活分配内存给这些指令 & 灵活调用它们

int main(int argc, char* argv[]){
    if(argc < 3){
        printf("Please provide 3 or more command input! Seperated by SPACE!\n");
        return 0;
    }
    printf("The argc count is: %d \n", argc);
    PrintLine;

    printf("The first command: %s\n", *(argv)); 
    printf("The second command: %s\n", *(argv+1));
    printf("The third command: %s\n", *(argv+2));
    // printf("The pointer address to Last command: %p \n", (void*)&argv[argc-1]);  // 指针指向最后的'内容地址'
    // printf("The content of argv[argc-1] is: %p \n", (void*)argv[argc-1]); // 最后一个内容 (所表示的'地址')
    // printf("The dereferenced content of argv[argc-1] is: %c \n", 8(argv[argc-1])); // 最后一个内容地址的'解引用', 得内容的值
    printf("The LAST command is: %s \n", argv[argc-1]);
}