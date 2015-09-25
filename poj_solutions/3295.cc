#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

int main()
{
    char input[101], temp[101];
    stack<char> s;
    int i, j, k, len;
    char result, left, right;
    while (cin >> input && strcmp(input, "0") != 0)
    {
        memset(temp, 0, 101);
        result = '1';
        for (i = 0; i < 32; i++)
        {
            strcpy(temp, input);
            len = strlen(temp);
            for (k = 0; k < len; k++)
            {
                if (temp[k] == 'p')
                    temp[k] = (((i & 1) >> 0) + 48);
                if (temp[k] == 'q')
                    temp[k] = (((i & 2) >> 1) + 48);
                if (temp[k] == 'r')
                    temp[k] = (((i & 4) >> 2) + 48);
                if (temp[k] == 's')
                    temp[k] = (((i & 8) >> 3) + 48);
                if (temp[k] == 't')
                    temp[k] = (((i & 16) >> 4) + 48);
            }
            for (j = len - 1; j >= 0; j--)
            {
                if (temp[j] == '0' || temp[j] == '1')
                    s.push(temp[j]);
                if (temp[j] == 'K')
                {
                    left = s.top();
                    s.pop();
                    right = s.top();
                    s.pop();
                    if (left == '1' && right == '1')
                        s.push('1');
                    else
                        s.push('0');
                }
                if (temp[j] == 'A')
                {
                    left = s.top();
                    s.pop();
                    right = s.top();
                    s.pop();
                    if (left == '0' && right == '0')
                        s.push('0');
                    else
                        s.push('1');
                }
                if (temp[j] == 'N')
                {
                    left = s.top();
                    s.pop();
                    if (left == '0')
                        s.push('1');
                    else
                        s.push('0');
                }
                if (temp[j] == 'C')
                {
                    left = s.top();
                    s.pop();
                    right = s.top();
                    s.pop();
                    if (left == '1' && right == '0')
                        s.push('0');
                    else
                        s.push('1');
                }
                if (temp[j] == 'E')
                {
                    left = s.top();
                    s.pop();
                    right = s.top();
                    s.pop();
                    if (left == '1' && right == '1')
                        s.push('1');
                    else if (left == '0' && right == '0')
                        s.push('1');
                    else
                        s.push('0');
                }
            }

            if (s.top() == '0')
            {
                result = '0';
                s.pop();
                break;
            }
            else
                s.pop();
        }
        if (result == '1')
            cout << "tautology" << endl;
        else
            cout << "not" << endl;

        memset(input, 0, 101);
    }
    //system("pause");
    return 0;
}