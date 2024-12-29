#include <stdio.h>

// 将数组的奇数移向左边，偶数移向右边
void move_odd_even(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;

    while (left < right)
    {
        // 从左向右找一个偶数，停下来，跳过奇数
        while (((left < right) && (arr[left] % 2 == 1)))
        {
            left++;
        }
        // 从右向左找一个奇数，停下来，跳过偶数
        while (((left < right) && (arr[right] % 2 == 0)))
        {
            right--;
        }
        // 交换奇数和偶数
        if (left < right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }
}
int main(int argc, char const *argv[])
{
    int arr[10] = {0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < sz; i++)
    {
        arr[i] = 1;
    }

    move_odd_even(arr, sz);

    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
