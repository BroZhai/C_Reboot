#include<stdio.h>
#define PrintLine printf("\n")

// 来研究一下C中的数组

int main(){
    // 直接声明 & 初始化一个数组 (数组在创建时一定要定长, 由此产生的数据)
    int num_list[] = {10, 20, 30, 40, 50};
    int single_element_length = (signed int) sizeof(num_list[0]); // 获得'一个元素'的字长 (每个元素一样)
    int total_counts = sizeof(num_list) / single_element_length; // 取得'总体元素'个数
    printf("Single element type length: %d\n", single_element_length);
    printf("Total elements counts: %d\n", total_counts);
    PrintLine;
    
    printf("The first element in num_list is: %d\n", num_list[0]);
    printf("The middle element in num_list is: %d\n", *(num_list + 2)); // 首地址 + 2偏移
    // 上面解引用运算的实际展开为: 首元素地址 + 2 x sizeof(int); 

    if(num_list == &num_list[0]){
        printf("The address of num_list is equal to the address of the FIRST ELEMENT in list! &num_list[0]\n");
    }
}