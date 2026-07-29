#include<stdio.h>
#define PrintLine printf("\n")

// 指针数组在C中的用处可大着啦awa
// 其核心的关键便是: 将一堆离散数据的地址'集合在一起', 方便管理各种'类型相同', 但是内容各异的东西

int main(){
    /*假如我们想创建一个"字符串数组", 常规的情况下我们会用"二维数组"来做
    char string_array[4][20] = {"Niko", "Kumo", "Cirno", "Starlight"};
    这里我们不难发现一些'限制':
    1. 字符数组定长的, 意味着C在内存中已经提前分配好了对应的存储, 因此每一个字符串都有'长度上限' (不能超过20个字符)
    2. 虽然已经分配好了存储大小, 但是每个字符串并不会将分配的"内存空间"全部利用, 多出来的"空闲部分"即是一种空间的浪费 xwx
    */ 

    // 为了解决上述问题, 关键就是让C根据每个字符串的长度'自动分配'其存储大小, 这本来就是C会做的 :)
    // char* string = "Cirno"; 这里C会直接自动分配 5Byte 来存储"Cirno"字符串, 随后再创建 char* 指针指向已分配大小的'首元素 C'的内存地址
    // 那么, 如果我们用char* []呢?
    char* string_array[] = {"Niko", "Kumo", "Cirno", "Starlight", "Taike"};
    /* 上述的声明完成了两件事情:
    1. C给每个字符串元素都动态分配好了内存, 大小分别是 4, 4, 5, 9, 5. 同时也动态确定了左侧string_array[]的大小为5
    (此处string_array[]中存的实际内容分别为: 指针字符'N'的首地址的一级指针, 指向字符'K'的首地址的一级指针, 指向'C'首地址的一级指针, 指向字符'S'首地址的一级指针, 指向字符'T'首地址的一级指针)
    (注: char* 的数组里放的元素都是 char* 指针! 指针才指向元素的'存储地址'!)
    2. string_array 的值为 指向字符'N'首地址的"一级指针"地址 (数组中首个元素的地址)

    解一级引用得 --> 字符'N'的存储地址
    解二级引用得 --> 字符'N'
    */
    printf("The first string in array is: %s\n", *(string_array));
    printf("The first char in first string is: %c\n", **(string_array)); 
    PrintLine;

    // 偏移读取测试
    printf("The fourth string is: %s \n", *(string_array+3));
    printf("The 7th char in this string is: %c \n", *(*(string_array+3)+6));
    PrintLine;

    // 另一个测试
    int a=114, b=514, c=1919, d=810;
    int* num_array[] = {&a, &b, &c, &d}; // 指针数组中存的每个元素都应该是一个'地址', 随后C会自动生成一个指向该地址的"一级指针"
    printf("The address of num_array is %p, the dereferenced value is: %p \n", (void*)num_array, (void*)(*num_array));
    printf("The first value address is: %p, dereferenced value: %d \n", (void*)(*num_array), **num_array);
}