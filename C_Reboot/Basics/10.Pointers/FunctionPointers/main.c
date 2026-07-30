#include<stdio.h>
#define PrintLine printf("\n")

// 来研究一下'函数指针', 本质上就是通过'函数地址解引用'来调用函数
// 通过这个特性, 我们就能编写'回调函数'啦 awa (函数里面调另一个函数)

// 创建一些有实现的方法
void play_sdvx(int rounds){
    printf("I must play Shan Dong Vei Xing for %d rounds! \n", rounds);
}

void play_maimai(int rounds){
    printf("I must play Wu Meng Di CHA for %d rounds! \n", rounds);
}

void play_iidx(int rounds){
    printf("I must play Lei Ting Da Si for %d rounds! \n", rounds);
}

// 这里是看上去是一个普通函数, 但是不同的是
// 这里函数的'输入形参'中带了一个'回调函数', 传入对应的'函数指针'即可完成另一个函数的调用(回调)
// '函数指针'形参的输入格式 和 '创建函数指针'的语法一致, 这里的'函数指针名'自定义
void summon_friend(void (*game_to_play_ptr)(int), int play_rounds){
    printf("Today, my friend and ");
    game_to_play_ptr(play_rounds); // 调用传入的'函数指针' (远程调用'函数地址'对应的'函数方法')
}

/* ------------------------------------------------------------------ */

int main(){
    // 创建三个play函数的地址创建它们对应的'函数指针'
    // 语法: 原函数返回类型 (*函数指针变量名)(原函数'输入形参'类型A, 类型B...) = &函数名; 
    /*Tips: 
    1. 函数的'&'可以省, 因为函数名变量 本身就是 函数的'起始地址' (但是出于好习惯, 还是尽量都写上 :3)
    2. 如果函数'不带形参', 那么在创建'函数指针'时的形参部分用(void)替代就好了
    */ 
    void (*sdvx_function_ptr)(int) = &play_sdvx;
    void (*maimai_function_ptr)(int) = play_maimai; // 可省略'&'不写
    void (*iidx_function_ptr)(int) = &play_iidx;

    // 创建好函数指针以后, 理论上我们可以直接用 '函数指针变量名'(形参)进行调用
    sdvx_function_ptr(114);
    maimai_function_ptr(514);
    iidx_function_ptr(1919);
    PrintLine;

    // 当然, 更多情况下我们会将这些'函数地址'拿到另一个函数中用作"回调函数" :P
    summon_friend(play_maimai, 3);
    // 输出: Today, my friend and I must play Wu Meng Di CHA for 3 rounds!
    /*
        summon_friend()调用: Today, my friend and 
        play_maimai()函数指针回调: I must play Wu Meng Di CHA for 3 rounds!
    */
    // Tips: 在一个函数中可以调用另一个函数了, 那么理论上来说, 这种回调可以无限迭代下去, 这就是人们所说的'回调地狱'了 XD
    // 因此控制好函数'回调'的次数, 防止超级长链条 shit code XD
    
    // 我们还可以引申出一种更高级的玩法 --> '函数指针数组'
    // 即直接把'不同的函数指针'用数组"汇总"起来, 方便直接用'数组调用' (和'指针数组'的管理思想一致)
    void (*rhythm_game_list[])(int) = {play_sdvx, play_maimai, play_iidx};
    summon_friend(rhythm_game_list[2], 5); // 传入的是 play_iidx 函数指针
    // summon_friend(*(rhythm_game_list+2), 5);
    // 注: 既然是'指针数组', 那么指针数组'访问的坑'这里也是一样的! 注意两种不同访问'得结果'的差异! (上面两个指令是一样的)
}