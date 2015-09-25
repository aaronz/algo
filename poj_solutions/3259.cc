#include <iostream>
#include <vector>
using namespace std;

struct path
{
    int x, y, z;
    path(int a, int b, int c) : x(a), y(b), z(c) {};
};
vector<path> vect;
const int MAX = 1 << 20;
int time[501];
int f, n, m, w, a, b, c, start;
bool bellman_ford()
{
    for (int i = 0; i <= n; ++i)
        time[i] = MAX;
    time[a] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < vect.size(); ++j)
            if (time[vect[j].y] > time[vect[j].x] + vect[j].z)
                time[vect[j].y] = time[vect[j].x] + vect[j].z;
    }
    for (int i = 0; i < vect.size(); ++i)
        if (time[vect[i].y] > time[vect[i].x] + vect[i].z)
            return 1;
    return 0;
}

int main()
{
    cin >> f;
    while (f--)
    {
        vect.clear();
        cin >> n >> m >> w;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b >> c;
            if (!i)
                start = a;
            path A(a, b, c), B(b, a, c);
            vect.push_back(A);
            vect.push_back(B);
        }
        for (int i = 0; i < w; ++i)
        {
            cin >> a >> b >> c;
            path A(a, b, -c);
            vect.push_back(A);
        }
        if (bellman_ford())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}