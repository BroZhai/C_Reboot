#include<stdio.h>
#define PrintLine printf("\n")

// 对C指针进行算术运算时, C会帮我们'自动展开'指针数据类型'对应的大小' 参与实际的地址偏移运算
/**
 * int arr[] = {1,2,3,4,5};
 * int* ptr_to_arr = &arr;
 * 
 * 地址偏移 +解引用 访问元素'2': *(ptr_to_arr + 2) --自动展开为--> *(ptr_to_arr + 2 * sizeof(int));
 * 因为指针是int类型, 所以在展开时后面自动补上了 sizeof(int);
 * 那么针对其他的数据类型也是同理 (C) 
 */

int main(){
    int arr[] = {1,2,3,4,5};
    char* char_ptr_to_arr = (char*)arr; // 此处进行强制类型转换, char*指针展开后只会按 1Byte (sizeof(char))偏移
    int* int_ptr_to_arr = arr;
    printf("Accessing thrid element using char*: %d\n", *(int*) (char_ptr_to_arr + 8)); // 等效于 *(ptr_to_arr + 8 x sizeof(char)), sizeof(char)为 1Byte, 8 x 1
    // 这里虽然是按'char *'进行的地址偏移, 但实际解引用的值还是int, 所以还要用(int*)强转回int指针进行正常的'解引用'
    
    printf("Accessing thrid element using int*: %d\n", *(int_ptr_to_arr + 2));// 等效于*(ptr + 2 x sizeof(int)), sizeof(int) 为 4 Byte, 2 x 4
}