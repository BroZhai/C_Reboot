// 来看看各种常见的'算术运算符'
#include<stdio.h>
#define PrintLine printf("\n")


int main(){
    int v1= 2+3*6/9; // 先算乘除, 后算加减, 两边都遵循'从左往右'的顺序
    printf("v1: %d\n", v1); // v1 = 4

    // ++前置自增 && 后置自增-- (自减同理)
    int v2=5;
    int v3=v2++; // 后置自增: 先把v2的值给v3, 随后再自增 (相当于命令行中 v3=v2 && v2+1)
    int v4=++v2; // 前置自增: 先把v2+1, 随后再给v3 (等效于 v3 = v2+1)
    printf("v3: %d, v4: %d\n", v3, v4);

    // 三元运算符
    int v5= (v3==5 && v4==7) ? 1919:810; // (条件) ? true值:false值
    printf("v5: %d\n", v5); // 1919 
}