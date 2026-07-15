// 学语言经典保留节目之猜猜数
// 之后用C把Jvav的恶魔轮盘写出来也算是OK了, 致敬前作的复合成分 salute!

#include<stdio.h> // 不仅用到里面的printf输出, 还要用到scanf获取用户输入 owo
#include<stdlib.h> // 用到其中的rand()生成伪随机数, 使用rand()前要先用srand()配置一个'种子'
#include<time.h> // 既然要种子那就用'系统时间'吧 (图个方便

#define PrintLine printf("\n");

int main(){
    // 用系统时间当种子, srand的输入形参为一个 unsigned int
    // time()是time.h中函数, 会返回当前的Unix秒数时间戳, 其定义要求要传个'地址'进去, 随后time会将时间戳写到对应的'地址'并返回该Unix时间戳
    /* Tips: 
        1. 这里我们只关心'返回Unix'秒数时间戳, 所以'地址'部分可以直接传个Null(不用写时间戳到内存)
        2. time()返回的一个time_t类型, 其最终类型实则是 (signed) long, 我们需要强转成unsigned才能放在srand()中用
        3. Unix秒数时间戳的'精度'只到秒(每秒才更新), 如果在循环中用要注意! 
    */
    // 更多具体实践解释见'random_test.c'
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed); // 设置种子
    int rand_num = rand();
    
    // 生成指定范围内的数
    int left=1;
    int right=100;
    int answer =  rand_num % (right-left+1) + 10;
    
    // 逻辑判断部分
    int is_correct = 0;
    int guess_count = 0;
    int input_value;
    printf("Welcome to Number Guesser!\n");

    do{
        printf("\nPlease enter your answer: ");
        scanf("%d", &input_value);
        switch(input_value){

        }
            



    }while(!is_correct); // 没错, 可以这么用, 在C中 !0 会算得 1

}