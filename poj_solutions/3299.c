#include<stdio.h>
#include<math.h>
#define MAX 9999

double tot(double d, double h)
{
    return h - 0.5555 * (6.11 * exp(5417.753 / 273.16 * d / (d + 273.16)) - 10);
}

double tod(double t, double h)
{
    return 1 / (1 / 273.16 - log(((h - t) / 0.5555 + 10) / 6.11) / 5417.7530) - 273.16;
}

double toh(double t, double d)
{
    return t + 0.5555 * (6.11 * exp(5417.753 / 273.16 * d / (d + 273.16)) - 10);
}

int main()
{
    double h, t, d;
    double x, y;
    char a, b;
    while (scanf("%c %lf %c %lf\r\n", &a, &x, &b, &y) && a != 'E')
    {
        h = t = d = MAX;

        if (a == 'T')
            t = x;
        else if (a == 'D')
            d = x;
        else
            h = x;

        if (b == 'T')
            t = y;
        else if (b == 'D')
            d = y;
        else
            h = y;

        if (h == MAX)
            h = toh(t, d);
        else if (t == MAX)
            t = tot(d, h);
        else
            d = tod(t, h);
        printf("T %.1f D %.1f H %.1f\r\n", t, d, h);
    }
}