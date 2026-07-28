#include<stdio.h>
#define PrintLine printf("\n")

// 这里来专门研究一下main的另一种形式
// 之前写的main()都不带形参, 这里main同时带了两个形参, 用于获取'命令行'的额外输入
// int argc = 额外指令的共计数目
// char* argv[] 指针数组: 因为命令行每个输入的指令'长度不确定', 但都是char, 这里便可以用 char*指针数组来 灵活分配内存给这些指令 & 灵活调用它们

int main(int argc, char* argv[]){
    
}