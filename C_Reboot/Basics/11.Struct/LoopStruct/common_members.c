#include<stdio.h>
#define PrintLine printf("\n")

typedef struct CommonAttributes{
    int hp;
    int mp;
    char name[12];
} CommonAttributes;
// 共计 20 Byte

typedef struct Player{
    char* skill; // 8 Byte (指针永远算8 Byte! 在64位OS中)
    char profile[41]; // 41 Byte
    struct CommonAttributes* info; // 8 Byte
} Player; // 8 + (41+7) + 8 = 64 Byte

typedef struct Enemy{
    int anger_value;
    CommonAttributes* info;
} Enemy;

/* ---------------------函数实现区-------------------- */
void hit(CommonAttributes* info, int damage){
    info->hp -= damage;
    printf("%s has taken %d damage! \n", info->name, damage);
}

void heal(CommonAttributes* info, int heal_value){
    info->hp += heal_value;
    printf("%s has received %d recovery. \n", info->name, heal_value);
}

/*-------------------------主函数----------------------- */

int main(){
    CommonAttributes p1_attr = (CommonAttributes){100, 130, "YellowCake"};
    Player p1 = (Player){"Physical Attack", "Joined at 2026.08.06", &p1_attr};
    printf("The size of p1 is: %zu \n", sizeof(p1));
    
    CommonAttributes e1_attr = (CommonAttributes){10, 20, "Slime"};
    Enemy e2 = (Enemy){5, &e1_attr};

    
}