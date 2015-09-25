#include<iostream>
#include<fstream>
#include<fstream>
using namespace std;
struct Node{
    int x, y;
    char d;
}node[120];
int main()
{
    //ifstream cin("a.txt");
    int value[110][110];
    int tot, a, b, n, m, robot, num;
    char order;
    cin >> tot;
    while (tot--)
    {
        cin >> a >> b;
        cin >> n >> m;
        memset(value, 0, sizeof(value));
        for (int i = 1; i <= n; i++)
        {
            cin >> node[i].x >> node[i].y >> node[i].d;
            value[node[i].x][node[i].y] = i;
        }
        int temp = 1;
        for (int i = 1; i <= m; i++)
        {
            cin >> robot >> order >> num;
            if (temp)
            {
                for (int j = 1; j <= num; j++)
                {
                    if (order == 'L')
                    {
                        if (node[robot].d == 'N')
                            node[robot].d = 'W';
                        else if (node[robot].d == 'W')
                            node[robot].d = 'S';
                        else if (node[robot].d == 'S')
                            node[robot].d = 'E';
                        else node[robot].d = 'N';
                    }
                    else if (order == 'R')
                    {
                        if (node[robot].d == 'N')
                            node[robot].d = 'E';
                        else if (node[robot].d == 'E')
                            node[robot].d = 'S';
                        else if (node[robot].d == 'S')
                            node[robot].d = 'W';
                        else node[robot].d = 'N';
                    }
                    else {
                        value[node[robot].x][node[robot].y] = 0;
                        if (node[robot].d == 'N')
                            node[robot].y++;
                        else if (node[robot].d == 'E')
                            node[robot].x++;
                        else if (node[robot].d == 'S')
                            node[robot].y--;
                        else node[robot].x--;
                        if (value[node[robot].x][node[robot].y])
                        {
                            printf("Robot %d crashes into robot %d\n", robot, value[node[robot].x][node[robot].y]);
                            temp = 0; break;
                        }
                        else if (!node[robot].x || !node[robot].y || node[robot].x == a + 1 || node[robot].y == b + 1)
                        {
                            printf("Robot %d crashes into the wall\n", robot);
                            temp = 0; break;
                        }
                        else value[node[robot].x][node[robot].y] = robot;
                    }
                    if (!temp)break;
                }
            }
        }
        if (temp)printf("OK\n");
    }
    return 0;
}