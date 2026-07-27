#include<stdio.h>
#include"random_tool.h"

#define PrintLine printf("\n")

// 通常来说, C是不允许返回在函数中创建的'临时数组' (在离开函数时所有数据都会被清空!)
// 但是如果将其内部的'临时数组'static修饰成'全局数组', 再返回全局数组的地址, 好像也不是不行 XD
int * get_random_arr(int min, int max){
    static int storage_arr[10]; // 将内部创建的'临时数组'通过static修饰成'全局变量'
    int storage_lenth = sizeof(storage_arr) / sizeof(storage_arr[0]);
    for(int i=0; i<storage_lenth ; i++){
        storage_arr[i] = get_random(min, max);
    }
    return storage_arr; // 返回'全局变量'数组的地址
}


int main(){
    int * pointer_to_arr;
    pointer_to_arr = get_random_arr(1,100);
    printf("Returned random array in range 1-100: \n");
    for(int i=0; i<10 ; i++){
        printf("%d, ", *(pointer_to_arr+i));
    }
}