#include<stdio.h>
int main()
{
    int sum, index;
    char c;
    while (1)
    {
        c = getchar();
        if (c == '#')
            break;
        sum = c - 'A' + 1;
        index = 1;
        while (c = getchar())
        {
            if (c != '\n')
            {
                index++;
                if (c == ' ')
                    continue;
                sum = sum + (c - 'A' + 1) * index;
            }
            else
                break;
        }
        printf("%d\n", sum);
    }

}