#include<stdio.h>
#include<stdlib.h> // malloc(), realloc()等相关内存管理函数在<stdlib.h>库中
#define PrintLine printf("\n")

// 我们来研究一下'动态数组', 顺便提前了解一下从'Heap堆'中自己申请内存 & 释放
// 这里'动态数组'的实现, 实际就是'重新分配' 数组所占空间的大小, 通过内存管理的realloc()实现

void show_elements(int * array_address, int array_size){
    printf("The elements in this array: ");
    for(int i=0; i<array_size; i++){
        printf("%d, ", *(array_address+i));
    }
    PrintLine;
}

int main(){
    // 提前申请好一块连续的内存 (想存'多少个'元素)
    int apply_size = 3; 
    int * dynamic_array = (int*) malloc(apply_size * sizeof(int));
    /* malloc()使用时直接传入'想要申请多少Byte', 这里我们需要清楚的知道'每个元素'的字长 和 '总共可存多少个元素' (这里以存 3 个 signed int为例)
        malloc()会返回一个void*指针, 表示为一个'无法确定返回类型'的指针
        在C中可以将void* 任意强转成其他类型的指针 (这里我们知道申请存放的元素是int, 那么就应该返回的是个int*指针, 直接强转即可)
     */
    // 小巧思: 数组本质上就是一个'int* 指针地址', 所以上面申请好内存地址 + 强转类型转换后, 我们就直接得到了一个长度为 3 的 int 数组

    // 对尝试申请的内存进行判断
    if(dynamic_array == NULL){
        printf("Memory application Failed!\n");
        return 1;
    }

    printf("The size of dynamic_array is now: %d\n", apply_size);
    dynamic_array[0] = 1;
    dynamic_array[1] = 2;
    dynamic_array[2] = 3;
    show_elements(dynamic_array, apply_size);
    PrintLine;

    printf("Reallocating int* array memory size...\n");
    apply_size = 5;
    dynamic_array = (int*) realloc(dynamic_array, apply_size * sizeof(int)); // 3 -> 5
    
    if(dynamic_array == NULL){
        printf("Memory application Failed!\n");
        return 1;
    }

    printf("The size of dynamic_array is now: %d\n", apply_size);
    dynamic_array[0] = 7;
    dynamic_array[1] = 1;
    dynamic_array[2] = 5;
    dynamic_array[3] = 5;
    dynamic_array[4] = 6;
    show_elements(dynamic_array, apply_size);
    
    free(dynamic_array); // 手动清理用完的'申请内存'
}