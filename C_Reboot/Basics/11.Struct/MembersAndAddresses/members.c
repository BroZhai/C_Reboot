#include<stdio.h>
#include<string.h>
#define PrintLine printf("\n")

// 自行研究一下'结构体'的本质, 看看它的地址 和 成员变量之间的关系是怎样的

typedef struct Player{
    double money; // 8 Byte
    int hp; // 4 Byte
    char name[20]; // 20 Byte
} Player;

// 额外收获: C编译器的'自动padding'补位 & 最终'对齐'
// 结构体的'分配大小'有时并不是'所见即所得', 具体见./sizeAllocation.c
// 只不过上面的定义顺序刚好 '自动padding补位' 和 '对齐' 都没触发 XD

int main(){
    Player p1 = (Player){9.99, 34, "Techniko_Pancake"};
    // Player* ptr_to_p1 = &p1;
    char* ptr_to_p1 = (char*) &p1; // 定义一个指向'p1'地址的指针, 偏移计算时按'char'(1 Byte偏移), 上面那种写法偏移时会直接按'32Byte'(一整个结构体变量)偏移!
    printf("The address of p1 is: %p \nptr_to_p1's content is: %p \n", &p1, ptr_to_p1); 
    PrintLine;

    // 结构体变量'p1'在这里本质上还是内存中的一个'起始地址', 涵盖了'一整个结构体大小'的地址空间 (8+4+20, 共计32Byte)
    printf("The total size allocate to p1 is: %zu Bytes\n", sizeof(p1));
    /* 也就是说
        money地址 = p1首地址
        hp地址 = p1首地址 + 8Byte (偏移跳过money)
        name地址 = p1首地址 + 8Byte (偏移跳过money) + 4Byte(偏移跳过hp)
    */
    // 注: 结构体内部的定义的'成员顺序'有时会触发'补位'操作, 且最终出来的'数据大小'必须为 8 的整数倍!
    printf("The address of p1.money is: %p, the value is: %f \n", (void*) &(p1.money), p1.money); // &(p1.money) = &p1
    printf("The address of p1.hp is: %p, the value is: %d \n", (void*) &(p1.hp), *(ptr_to_p1 + 8)); // &(p1.hp) = &p1 + 8 Byte
    printf("The address of p1.name is: %p, the value is: %s \n", (void*) p1.name, ptr_to_p1 + 12);

    
}