// C中并没有内置显示数值'二进制表示'的相关工具, 要自己实现 owo...
#include<stdio.h>
#include"bit_tool.h"

// 显示一个有符号数的'二进制表示', 限制8位bit (范围 -127 < x < 127)
void show_bin(signed int input_value){
    if(input_value > 127 || input_value < -127){
        // 注: 这里if在进行比较时, C会将右侧的值'强制转换'为左边'对等'的值
        // 如左侧传进来的input_value是一个 unsigned值, 那么在进行 input_value < -127判断时, 右侧的signed -127将会被强制转成 unsigned! (-127将会变成一个'其他的值', 导致判断失效!)

        // static char msg[200] = "Value is out of index! Please provide a value x in -127 < x < 127! \n";
        // static: 保证后面的变量在'离开该函数域'后仍存在, 而不是用默认的auto存储类
        // 这里不进if分支就不会有static声明占内存
        printf("Value %d is out of index! Please provide a value x in -127 < x < 127! \n", input_value);
        return;
    }

    // 备份输入进来的值
    int pos_backup = input_value;
    int is_negative = 0;

    // 对'负数'进行判断
    if(input_value < 0){
        printf("Value %d is a negative value!\n", input_value);
        is_negative = 1;
        // show_bin(input_value);
        // return;
    }

    
    int bin_list[8];
    int bin_length = sizeof(bin_list) / sizeof(bin_list[0]);
    size_t last_index = bin_length - 1; // 数组末尾index, 从后往前依次赋值
    do{
        if(input_value % 2 == -1){ // 负数取余会得-1, 这里进行特殊处理 (其实原则上直接将input_value (-取反)就好了, 但是这样写显得规范一点 XD)
            bin_list[last_index] = -(input_value % 2);
        }else{
            bin_list[last_index] = input_value % 2;
        }
        
        input_value/=2;
        last_index--;
    }while(input_value >= 2 || input_value <= -2);

    // 被除数为1,-1 或 0 (无法继续进行取余操作)
    if(last_index != 0){
        if(input_value != 0){
            // 如果被除数为1, 则在当前的位上写入对应的值 (如果是-1则直接取反)
            if(input_value == -1){
                input_value = -input_value;
            }
            bin_list[last_index] = input_value;
            last_index--;
        }
        // 往前填0, 防止Null
        for(int i=last_index; i>=0; i--){
            bin_list[i] = 0;
        }
    }

    // 针对'负数'的处理
    if(is_negative==1){
        // 在上面的赋值过程中, 负数被转成了正数进行处理, 接下来这里的流程便是我们'手动调转bit' & +1
        // 李奶奶的C用二进制补位存储有符号负数, 实际显示还要靠哥们先转成正数 然后再手动转成二进制补位表示, 我去你的

        // 这个int数组'逐位取反'(0->1, 1->0)
        for(int i=0; i<bin_length; i++){
            if(bin_list[i]==0){
                bin_list[i]=1;
            }else if(bin_list[i]==1){
                bin_list[i]=0;
            }
        }

        // 最精妙的'+1'部分 (拿笔推了半天就这么几行XD)
        int carry = 1;
        for(int i=bin_length-1; i>=0 && carry; i--){ // 从最后一位开始处理, 如果进位符为0则可结束循环 (往前的值不用动了)
            int current_bit_sum = bin_list[i] + carry; // 计算当前位的和
            bin_list[i] = current_bit_sum & 1; // 更新当前位的值
            carry = current_bit_sum >> 1; // 右移'总和'一位, 准备和下一位进行相加 (位数对齐), 右移完的结果如果是1则表示'进位'(需要接着算), 0则表示'无需进位'(结束运算)
        }
        printf("The value has converted to 2's complement for display!\n");
    }

    // 输出
    printf("The binary value of %d is: ", pos_backup);
    for(int i=0; i<bin_length; i++){
        if(i % 4 == 0 && i!=0){
            printf(" %d", bin_list[i]);
        }else{
            printf("%d", bin_list[i]);
        }
    }
    printf("\n");
}