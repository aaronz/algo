#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<char> v;
    int q;
    int p[21];
    int t, n, m, i, j, current, count;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        m = n;
        v.clear();
        memset(p, 0, sizeof(p));
        while (m > 0)
        {
            cin >> q;
            p[n - m] = q;
            m--;
        }
        m = n;
        current = 0;
        for (i = 0; i < m; i++)
        {
            j = p[i] - current;
            while (j > 0)
            {
                v.push_back('(');
                current++;
                j--;
            }
            v.push_back(')');
        }
        t--;
        m = n;
        for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
        {
            count = 0;
            if (*it == ')')
            {
                vector<char>::iterator it2 = it;
                while (*it != '(')
                {
                    if (*it == ')')
                        count++;
                    it--;
                }
                *it = '0';
                it = it2;
                cout << count;
                m--;
                if (m != 0)
                    cout << ' ';
            }
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}