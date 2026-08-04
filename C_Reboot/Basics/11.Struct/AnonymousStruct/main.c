#include<stdio.h>
#include<string.h>
#define PrintLine printf("\n")

// 来专门研究一下'匿名结构体'
// 所谓'匿名结构体', 其实就是程序员'懒得写结构体名称'但又想直接用'有这样这一个结构'的变量
// 于是, '匿名结构体'就诞生了

struct {
    int hp;
    char name[50];
} entity1, entity2 = {60, "Second Entity"};
// 像上面这种写法, 就是'直接声明'了两个变量都有'int hp, char name[50]'这样的结构, 可以直接拿来用
// 因为没写结构名, 所以除了两个'直接创建'的结构体变量外, 将不能手动创建额外的'新结构体变量' (struct ??? enitiy3 = ... 没有'结构体名'创建个毛线啊 XD)

// typedef'强行安个名儿': 如果用typedef尝试去创建一个匿名结构体, 那么typedef其实会用'别名'强行给'匿名结构体'起名
// 因为typedef无论如何都要给数据类型一个"别名", 所以typedef创建出来的结构体都是"有名"结构体 XD
typedef struct{
    int id;
    float price;
    char title[100];
} Book;

int main(){
    // 要给'匿名结构体'变量赋值, 只能用 .成员变量 = xxx "挨个赋值" (C99的那套'简便写法'也不管用, 因为没有'结构体名'可以用于'强制类型转换' XD)
    /* entity 1 = (struct ???){.hp = ..., .name = "..."} 强转类型木大了*/
    entity1.hp = 55;
    strcpy(entity1.name, "Starlight");
    printf("Anonymous Struct Variable entity1's name is: %s, hp is: %d \n", entity1.name, entity1.hp);
    printf("Anonymous Struct Variable entity2's name is: %s, hp is: %d \n", entity2.name, entity2.hp);
    PrintLine;
    

    // 而typedef创建的'匿名结构体'变量, 实际上有一个'可用名称', 那C99那套'简便写法'就行得通了 XD
    Book b1 = (Book){.title = "How to learn C?", .price=48.88, .id=14};
    printf("The title of book b1 is: %s, the price: %f, id=%d \n", b1.title, b1.price, b1.id);

    // 但是typedef的内部写的仍是'匿名结构体', 因此内部的结构体仍没有'自己的名字', 所以也不能用'原名'进行创建 (只能用typedef定义的别名)
    // struct ??? b1 = {...}; 无法确定'结构体自己的名字', 故这种写法不支持...
    // 反正记好'没有原名'可用就OK了 :)
}