#include <iostream>
#include <string>
#include <stack>
using namespace std;


void Recur(stack<char> &st, string pre, string in)
{
    //cout<<pre<<' '<<in<<endl;
    if (pre.length() == 0)
        return;
    char root = pre[0];
    st.push(root);
    int index = 0;
    while (in[index] != root)
        index++;
    string preleft = pre.substr(1, index);
    string preright = pre.substr(index + 1, in.length() - index - 1);
    string inleft = in.substr(0, index);
    string inright = in.substr(index + 1, in.length() - index - 1);
    //cout<<preleft<<' '<<preright<<' '<<inleft<<' '<<inright<<endl;
    Recur(st, preright, inright);
    Recur(st, preleft, inleft);
}

int main()
{
    string pre, in;
    stack<char> st;
    while (cin >> pre >> in)
    {
        Recur(st, pre, in);
        while (!st.empty())
        {
            char c = st.top();
            st.pop();
            cout << c;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}