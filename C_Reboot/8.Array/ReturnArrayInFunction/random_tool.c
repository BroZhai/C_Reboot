// 随机数生成器工具的实现部分, 干脆自己写一个把, 后面可能会经常复用上
#include<stdio.h> 
#include<stdlib.h>

#include<windows.h>
#include<bcrypt.h>

#include"random_tool.h"


#define PrintLine printf("\n");

int get_random(int min, int max){
    unsigned int seed;
    BCryptGenRandom(NULL, (PUCHAR)&seed, sizeof(seed), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
    srand(seed);
    int rand_num = rand(); // 先取得一个随机值

    int generated_num = rand_num %(max-min+1) + min;
    return generated_num;
}
