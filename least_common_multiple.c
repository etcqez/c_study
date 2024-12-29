#include <stdio.h>
#include <stdlib.h>

// 计算最小公倍数
//  int main(int argc, char const *argv[])
//  {
//      int a = 3;
//      int b = 5;

//     int m = (a > b ? a : b);
//     while (1)
//     {
//         if(m%a==0&&m%b==0){
//             break;
//         }
//         m++;
//     }
//     printf("%d\n", m);

//     return 0;
// }

// 从1开始乘以a模b，不等于0，就是最小公倍数
int main(int argc, char const *argv[])
{
    int a = 5;
    int b = 9;
    int i = 1;
    while (a * i % b)
    {
        i++;
    }
    printf("%d\n", i * a);
    return 0;
}
