#include <stdio.h>

// 判断当前机器字节序
// 小端字节序存储
// 低位字节序存放在低位地址

int main(int argc, char const *argv[])
{

    // 内存地址：低------------高
    // 存储形式：01 00 00 00 低放低
    // 为小端
    int a = 1;
    // 强制转换，再解引用
    if (*(char *)&a == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }

    return 0;
}
