#include<stdio.h>
#define PrintLine printf("\n")

// 在看typedef匿名结构体的时候然想到一个case, 过来这边验证一下看看能不能跑
// 匿名枚举类起的'别名'能用于创建新的'枚举变量'吗? (匿名结构体可以这么玩)

typedef enum {
    SPRING = 1, SUMMER, AUTUMN, WINTER
} SEASONS;

int main(){
    SEASONS my_fav = AUTUMN; // 答案是可以!
    printf("The number of my favourite season is: %d", my_fav);
}