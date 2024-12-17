#include <stdio.h>

// 要用无符号数，因为如果是-1，%2等于-1，/2就等于0了，循环退出
int count_num_if_1(unsigned int n)
{
    int count = 0;
    while (n)
    {
        if ((n % 2) == 1)
        {
            count++;
        }
        n /= 2;
    }
    return count;
}

int count_num_if_1_2(int n)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((n >> i) & 1) == 1)
        {
            count++;
        }
    }

    return count;
}

int count_num_if_1_3(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}
int main()
{
    int i = count_num_if_1_2(-1);
    printf("%d\n", i);
}