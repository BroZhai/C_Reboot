#include<stdio.h>
#define PrintLine printf("\n")

// 研究一下结构体的'大小分配'究竟是怎样的, 主要看看'成员补位' 和 '最长数据类型'对齐
/*
    成员补位: 每一个成员变量的都需要有自己的'完整存储空间', 即 '起始位置' % 自身大小 = 0! 如果不为0, 则前面的数值则需要'补位', 将后面的值'挤'到正确的位置上
    最长对齐: 所有内部成员补好位后, 最终累加出来的'总大小' % 成员变量的最大'类型大小' 要 = 0
    (如成员中最大的数据类型为 long long int, 则是 '总大小' & 16 Byte == 0, '总大小'不够就往上扩张(对齐)! )
 */

typedef struct Player{
    char code; // 1 Byte ( 1 % 1 = 0, 无需补位)
    int id; // 4 Byte (原本会放在1 Byte后面, 1 % 4(自身存储长度) ≠ 0, 触发'Padding补位', char补3Byte, 将int id放在'第3Byte'后(4 Byte开始), 4 % 4 = 0)
    float money; // 4 Byte (放在'第7Byte'后 (8 Byte 开始), 8 % 4 = 0, 无需补位)
} Player;
// 共计 (1+3) + 4 + 4 = 12 Byte
// 12 % 4(最大数据类型) == 0 (无需对齐)

typedef struct Enemy{
    char code; // 1 Byte
    double money; // 8 Byte (前面char 补7Byte)
    char name[5]; // 5 Byte
} Enemy;
// 共计 (1+7) + 8 + 5 = 21 Byte
// 21 % 8(最大数据类型) ≠ 0, 21 --扩充对齐到--> 24, 24 % 8 == 0 (24为能最近%8 得 0 的数)

typedef struct Npc{
    long double money; // 16 Byte
    char code; // 1 Byte
} Npc;
// 共计 16 + 1 = 17 Byte
// 17 % 16(最大数据类型) ≠ 0, 17 ----> 32, 32 % 16 == 0

int main(){
    Player p1 = (Player) {'A', 114, 9.99};
    char* ptr_to_p1 = (char*) &p1;
    *(ptr_to_p1+4) += 5; // 114 + 5
    printf("The size of Player p1 is: %zu Bytes.\n", sizeof(p1)); // 12 Byte
    printf("The id of p1 is: %d \n", *(ptr_to_p1+4)); // 跳过 1 Byte char + 3 Byte 补位
    PrintLine;

    Enemy e1 = (Enemy){'B', 99.99, "Slime"};
    char* ptr_to_e1 = (char*) &e1;
    printf("The size of Enemy e1 is: %zu Bytes.\n", sizeof(e1)); // 24 Byte
    printf("The name of e1 is: %s\n", ptr_to_e1+8+8); // 跳过前 (1 Byte char + 7 Byte 补位) + (8 Byte double)
    PrintLine;

    Npc n1 = (Npc){999.99, 'C'};
    char* ptr_to_n1 = (char*) &n1;
    printf("The size of Npc n1 is: %zu Bytes.\n", sizeof(n1)); // 32 Byte
    printf("The code of n1 is: %c \n", *(ptr_to_n1+16)); // 跳过前 16 Byte long long int
}