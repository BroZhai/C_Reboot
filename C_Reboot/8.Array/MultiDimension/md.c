#include<stdio.h>
#define PrintLine printf("\n")

// 简单玩转一下多维数组

int main(){
    // 定义 & 初始化一个二维数组, 5行 3列 (横向index 0-2, 纵向0-4)
    int two_dimension_arr[5][3] = {
        {2,3,6},
        {3,2,7},
        {1,2,3},
        {9,2,7},
        {4,6,5}
    };
    
    // 获取二维数组中的'元素个数'
    int element_counts = (int) sizeof(two_dimension_arr) / sizeof(two_dimension_arr[0]); // 外层元素个数
    int nested_count = (int) sizeof(two_dimension_arr[0]) / sizeof(two_dimension_arr[0][0]); // 内存元素个数
    printf("The total element counts in two_dimension_arr is: %d\n", element_counts);
    printf("The nested_count in each array is: %d\n", nested_count);
    PrintLine;

    // 循环输出
    printf("The value traversed in the two_dimension_arr:\n");
    for(int i=0;i<element_counts;i++){
        for(int j=0;j<nested_count;j++){
            printf("%d, ",two_dimension_arr[i][j]);
        }
        printf("\n");
    }
}