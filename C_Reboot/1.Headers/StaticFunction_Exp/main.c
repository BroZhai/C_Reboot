#include<stdio.h> // 从'系统C库'中引入printf
#include"my_operations.h" // 从'当前目录'引入自定义的'头文件'

// int value_in_header=114;
int main(){
    printf("The value provided in the header file is: %d\n", value_in_header);
    int a=5, b=4;
    printf("Value a = %d, b = %d\n",a,b);
    printf("a + b = %d\n", num_sum(a,b));
    printf("a - b = %d\n", num_sub(a,b));
    return 0;
}