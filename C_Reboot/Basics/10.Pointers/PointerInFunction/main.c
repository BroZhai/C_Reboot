#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define PrintLine printf("\n")

// 对传入的指针数组的'最后一个'地址所指向的值 + 1, 直接应作用在原指针数组上
void last_plus_one(int* pointer_array[], int array_size){
    // 取到最后一个元素的地址, 直接解引用得变量/变量值, 再 +1 即可
    *(pointer_array[array_size-1]) = *(pointer_array[array_size-1])+1;
}

void show_all_values(int* pointer_array[], int array_size){
    printf("The value in array: ");
    for(int i=0; i<array_size; i++){
        printf("%d, ",*(pointer_array[i]));
    }
    PrintLine;
}

char* make_string(const char* src) {
    char* copy = malloc(strlen(src) + 1); // malloc(想要申请多少Byte), +1 是因为strlen()不会考虑'\0'
    printf("The incoming string address is: %p, which the dereferenced value is: %c \n", (void*)src, *src);
    strcpy(copy, src); // strcpy(新起始地址, 原字符串起始地址), 随后实现"内容照搬"
    printf("The allocated starting memory address is: %p, which the dereferenced value is: %c \n", (void*)copy, *copy);
    PrintLine;
    return copy;  // 返回调用者拿到后负责 free
}

int main(){
    int a=114, b=514, c=1919, d=810;
    int* num_array[] = {&a, &b, &c, &d};
    int array_size = (int) sizeof(num_array) / sizeof(num_array[0]);
    /*  上面写了一个看似很矛盾的'求指针数组'长度, 按理来说, num_array 和 num_array[0]本质上都是内存地址, 他们俩比较的话结果永远都只会是1
    但是呢, 我们理解的这个情况实际只发生在'运行期', sizeof()的统计并不发生在'运行期', 而是在'编译期'
    在'编译期', sizeof()是可以拿到数组的'元素个数'的! 随后会返回 元素个数 x 每个元素字长 的"总长度" 
    对于上面的案例, 指针数组的长度即是 4个地址 x 每个地址的长度(16位, 每位4bit = 64bit = 8Byte) = 32 Byte
    而单个地址元素的长度为: 64 bit = 8 Byte
    最终得出 32 Byte / 8 Byte = 4个地址元素
    */

    show_all_values(num_array, array_size);
    last_plus_one(num_array, array_size);
    show_all_values(num_array, array_size);
    PrintLine;

    // 从函数返回指针的示例见 8.Array/ReturnArrayInFunction/return_arr.c :)
    // 这里我们用另外一个例子: 返回在函数中'灵活分配'的内存地址
    char* my_str_ptr;
    my_str_ptr = make_string("Pancake is Big BAKA");
    printf("Returned to main...\n");
    printf("The memory address of my_str_ptr is: %p, which the dereferenced value is: %c \n", (void*)my_str_ptr, *my_str_ptr);
}