#include<stdio.h>
#define PrintLine printf("\n")

// 来研究一下C中的枚举类
enum WEEKDAY {
    MON=1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

enum SEASON {
    SPRING=1, SUMMER, AUTUMN, WINTER
} season; // 这里在创建完SEASON枚举类的同时, 创建了一个'对应类型'的变量
// 此处'season'的变量类型为'enum SEASON', 初始默认值为'0'

// 定义一个'奇怪顺序'的枚举类
enum TEST_ENUM{
    Vfirst, VA=7, VB, VC=10, VD, VE=8
    // ENUM中若有有值'没有赋值', C会默认将其赋值为"前面的值+1"
    // 若是'首个值'没有赋值, 则第一个值默认为0
    // 在这个例子中: Vfirst=0, VB = 8, VD = 11 (C自行推导赋的值)
    // ENUM中允许不同的'枚举类'有同样的值, 如这里的 VE = VB = 8
};

int main(){
    // 手动创建一个'枚举类型'的变量
    enum WEEKDAY my_weekday = 5;
    printf("The number of 'FRI' is: %d\n", my_weekday);
    printf("The number of deafult SEASON variable is: %d\n", season);
    PrintLine;

    printf("1.Spring 2.Summer 3.Autumn 4.Winter\n");
    printf("Please select your favourite season: ");
    scanf("%d", &season);
    switch(season){
        case SPRING:
            printf("Your favourite season is SPRING!\n");
            break;
        case SUMMER:
            printf("Your favourite season is SUMMER!\n");
            break;
        case AUTUMN:
            printf("Your favourite season is AUTUMN!\n");
            break;
        case WINTER:
            printf("Your favourite season is WINTER!\n");
            break;
        default:
            printf("This is not a valid input! Try again :(\n");
            break;
    }
    PrintLine;

    // 展示TEST_ENUM中的所有值 (Tips: 在某些IDE中, 鼠标悬浮在对应的变量上也可以展示)
    printf("Displaying every value inside TEST_ENUM...\n");
    printf("Vfirst = %d\n", Vfirst);
    printf("VA = %d\n", VA);
    printf("VB = %d\n", VB);
    printf("VC = %d\n", VC);
    printf("VD = %d\n", VD);
    printf("VE = %d\n", VE);
}