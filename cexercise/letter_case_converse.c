#include <stdio.h>
#include <ctype.h>

// 循环字母大小写转换
// scanf读取成功时返回字符个数，失败时返回EOF
int meth01()
{
    char ch = 0;
    // while (scanf("%c", &ch) == 1)
    while (scanf("%c", &ch) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            printf("%c\n", ch - 32);
        }
        else if (ch >= 'A' && ch >= 'Z')
        {
            printf("%c\n", ch + 32);
        }
        getchar();
    }
}

int main()
{
    char ch = 0;
    while (scanf("%c", &ch) != EOF)
    {
        if (islower(ch))
        {
            printf("%c\n", toupper(ch));
        }
        else if (isupper(ch))
        {
            printf("%c\n", tolower(ch));
        }
        getchar();
    }
}