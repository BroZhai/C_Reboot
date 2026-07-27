// 来实践一下C中的各种'判断式'
#include<stdio.h>
#define PrintLine printf("\n");

// C里面将 非0 或 非空 的值定为true, 0 或 null定为false, 其自身并没有'true/false'布尔变量判断
int a=4, b=3;
// int a=4;

int main(){
    // 常规if判断
    if(3*a-2*b){ // 0 = false, 不会进入下面的分支, 而直接跳到最下面else的分支
        printf("3 x a - 2 x b is NOT 0! Regarded as a TRUE result \n");
    }else{ 
        printf("3 x a - 2 x b is 0! which has lead a jump to this statement. \n");
    }

    // switch-case (条件判断中应是一个'整数结果', 或者表达式得'整数结果', 根据'结果值'进行分支走向)
    int week_index=3;
    switch(2*week_index){
        case 1:
            printf("Today is MONDAY\n");
            break;
        case 2:
            printf("Today is TUESDAY\n");
            break;
        case 3:
            printf("Today is WEDNESDAY\n");
            break;
        case 4:
            printf("Today is THURSDAY\n");
            break;
        case 5:
            printf("Today is FRIDAY\n");
            break;
        case 6:
            printf("Today is SATURDAY\n");
            break;
        case 7:
            printf("Today is SUNDAY\n");
            break;
        default:
            printf("The week_index is out of index!\n");
            break;
    }

    // 三元运算符
    (a>0) ? printf("a is GREATER than 0\n"):printf("a is SMALLER than 0\n");
    int int_value = (a>0) ? 4.5:3; // 在利用三元运算符返回赋值时, 应注意'返回数值'应与左侧'接收类型'对应, 否则C会强转
    // 在这个例子中, float 4.5 会被强转成左侧标的int
    printf("int_value is: %d \n", int_value); // 4
}