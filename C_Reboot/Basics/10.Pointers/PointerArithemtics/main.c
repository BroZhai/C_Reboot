#include<stdio.h>
#define PrintLine printf("\n")

// 指针存的内存地址本质上就是'数值', 因此其支持各种'运算符'的操作

int main(){
    // 运算时的'自动sizeof()展开'
    short num_list[4] = {1,2,3,4}; // 每个short元素 占 2Byte,
    for(int i=0; i<4; i++){
        printf("index %d, value: %d, address: %p \n", i, *(num_list+i), (void*)(num_list+i));
        // 在对地址num_list进行计算时, 地址 + 偏移index 实际上会被换算成 首元素地址 + 偏移index x sizeof(short)
        // 小坑: 这里要先算计算后面的'起始 + 偏移地址'得到对应元素的地址, 再整体void*强转, 不要写成 (void*)num_list + i! 这样只会先转'起始地址', 然后加上一个'固定值'
        // 上面最后查看元素的地址也可以写成 (void*)&num_list[i], 更直观
    }
    PrintLine;

    // 研究简单增减
    short* list_ptr = num_list;
    printf("First Element: %d \n", *(list_ptr));
    list_ptr++; // 此处为 list_ptr = list_ptr + 1, 会被自动展开为 list_ptr = list_ptr + 1 * sizeof(short);
    printf("Second Element: %d \n", *(list_ptr));
}