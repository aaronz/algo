#include<stdio.h>
#define MAX 1000001
int prime[MAX];

void init()
{
    int i, j;
    for (i = 2; i < MAX; i++)
        if (!prime[i])
            for (j = 2; i*j < MAX; j++)
                prime[i*j] = 1;
    //for(i = 0; i<MAX;i++)
    //if(!prime[i])
    //printf("%d ",i);
}

int main()
{
    int n, i;
    init();
    while (scanf("%d", &n) == 1 && n)
    {
        for (i = 3; i <= n / 2; i += 2)
            if (prime[i] == 0 && prime[n - i] == 0)
            {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        if (i > n / 2)
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}