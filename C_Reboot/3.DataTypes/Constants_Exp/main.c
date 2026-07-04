// 研究一下 C中'常量'的声明
#include<stdio.h>

int main(){
    // 在声明整数字面量时, 可以在整数后面加一些'奇怪字母'来声明数字的'类型', 防止编译器'隐式转换'数字类型
    unsigned int value_a = 114; // signed int
    // 在上面的声明中, 右侧输入的114字面量默认被编译器视为 signed int
    // 编译器当然会意识到右侧的类型并"不匹配"左侧的unsigned, 于是就会隐式的将右侧的signed int字面量转成 unsigned int
    // 这么一看好像编译器没干错啥事, 但是这种'自动转换'有时候会导致程序出现一些问题, 因此我们可以想办法预防'自动转换'的发生

    // 通过在字面量后面些'奇怪'字母, 我们就能很清晰的'直接声明'字面量的'具体类型'了
    unsigned int value_b = 114U; // 右侧字面量为 Unsigned int
    signed long int value_c = 114L; // signed Long int
    unsigned long int value_d = 114UL; // Unsigned Long int
    signed long long int value_e = 114LL; // signed Long Long int
    
    // 小数声明也是一样的道理, 默认的小数字面量为 double
    float value_f = 3.14f; // float
    double value_g = 3.14; // 小数字面量就是double
    long double value_h = 3.14L; // Long double

    printf("Multiple \
String \
Line");
}