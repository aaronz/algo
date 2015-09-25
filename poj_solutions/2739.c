#include<stdio.h>
#include<string.h>
#define MAX 10010
short map[MAX];

void initmap()
{
    int i, j;
    for (i = 1; i < MAX; i++) map[i] = 1;

    for (i = 2; i <= 100; i++)
        if (map[i])
            for (j = 4; j < MAX; j++)
                if (map[j] && i != j && j%i == 0)
                    map[j] = 0;
}

int main()
{
    int n, i, j, sum, count, half;
    initmap();
    while (scanf("%d", &n) != EOF && n != 0)
    {
        count = 0;
        half = n / 2;
        if (map[n]) count++;
        for (j = 1; j<half; j++)
        {
            sum = 0;
            if (!map[j])
                continue;
            for (i = j; i < MAX; i++)
            {
                if (!map[i])
                    continue;
                sum += i;
                if (sum == n)
                {
                    count++;
                    break;
                }
                else if (sum > n || i > half)
                {
                    break;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}