#include<stdio.h>
#define PrintLine printf("\n")

// 函数的创建, 传参, 我们并不陌生
// 而在C中, 就是多了个'外部函数声明' 和 '传参指针' 这俩新鲜玩意而已, 来自己研究一下

// 创建一个普通函数, 对传入的'值'做操作
void add_one(int input_value){
    input_value +=1;
    printf("The input value after changing inside the 'add_one' function: %d\n", input_value);
}

// 也是一个没有任何返回值的函数, 但输入的形参是一个'地址', 假设为单指针, 一次解引用得其值
void double_value(int * value_address){
    signed int real_value = *value_address; // 对传入的'地址'解引用得值
    real_value *= 2;
    printf("The real value in 'double_value' function: %d\n", real_value);
}

// 手动引入一个外部的'函数签名' (这里可以也写成header file头文件再进行include引入, 其具体实现在impl.c中)
void apply_double(int * value_address);

int main(){
    int a=23, b=47;
    add_one(a);
    double_value(&b);
    PrintLine;

    // 根据局上面两个函数的写法, 两个传入的值的'生命周期'仅在对应的'函数作用域'内有效
    // 两个函数都没有返回, 或是能直接修改到main中定义的两个值, 所有main中的两个值维持原样未动
    printf("The value of a in main is: %d\n", a); // 23
    printf("The value of b in main is: %d\n", b); // 47
    PrintLine;

    printf("Applying changes to value b through its address...\n");
    apply_double(&b);
    printf("The value of b in main after application is: %d\n", b);
}