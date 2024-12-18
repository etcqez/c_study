#include <stdio.h>
#include <stdlib.h>
// 求a+aa前n项之和
// 例如：2 + 22 + 222 + 2222 + 22222
// 求每项：2
// 22*10+2 = 222
// 222*10+2 = 2222
// 2222*10+2 = 22222
int main()
{
    int a = 0;
    int n = 0;
    scanf("%d %d", &a, &n); // 2 5
    int sum = 0;
    // 表示每一项
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k = k * 10 + a;
        sum += k;
    }
    printf("%d\n", sum);

    return 0;
}