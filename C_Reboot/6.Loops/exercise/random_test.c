#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PrintLine printf("\n")

// 来研究一下随机数生成

int main(){
    // rand会返回一个(signed) int, 其'最大范围值'在不同平台上有差异
    // 具体要看stdlib.h中的'RAND_MAX'宏定义, 在MSVC中最大是0x7fff(32767), 在Unix中则是2147483647
    // 因为我们用的是'系统时间'做的种子, 时间变动是规律的, 因此我们看到rand()生成的随机数也是'规律变动'的 XD
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed); // 设置种子
    int rand_num = rand();

    // 生成 [0, n-1] 范围的随机数
    // Tips: 未知值 % a = [0, a-1]范围中的一个值
    int n=20;
    rand_num = rand_num % n;
    printf("Random number range in [0, %d]: %d\n", n-1, rand_num);

    PrintLine;

    // 生成指定范围内的数
    // (利用上面的Tips我们可以推出该式子: 大随机数 % (区间跨度范围) + 左右双向调整值)
    // e.g, 10 - 30 的区间为20, 那么即是 大随机数 % (20 + 1) = 0 - 20 随机取整 (不+1就是0-19)
    // 随后再在后面补上'整体变动值'就好了, 通常是'左侧最小值' 0 - 20 (整体+10) --> 10 - 30
    rand_num = rand();
    int left=10;
    int right=30;
    int destined_rand = rand_num % (right-left+1) + left;
    printf("Random number range in [%d, %d]: %d\n", left, right, destined_rand);
}