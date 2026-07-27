#include<stdio.h>

// 研究一下goto的用法, 其实很像汇编
// 在任何语言中goto的写法都能写成其他更加简单的语句, 降低人的理解难度
// 这里仅为拓展了解

int main(){
    int count=0;
    My_action:
        if(count<5){
            printf("Current count value: %d\n", count);
            count++;
            goto My_action;
        }
    // 上述写法完全可以写成一个简单的for循环 XD
}