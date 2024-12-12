#include <stdio.h>
#include <string.h>

//利用临时变量交换左右坐标
int method1(char* str, int sz)
{
    int left = 0;
    int right = sz - 2;
    while (left < right)
    {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        left++;
        right--;
    }
    return 0;
}

//递归
//交换abcdefg = 交换a和g加上逆序bcdef
int method2(char* str)
{
    //*str 表示第一个字符
    //保存第一个字符
    char tmp = *str;
    int len = strlen(str);

    //将第一个字符赋值给最后一个字符
    *str = *(str + len - 1);

    //*(str + len -1)表示g(最后一个字符)
    //将最后一个字符置空
    *(str + len - 1) = '\0';

    //因为最后字符已为空，此时递归第二个到倒数第二个
    if (strlen(str + 1) >= 2)
    {
        method2(str + 1);
    }

    //最后一个字符赋值给tmp
    *(str + len - 1) = tmp;
}

void method3(char* str, int left, int right)
{
    if (left < right)
    {
        method3(str, left + 1, right - 1);
    }
    char tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;
}

int main(void)
{
    char arr[] = "abcdefg";
    int sz = sizeof(arr) / sizeof(arr[0]);

    // method1(arr, sz);
    // method2(arr);
    int left = 0;
    int right = strlen(arr) - 1;
    method3(arr, left, right);
    printf(arr);
}
