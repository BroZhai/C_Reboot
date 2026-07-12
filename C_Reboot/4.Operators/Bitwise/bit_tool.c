// C中并没有内置显示数值'二进制表示'的相关工具, 要自己实现 owo...
#include<stdio.h>
#include"bit_tool.h"

// 显示一个有符号数的'二进制表示', 限制8位bit (范围 -127 < x < 127)
// 目前只能处理 0 - 127正数范围, 开动脑筋想想负数怎么处理...
void show_bin(signed int pos_val){
    if(pos_val > 127 || pos_val < -127){
        // 注: 这里if在进行比较时, C会将右侧的值'强制转换'为左边'对等'的值
        // 如左侧传进来的pos_val是一个 unsigned值, 那么在进行 pos_val < -127判断时, 右侧的signed -127将会被强制转成 unsigned! (-127将会变成一个'其他的值', 导致判断失效!)

        // static char msg[200] = "Value is out of index! Please provide a value x in -127 < x < 127! \n";
        // static: 保证后面的变量在'离开该函数域'后仍存在, 而不是用默认的auto存储类
        // 这里不进if分支就不会有static声明占内存
        printf("Value %d is out of index! Please provide a value x in -127 < x < 127! \n", pos_val);
        return;
    }
    
    int pos_backup = pos_val;
    int bin_list[8];
    int bin_length = sizeof(bin_list) / sizeof(bin_list[0]);
    size_t last_index = bin_length - 1;
    do{
        bin_list[last_index] = pos_val % 2; 
        pos_val/=2;
        last_index--;
    }while(pos_val >= 2);
    if(last_index != 0){
        if(pos_val != 0){
            bin_list[last_index] = pos_val;
            last_index--;
        }
        for(int i=last_index; i>=0; i--){
            bin_list[i] = 0;
        }
    }

    printf("The binary value of %d is: ", pos_backup);
    for(int i=0; i<bin_length; i++){
        if(i==4){
            printf(" %d", bin_list[i]);
        }else{
            printf("%d", bin_list[i]);
        }
    }
}