// 预处理指令区

// (a) 引入其他的'头文件' (可以理解成Java中的'接口', '接口'的具体实现在别处)
#include<stdio.h> // printf函数所在的'头文件'声明 (抽象方法/接口声明地点)
#include<windows.h> // 解决Windows中cmd输出中文编码问题的头文件 (可忽略)
// 在预处理阶段, include关键字引入的其他'抽象头文件'会进行"原文插入替换"
// 随后在最终link阶段, ld链接器会去找到printf等"声明方法"的'具体实现地点', 并将找到的可调用的'内存地址'返回到当前程序中, 完成最终'可执行文件'的包装 (动态链接)
// 在该示例中, ld链接器找到了printf(), SetConsoleOutputCP(), SetConsoleCP()方法的实现, 以及在内存中的"可调用地址"

// Tips: 一般来说, 操作系统里面会有'集成'一些常用的库, 提供如printf这一类的方法. 程序在最后的链接阶段时, 可以分成'动态链接'和'静态链接'
// 动态链接: ld链接器找到方法'可调用的地址', 程序运行时像'调用API'一样直接调用
// 静态链接: ld链接器会将'整套API运行逻辑'全套照搬到运行的程序中, 程序不再需要'调API', 而是自己'拥有了一整套API执行逻辑'可以直接用 XD

// (b) 各种'宏定义' (用户自定义 数据/关键字替换)
#define target_msg "你好呀~我是来自<stdio.h>中的printf()函数, 有人找到我说这里需要我'帮个小忙', 没我啥事的话我就先撤了~\n"
#define TRUE 1

// 自定义'数据类型'区
struct User{ // 自定义 'User类型' (struct User)
    char name[50];
    int age;
};
enum Color { // 枚举常量类型
    RED,
    GREEN,
    BLUE
};

//"全局"声明区 (用于声明'全局变量' & '暴露函数'给其他方法用)
extern int global_counter; // 使用'extern'关键字来声明'全局变量'
int fun_add(int a, int b); // 这里写的'函数签名'实际意义是: "我将用到一个'别的程序'的方法", 它的实现不在这里, 但是它可以直接用!
// 正常来说这玩意可以写到'单独的.h头文件'中, 方便众多方法的集成 & 引用

// 函数实现区 (main函数就在其中)
// 此处可以写一些方法的实现...

// 主程序入口 (跑起来全看这里)
int main(){
    // 告知CMD使用UTF-8解析中文字符输出
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    printf(target_msg);
    printf("The defined value of 'TRUE' is: %d",TRUE);
    return 0;
}