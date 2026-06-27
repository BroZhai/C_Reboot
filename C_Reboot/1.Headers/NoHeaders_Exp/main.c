#include<stdio.h> // 从'系统C库'中引入printf

// 不引入.h头文件, 直接硬写要用的'方法签名' (理论上只要提供了对应的"实现"文件, GCC在最终编译时就能找到)
extern int value_in_header;
int num_sum(int a, int b);
int num_sub(int a, int b);

// int value_in_header=114;
int main(){
    printf("The value provided in the header file is: %d\n", value_in_header);
    int a=5, b=4;
    printf("Value a = %d, b = %d\n",a,b);
    printf("a + b = %d\n", num_sum(a,b));
    printf("a - b = %d\n", num_sub(a,b));
    return 0;
}