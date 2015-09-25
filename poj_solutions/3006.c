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
    prime[0] = prime[1] = 1;
}

int main()
{
    int a, d, n, i;
    init();
    while (scanf("%d %d %d", &a, &d, &n) != EOF && (a | d | n))
    {
        //printf("%d %d %d\n",a,d,n);
        i = 1;
        if (!prime[a]) n--;
        while (n > 0)
        {
            while (prime[a + (d*i)])
            {
                i++;
            }
            n--;
            i++;
        }
        printf("%d\n", a + (d*(i - 1)));
    }
    return 0;
}