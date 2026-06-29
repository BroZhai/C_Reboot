#include<stdio.h>
// #include<cpl.h>

// 来研究一下各种'预处理'指令, 本质上就是各种'自定义文本替换'
// 注: 每行预处理指令后面不用加';', 因为';'也会被当成'替换文本'的一部分
#define CLG printf // 将'printf'关键字换成'CLG', 下方再调printf时可以直接用CLG作为替换
#define my_data 40
// #undef my_data // 'undef'取消定义某个宏 (注释后main中报错找不到my_data)

// 宏中的'判断' 
// '条件'判断 #if #elif #else
#if my_data > 30
    #warning "my_data的值大于30!"
#endif // 每一个#if...都需要有个#endif收尾

// '定义'判断 #ifdef #ifndef 
void check_clg(){
#ifndef CLG
    #define CLG printf // 注释掉第6行的define即可进入该分支
    #warning "CLG has NOT replaced printf, redefining now...";
#else
    CLG("CLG has SUCCESSFULLY replaced printf!\n");
#endif 
}

// Tips: #ifdef还可用于'头文件'的引入检测, 即有没有引入'所需的'头文件 (了解用法即可)
// 原理: 判断'有无头文件中定义的'宏'', 如cpl.h中有个统一官方定义的宏'__cplusplus'
#ifndef __cplusplus
    #warning "You have not include the C plus plus header file!"
#else
    printf("C plus plus library is ready!!")
#endif
// 注: 该方法并不是'万能'的, 因为很多头文件的并没有这样的'统一定义宏', 或是定义的'标准'完全不一样
// 如 stdio.h 在mingw64中的宏是_INC_CPL, 而在Linux中却是_STDIO_H, 所以"判断标准"并不统一, 自然更别提判断了

// 在实际写代码时, 我们通常防的是'同一个.h文件 / 变量' 在"本文件"中引入了两次或多次
// 此时我们可以'巧用'宏定义, 让其'一次性'完成所有 头文件引用 / 变量声明
#ifndef my_status // 如果'my_status'未曾被定义 (程序首次执行)
    #define my_status // 那么就定义它, 并且'顺带执行'下面的命令, 之后就不用管了(不用在引入了)
    // #include <stdio.h>
    // (要追加其他的头文件/变量时, 直接在这里追加即可)
#endif
// 这种写法叫 Include Guard


int main(){
    check_clg();
    CLG("The value of my_data is: %d\n", my_data);
    CLG("The current filename is: %s",__FILE__); // 系统内置宏 (预定义宏)
    return 0;
}
