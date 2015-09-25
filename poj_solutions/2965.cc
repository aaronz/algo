#include<iostream>
using namespace std;

int main()
{
    char c;
    int i, j, n, x, y, count, temp, tempj, min = 17, state = 0;
    for (i = 0; i < 16; i++)
    {
        cin >> c;
        if (c == '+')
            state += 1 << i;
    }
    for (i = 0; i < 65536; i++)
    {
        count = 0;
        temp = state;
        for (j = 0; j < 16; j++)
        {
            if (i & (1 << j))
            {
                count++;
                temp ^= (1 << j);
                x = j % 4;
                y = j / 4;
                for (n = 0; n < 4; n++)
                {
                    temp ^= 1 << (n * 4 + x);
                    temp ^= 1 << (y * 4 + n);
                }
            }
        }
        if (temp == 0 && count < min)
        {
            tempj = i;
            min = count;
        }
    }
    if (min < 17)
    {
        cout << min << endl;
        for (j = 0; j < 16; j++)
            if (tempj & (1 << j))
                cout << j / 4 + 1 << ' ' << j % 4 + 1 << endl;
    }
    else
        cout << "Impossible" << endl;
    return 0;
}