#include<stdio.h>
#define PrintLine printf("\n")

// 来研究一下数组当形参 和 返回

// 1. 使用指针当形参, 传入'数组地址' (数组中首个元素的地址)
// Tips: 在C中, 若仅知道一个数组的'起始地址', 是无法得出其具体长度的! 见下方注释代码
// 因此在写方法时, 通常会要求把'数组长度'显示的传进来
void show_last(int * array_address, int array_size){
    // int last_index = (int) sizeof(array_address) / sizeof((array_address)[0]) - 1; // 这里的sizeof()实则算的是'指针'的大小(固定8字节), 而不是算'数组'的大小, 故在仅知道'地址'的情况下时无法得知数组的'具体长度'的
    int last_index = array_size - 1;
    // printf("The calculated last index of this array is: %d\n", last_index);
    printf("The last value in this array is: %d\n", *(array_address+last_index)); // 会展开成 array_address + last_index * sizeof(int)

    // 额外小贴士: 传入的'数组地址'也可以直接用index访问其元素
    // 上面的printf可以等价写成: printf("The last value in this array is: %d\n", array_address[last_index]);
}

// 2. 直接写成'传入数组'的形式, 但是实际上仍然是'数组地址', 和上面的写法没有区别
void show_last_but_one(int array[], int array_size){ // 等价于 int * array_address
    // int last_but_one_index = (int) sizeof(array) / sizeof(array[0]) - 2; // 传入的不是'数组本身', 永远只会是'数组的地址'!!
    int last_but_one_index = array_size - 2;
    printf("The last but one value in this array is: %d\n", array[last_but_one_index]);
}

// 还有一种'语法糖'的形式, 即是'带上数组大小', 不过编译器会会忽略"数组大小", 本质上还是会看成'数组地址'
// void func(int array[23]){...} // 实际上仍等价于 func(int * array_address);


int main(){
    int first_arr[] = {5,3,1,2,6};
    int second_arr[] = {1,9,4,7};
    show_last(first_arr, 5);
    show_last(second_arr, 4);
    PrintLine;

    show_last_but_one(first_arr, 5);
    show_last_but_one(second_arr, 4);
}