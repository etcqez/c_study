#include <stdio.h>
#include <stdlib.h>

// 把字符串每个单词逆序
void reverse(char *left, char *right)
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main(int argc, char const *argv[])
{
    char arr[101] = "Hello World!";
    // 可以装空格
    char *start = arr;
    while (*start)
    {
        char *end = start;
        while (*end != ' ' && *end != '\0')
        {
            end++;
        }
        reverse(start, end - 1);
        if (*end != '\0')
        {
            end++;
        }
        start = end;
    }
    printf("%s\n", arr);

    return 0;
}
