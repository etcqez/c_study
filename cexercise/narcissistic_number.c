#include <stdio.h>
#include <math.h>
// 变种水仙花数
// 12345
// 1*2345+12*345+123*45+1234*5
// 12345/10=1234 12345%10=5
// 12345/100=123 12345%100=45
int main()
{
    for (int i = 10000; i <= 99999; i++)
    {
        int sum = 0;
        for (int j = 0; j <= 4; j++)
        {
            int k = (int)pow(10, j);
            sum += (i % k) * (i / k);
        }
        if (sum == i)
        {
            printf("%d ", i);
        }
    }
}