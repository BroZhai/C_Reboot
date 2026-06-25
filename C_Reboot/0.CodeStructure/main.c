#include<stdio.h> // printf函数所在的'头文件'声明 (抽象方法/接口声明地点)
// 在link阶段, ld链接器会去找到printf的'具体实现地点', 并将printf可调用的'内存地址'返回到当前程序中, 完成最终'可执行文件'的包装

#include<windows.h> // 解决Windows中cmd输出中文编码问题

int main(){
    // 告知CMD使用UTF-8解析中文字符输出
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    printf("你好, 我是来自stdio.h中的printf函数, 有人把我叫来这里打印这行语句, 后面没我的事就先撤了~");
    return 0;
}