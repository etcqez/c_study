#include <stdio.h>

// 统计两个数不同位的个数
int count_diff_bit(int m, int n)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((m >> i) & 1 != (n >> i) & 1)
        {
            count++;
        }
    }
    return count;
}

// 先异或，再统计1的个数
int count_diff_bit_2(int m, int n)
{
    int count = 0;
    int ret = m ^ n;
    while (ret)
    {
        ret = ret & (ret - 1);
        count++;
    }
    return count;
}
int main()
{
    int ret = count_diff_bit_2(1999, 2299);
    printf("%d\n", ret);
}