#include<stdio.h>

int int_list[12];
double double_list[6];

int main(){
    printf("The size of int_list is %zu Bytes, ", sizeof(int_list));
    // 使用sizeof看某个'对象大小'时, 用%zu占位符, 同时sizeof统计出来的实际是'Byte'大小, 而非对象定义大小...
    // 这里可以用点'小巧思'将其还原回来 (数组总字长 / 每个元素的字长 = 元素个数, 也是'数组长度')
    printf("which real length is %zu\n", sizeof(int_list)/sizeof(int_list[0])); // 每个int 在现代OS上都是4Byte

    printf("The size of double_list is %zu Bytes, ", sizeof(double_list));
    printf("which real length is %zu\n", sizeof(double_list)/sizeof(double_list[0])); // 每个double均为8 Byte, 数据类型研究中有记过
    return 0;
}