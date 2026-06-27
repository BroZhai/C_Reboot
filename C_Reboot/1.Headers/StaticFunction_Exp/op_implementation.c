#include "my_operations.h" // (optional)

int value_in_header = 514; 
int num_sum(int a, int b){
    return a+b;
} 

// num_sub 已经在 my_operations.h 中有了'实现模版', 无需在此处重写 (重写会报错 multi definitions)
// int num_sub(int a, int b){
//     return a-b;
// }