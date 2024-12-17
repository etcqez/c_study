#include <string.h>
#include <stdio.h>

// 遍历
int my_strlen1(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

// 递归
int my_strlen2(char *str)
{
    if (*str == '\0')
    {
        return 0;
    }
    return my_strlen2(str + 1) + 1;
}

// 指针 - 指针
int my_strlen3(char *str)
{
    char *start = str;
    while (*str != '\0')
    {
        str++;
    }
    return str - start;
}

int main()
{
    int len = my_strlen2("abcdef");
    printf("%d\n", len);
}