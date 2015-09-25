#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int length = 200;
int counts[length];
int main()
{
    int T, i, j, k, n, s, t;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        memset(counts, 0, sizeof(counts));
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d %d", &s, &t);
            if (s > t)
                swap(s, t);
            s = (s - 1) >> 1;
            t = (t - 1) >> 1;
            for (k = s; k <= t; k++)
                ++counts[k];
        }
        printf("%d\n", *max_element(counts, counts + length) * 10);
    }
    return 0;
}