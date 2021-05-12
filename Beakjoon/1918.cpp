#include <iostream>
#include <string>
#include <stack>
using namespace std;

string post_order(string str)
{
    stack<char> st;
    string temp = "";
    int bracket = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while (1)
            {
                if (st.empty() || st.top() == '(' || ((st.top() == '+' || st.top() == '-') && (str[i] == '*' || str[i] == '/')))
                {
                    st.push(str[i]);
                    break;
                }
                else
                {
                    temp += st.top();
                    st.pop();
                }
            }
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (st.top() != '(')
            {
                temp += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            temp += str[i];
        }
    }

    while (!st.empty())
    {
        temp += st.top();
        st.pop();
    }

    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    cin >> str;

    cout << post_order(str) << "\n";
    return 0;
}
