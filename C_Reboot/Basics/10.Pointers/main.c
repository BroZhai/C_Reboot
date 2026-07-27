#include<stdio.h>
#define PrintLine printf("\n")

// 来研究一下指针相关的内容
// 其实本质上玩了下CE找基址的过程就对此处的内容相当理解了

int main(){
    // 单个变量的地址 & 解引用
    int random_value = 114514; // 此处的random_value为'字面量'
    int* value_ptr = &random_value; // 使用 &random_value取得各种'字面量'变量的内存地址, 拿'函数'的地址也是这样
    printf("The address of randon_value is: %p, and the dereferenced value is: %d\n", (void*)value_ptr, random_value);
    PrintLine;

    // 多级指针, 某个很难定位的值具有'多重指针'指向 (在CE中基址 + 多层指针偏移 才能锁定到最终真正的值!)
    /*
        快速参考:
        int* ptr = xxx地址;

        ptr自身 = xxx地址;
        *ptr = 对(xxx地址)解引用得其'具体值', 注意并不是对'ptr自身'解引用!
        &ptr = ptr的地址
    */
    int target_value = 1919810;
    int* first_ptr = &target_value; // first_ptr的值为 target_value的内存地址
    int** second_ptr = &first_ptr; // second_ptr的值为 first_ptr的内存地址, 注意first_ptr已经是 int* 一级指针, 存它的地址要用 int** 二级指针来存 (下面同理)
    int*** third_ptr = &second_ptr; // thrid_ptr的值为 second_ptr的内存地址
    printf("The address of randon_value is: %p, and the dereferenced value is: %d\n", (void*)&target_value, target_value);
    printf("The address of first_ptr is: %p, it is pointing to: %p, and the dereferenced value of that pointer is: %d \n", (void*)&first_ptr, (void*)first_ptr, *first_ptr); // 解一级指针
    printf("The address of second_prt is: %p, it is pointing to: %p, and the dereferenced value of that pointer is: %p \n", (void*)&second_ptr, (void*)second_ptr, (void*)*second_ptr);
    printf("The address of third_ptr is: %p, it is pointing to: %p, and the dereferenced value of that pointer is: %p \n", (void*)&third_ptr, (void*)third_ptr, (void*)*third_ptr);
    PrintLine;

    // 一些变量类型如 数组, 字符串等, 他们的变量地址无需用'&'来拿, 变量本身的'值'直接就是"首个元素"的地址
    char str_buffer[100] = "ABCDEFG"; // str_buffer的地址为字符'A'的地址4
    printf("The address of str_buffer is:%p, the value dereferenced is: %c \n", (void*)str_buffer, *str_buffer);
    printf("The next addrees is: %p, which the dereferenced value is: %c \n",(void*)str_buffer + 1, *(str_buffer+1));
    printf("And the next addrees is: %p, which the dereferenced value is: %c \n",(void*)str_buffer + 2, *(str_buffer+2));
}