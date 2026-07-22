// 随机数生成器工具的实现部分, 干脆自己写一个把, 后面可能会经常复用上
#include<stdio.h> 
#include<stdlib.h>

// 使用bcrypt.h取得'动态变化'的种子, 其中很多的'宏定义'需引入windows.h (如ULONG)
#include<windows.h>
#include<bcrypt.h>

#include"random_tool.h"

#define PrintLine printf("\n");

int get_random(int min, int max){
    unsigned int seed;
    BCryptGenRandom(NULL, (PUCHAR)&seed, sizeof(seed), BCRYPT_USE_SYSTEM_PREFERRED_RNG); // 每次调用时, 产生一个'动态变化'的种子
    srand(seed); // 核心: 这里调用时输入的seed应是不一样的值

    int rand_num = rand(); // 根据本次的种子取得一个随机值

    int generated_num = rand_num %(max-min+1) + min;
    return generated_num;
}
