// 在这里实现'apply_double'的具体流程, 对应main.c中引入的'函数签名'
// 编译时两者要一起来编 (gcc main.c impl.c -o baka.exe)
void apply_double(int * value_address){
    // 利用传入的指针精准定位到其对应的值, 直接在'地址'指向的值上完成
    // 故更新操作将会作用在'指针指向的值上', 再次用指针访问时会发现'指着的值'发生了变动
    *value_address *=2;
}