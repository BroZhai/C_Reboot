#include<stdio.h>
#include<string.h>
#define PrintLine printf("\n")

// 来详细研究一下C中最重磅的'结构体'struct
// 结构体其实指的就是一种'不同类型数据的集合', 和Java中的 class类极其相似, 但是C这里主要还是以'切面编程'为主进行创建 & 访问 :3

// 创建struct结构体的不同方式
// a. 直接写 (和 枚举ENUM 的创建方式可以说是一摸一样 XD)
/* 
struct 结构体名称{
    成员变量A声明;
    成员变量B;
    ...
} '顺手'创建的"结构体变量";

*/
struct Player
{
    int hp;
    char nickname[50];
    char* profile;
}p1, p2; // 顺手创建的两个'玩家'变量 p1, p2 (类型为 struct Player);
// 上面的'玩家'变量也可以不写, 我们可以在随后的别处用 struct PLayer p1, p2... 进行手动声明 + 赋值 :3

// b. typedef 封装
// 我们知道 typedef 其实就是 对已知的某个数据类型 进行 redefinition (typedef char* charPtr, 之后即可直接用charPtr指代char*) 
// 这里我们直接利用上面的写法, 直接将结构体'封装'起来并起一个'别名'
/*
typedef struct 结构体名称{
    成员变量A声明;
    成员变量B;
    ...
} 结构体'别名';
*/
typedef struct NotPlayer{
    int hp;
    char name[50];
} Enemy; // 这里的'Enemy' 即是 'struct NotPlayer'类型 的 "指代别名"

// c. 匿名结构体 (详情见 ./AnonymousStruct/main.c)

/*-------------------------------------------*/
// 玩家struct'受击'函数 (传入 '玩家'struct变量的'地址', 解引用取得内部的成员变量 hp 并进行修改)
// 注: 如果传的'不是地址', 那么这里的player_enetity则将会是一份'数据拷贝'! 所有的操作将只会作用在'数据拷贝'上 而 不影响'原数据'!
void hit_player(struct Player* player_entity, int damage){
    // 如果传入的数据是一个'struct变量指针', 则需用 '->' 解引用 & 访问其成员变量 (普通struct变量直接用 '.' 去访问就好了)
    player_entity->hp -= damage;
    printf("Player '%s' takes %d damage!\n", player_entity->nickname, damage);
}

// 和上面同理, 这里是'怪物'的受击函数 (传入'怪物struct'的'地址')
void hit_enemy(Enemy* monster_entity, int damage){
    monster_entity->hp -= damage;
    printf("Monster '%s' takes %d damage!\n", monster_entity->name, damage);
}

// 这里用了一种比较硬核的方式来查 玩家/怪物 生命数据, 即直接给地址 & 解引用看 XD
// 其实如果多个结构体有'相同类型的成员'的话, 我们可以将这些'公共成员'提取出来'单独搞成一个(通用)struct', 方便操作 awa
// 详细见./StructTechniques/common_members.c
void check_health(char* name_address, int* hp_address){
    printf("%s's hp is %d now.\n", name_address, *(hp_address));
}

/*-------------------------------------------*/
int main(){
    // Player中的p1, p2均'没有赋值', 如果在'已创建'结构体变量 但 '未赋初始值'的情况下
    // 在后续只能通过p1.xxx = ?, p2.xxx = ?的方式进行赋值 (或者用'结构体变量指针'解引用 & 访问赋值)
    p1.hp = 50;
    strcpy(p1.nickname, "Niko");
    char* p1_profile_address = "I love pancakes";
    p1.profile = p1_profile_address;

    p1.hp -= 10;

    printf("p1's nickname is: %s, hp is: %d, profile content: %s\n", p1.nickname, p1.hp, p1.profile);

    // 但是这样一个个赋值未免有点'太麻烦了', 所以在C99标准中, 有这么个'便携写法' (designated initializer（指定初始化器)
    p2 = (struct Player){.hp = 80, .nickname = "CyanCandy", .profile = "I'm gonna blow up the world!"};
    // 上面的语句 先是在右侧创建了一个'匿名结构体'(包含三个成员变量), 随后用(struct Player)进行强制类型转换后, 再让p2'挨个照搬值'

    /*  具体展开
    struct Player __temp = {.hp = 80, .nickname = "CyanCandy", .profile = "..."};
    p2 = __temp; // 此处p2是从'__temp'中"挨个搬值", 而不是'指向'__temp的内存地址 XD
    */

    /* 也可以写成如下形式 (要求要和结构体成员变量的'定义顺序'一致!)
        p2 = (struct Player) {80, "CyanCandy", "I'm gonna blow up the world"}
    */

    // 若是直接创建的'新结构体变量', 则可以在声明时'直接赋值' (和上面C99的写法标准一样, 可以不写'类型转换')
    struct Player cirno = {.hp = 99, .nickname = "Cirno", .profile = "I'm the strongest!"};
    // cirno.hp -= 10;
    // 也可以写成 struct Player cirno = {99, "Cirno", "I'm the strongest!"}; 注意成员变量'定义顺序'!

    // 用'封装好'的struct别名创建一个'敌人'变量
    Enemy slime = {9, "Slime"}; // 这里slime的类型实际为"struct NotPlayer" 
    // 在创建时, Emeny 已经完整指代了 "struct NotPlayer", 上述语句等效于 struct NotPlayer slime = {...}
    
    // 通过'地址'访问查看双方的血量
    check_health(cirno.nickname, &(cirno.hp));
    check_health(slime.name, &(slime.hp));
    PrintLine;

    // 传入'对象'的地址进对应的函数进行'扣血'操作
    hit_enemy(&slime, 4);
    check_health(slime.name, &(slime.hp));
    hit_player(&cirno, 2);
    check_health(cirno.nickname, &(cirno.hp));
}