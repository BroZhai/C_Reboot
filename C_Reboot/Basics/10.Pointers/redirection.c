#include<stdio.h>
#define PrintLine printf("\n")

// 进行一个小实验, 看看指针'重新赋值'到底是个什么东西

int main(){
    // 创建一个指针, 查看其当前指向的内存地址
    char* string = "Hello, this is yellocake :)";
    printf("The address of string is now: %p, and the content is: %s", (void*)string, string);
    PrintLine;

    // 重新对指针赋值, 一般来说, 指针会指向'新内容'的地址
    // string = "Hello, this is yellocake :)"; // 但当'新内容'和原来一样时, 编译器会很聪明的'保持不变' (内容都一样嘛, 为什么我要新建个内存存两个一摸一样的东西 :3)
    string = "Hello, this is yellocake"; // 和'原内容'不一样, 此时string将会指向该'新内容'的起始地址, '原内容'就无人指认了 XD
    printf("The address of string is now: %p, and the content is: %s", (void*)string, string);
}