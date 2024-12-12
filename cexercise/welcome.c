#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "Welcome China!!!";

    int l = 0;
    int r = strlen(str1) - 1;

    printf("%d %d\n", l, r);
    for (l, r; l < r; l++, r--)
    {
        for (int i = 0; i < strlen(str1); ++i)
        {
            if (i <= l || i >= r)
            {
                printf("%c", str1[i]);
            }
            else
            {
                printf("%s", "#");
            }
        }
        printf("%s","\n");
    }

    return 0;
}
