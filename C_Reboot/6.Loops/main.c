#include<stdio.h>
#define PrintLine printf("\n")

// 可以说C的循环结构奠定了所有其他变成语言的循环结构, 基本是一样的, 这里简单过一下

int main(){
    int count=1;
    // for 循环
    for(int i=4; i>=0; i--){ // 执行5次
        printf("For loop %d time execution.\n", count);
        count++;
    }

    PrintLine;
    count=1;
    // while 循环
    // Tips: while中的循环判断也是一个'整数值', 0 break 非0继续
    while(count<3){ // 执行2次
        printf("While loop %d time execution.\n", count);
        count++;
    }

    PrintLine;
    // do...while循环 (先执行一遍再看看循不循环)
    count=1;
    do{
        count++;
        printf("do while won't do loop here, this is the entry execution.\n");
    }while(count<2);

}