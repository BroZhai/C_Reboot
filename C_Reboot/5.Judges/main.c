// 来实践一下C中的各种'判断式'
#include<stdio.h>
#define PrintLine printf("\n");

// C里面将 非0 或 非空 的值定为true, 0 或 null定为false, 其自身并没有'true/false'布尔变量判断
int a=4, b=3;
// int a=4;
int week_index=5;

int main(){
    // 常规if判断
    if(3*a-2*b){ // 0 = false, 不会进入下面的分支, 而直接跳到最下面else的分支
        printf("3 x a - 2 x b is NOT 0! Regarded as a TRUE result \n");
    }else{ 
        printf("3 x a - 2 x b is 0! which has lead a jump to this statement. \n");
    }

    // switch-case
}