#include<stdio.h>
#include<string.h> // 重磅嘉宾
#define PrintLine printf("\n")

// 研究一下<string.h>头文件中各种常用的方法
// Tips: char数组[] 本质上就是'字符'起始地址, 一个char*指向 和 char[]数组 可以算是等效的 XD
// 但是在细节上有区别, 如 char[] 是'明确声明'的数组, 可以被sizeof()统计长度, 而数组起始地址的char*不行 (sizeof()统计的只是'地址长度'而非'数组长度')

int main(){
    // strcpy(新地址, 原地址);  将'新地址'的字符串内容 用 '原地址'的字符串覆盖, 将返回'新地址'的指针 (和传入的一样)
    // 注: 新地址需要有'足够的大小'来接收'原地址'的字符串内容! (不能用'空指针'! 因为'空指针'并没有实际分配内存大小)
    // char str1[] = "Baka"; // 等效于 char* str1="Baka"; 这里的大小为 5 Byte (4 + 1)
    char str1[] = "Everyone is baka!"; // 18 Byte + 1
    char* str2 = "Pancake"; // 7 Byte + 1
    // char* empty_space; // 这里原本想试试能不能用'空指针'当'接收空间', 结果是不行, '空指针'并没分配任何的'实际存储空间', 导致在strcpy()的时候炸了 XD

    int size1 = sizeof(str1) / sizeof(str1[0]) + 1;
    int size2 = sizeof(str2) / sizeof(str2[0]);
    printf("The current content in str1: %s \nstr2: %s\n", str1, str2);
    printf("The size of str1 is: %d, str2: %d \n", size1, size2);
    PrintLine;

    printf("Doing strcpy()...\n");
    strcpy(str1, str2);
    // strcpy(empty_space, str2);
    size1 = sizeof(str1) / sizeof(str1[0]) + 1;
    printf("The size of str1 is: %d, str2: %d\n", size1, size2); // 可以发现原来声明的'数组大小'并没有变化, 只是内容被完全替换了而已
    printf("The current content in str1: %s \nstr2: %s\n", str1, str2);
    PrintLine;

    // strcat(新地址, 原地址); 将'原地址'的字符内容"拼接"到新地址后面
    // 这里'新地址'的大小也要管够!
    char string_buffer[100] = "Original Content"; // 16 Byte + 1
    char* dlc_string = ", and the dlc content will be concatenated behind here :)"; // 57 Byte + 1
    printf("The content in string_buffer before concatenation: %s \n", string_buffer);
    printf("The total length of string_buffer is now: %u Bytes\n", strlen(string_buffer)); // 16 (未统计'\0')
    strcat(string_buffer, dlc_string);
    printf("The content in string_buffer After concatenation: %s \n", string_buffer);
    // strlen(字符起始地址); 统计字符串长度 Bytes, 不会统计'\0'
    printf("The total length of string_buffer is now: %u Bytes\n", strlen(string_buffer)); // 57 + 16 = 73 (未统计'\0')
    PrintLine;

    // strcmp(a字符串起始地址, b字符串起始地址); '逐位比较'两个字符串的'逐位ASCII大小', 返回一个int值 (在Redis中叫'字典序'比较)
    /**
     * a > b: 返回值>0
     * a = b: 返回值=0
     * a < b: 返回值<0
     */
    // Tips: 小写字符ASCII值 通常比 大写字符 大!
    char* strA = "baka";
    char* strB = "bAka";
    // strA = "Baka"; result < 0 触发
    // strB = "baka"; result = 0 触发
    int result = strcmp(strA, strB);
    if(result > 0){
        printf("strA > strB \n");
    }else if(result == 0){
        printf("strA = strB \n");
    }else{
        printf("strA < strB \n");
    }
    PrintLine;
    // printf("%s", (result>0)? "strA > strB":"strA < strB"); // 混沌邪恶写法, 覆盖不够全面, nonono

    // strchr(字符串起始地址, '查询单字符'); 在给定字符串中查找'指定单字符'的位置, 返回'找到单字符'的地址
    // 如果没有找到对应的字符, 返回的地址则是'全0' (内存不可达)
    char* tgt_str = "bakaBakabaKa";
    char* index_b_address = strchr(tgt_str, 'b');
    char* index_B_address = strchr(tgt_str, 'B');
    char* index_d_address = strchr(tgt_str, 'd'); // 不存在的字符, 看看会返回什么
    printf("tgt_str is: %s, its starting address is: %p\n", tgt_str, (void*)tgt_str);
    printf("The address of 'b' in tgt_str is: %p, dereferenced value: %c \n", (void*)index_b_address, *index_b_address);
    printf("The address of 'B' in tgt_str is: %p, dereferenced value: %c \n", (void*)index_B_address, *index_B_address);
    printf("The address of 'd' in tgt_str is: %p, which is not accessable...\n", (void*)index_d_address);
    PrintLine;

    // strstr(字符串起始地址, "查询字符子串"); 和上面的strchr类似, 不同的是这里查的是"字符子串", 返回"字符子串"的起始地址 (可以理解为利用'字符串'延长"匹配范围", 仍返回匹配的'首字符地址')
    tgt_str = "TeknikoPancake";
    char* index_T_address = strstr(tgt_str, "T");
    char* index_niko_address = strstr(tgt_str, "niko");
    printf("tgt_str is: %s, its starting address is: %p\n", tgt_str, (void*)tgt_str);
    printf("The address of 'T' in tgt_str is: %p, dereferenced value: %c \n", (void*)index_T_address, *index_T_address);
    printf("The address of 'niko' in tgt_str is: %p, dereferenced value: %c \n", (void*)index_niko_address, *index_niko_address); 

}