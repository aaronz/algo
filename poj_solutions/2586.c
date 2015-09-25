#include<stdio.h>
int main()
{
    int s, d;
    int i, sum;
    while (scanf("%d %d", &s, &d) != EOF)
    {
        if (s >= 4 * d)
            printf("Deficit\n");
        else
        {
            i = 1;
            while (i < 5)
            {
                if (((5 - i)*s - i*d) < 0)
                {
                    if (i == 4)
                        sum = 3 * s - 9 * d;
                    else
                        sum = (12 - 2 * i)*s - 2 * i*d;
                    if (sum >= 0)
                        printf("%d\n", sum);
                    else
                        printf("Deficit\n");
                    break;
                }
                i++;
            }
        }
    }
    return 0;
}