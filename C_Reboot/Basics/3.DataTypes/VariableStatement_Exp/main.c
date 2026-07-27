#include<stdio.h>
// #include"impl.h" // Tips: '引入'的部分也可以写成单独的'头文件', 和'函数签名'一起

// 引入'外部变量' (Tips: 以下内容也可以引入到'头文件'中进行使用)
// 在该函数中可使用的'外部变量'以这里的'签名'为准
// 变量的'签名'应与'实现的签名'一致, 不然盲目修改可能会导致问题 XD (和方法签名同样的道理)
extern int impl_varA;
extern const int impl_varB; // const关键字声明了该'引用变量'不可修改, 其'原实现'也是const不可改

// main.c本地定义的变量 (全部为'仅声明')
int default_int;
double default_double;
char default_char;
int* deafult_int_ptr;

int main(){
    printf("The value of impl_varA is: %d, and impl_varB is: %d \n", impl_varA, impl_varB);
    // 重新给'外部引用变量'赋值
    impl_varA = 1919;
    // impl_varB = 810; // impl_varB被const修饰, 只读不能改
    printf("After changing, impl_varA: %d, impl_varB: %d \n",impl_varA, impl_varB);

    printf("\n===============Default Value Testing=================\n");
    printf("Deafult int is: %d\n", default_int);
    printf("Deafult double is: %f\n", default_double);
    printf("Deafult char is: %c\n", default_char);
    printf("Deafult pointer is: %p\n",(void*) deafult_int_ptr);
    printf("\a");
    return 0;
}