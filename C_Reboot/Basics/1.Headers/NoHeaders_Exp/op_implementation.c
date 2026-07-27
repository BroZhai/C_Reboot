// 这里直接写实现, 看能不能通过编译

// 以下内容注释 & 取消注释将"不影响"运行 (和#include"my_operations.h"作用一致, 这里直接照搬)
// extern int value_in_header;
// int num_sum(int a, int b);
// int num_sub(int a, int b);

int value_in_header = 514; 
int num_sum(int a, int b){
    return a+b;
} 
int num_sub(int a, int b){
    return a-b;
}

// 结论: 在对方法进行"实现"时, 可以不带对应的'头文件', 但实际开发中建议还是带上
// .h头文件就像是提前定好的一个"标准", 实现时就靠着这个'标准'来写, 防止出现'标准'和实现不一致的情况
// 此外, 写个.h头文件也能让IDE读到.h中定义的各种'标准', 给你提供劲爆snippets协助开发