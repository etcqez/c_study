#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 水仙花数
// 一个n位数，其各位数字的n次方之和刚好等于该数本身
// 如：153 = 1^3 + 5^3 + 3^3

// 求0-100000所有的水仙花数
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 100000; i++)
    {
        // n表示i的位数
        int n = 0;
        int tmp = i;
        int sum = 0;
        // 求得i的位数
        while (tmp)
        {
            n++;
            tmp /= 10;
        }
        tmp = i;
        // 循环取最后一位并与位数相幂累加
        while (tmp)
        {
            sum += pow(tmp % 10, n);
            tmp /= 10;
        }
        if (sum == i)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
