// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int priority(char x)
{
    unordered_map<char, int> m;
    m['^'] = 3;
    m['*'] = 2;
    m['/'] = 2;
    m['+'] = 1;
    m['-'] = 1;

    return m[x];
}

string reverse(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
        swap(s[i++], s[j--]);

    return s;
}

string reverseWithBracket(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        swap(s[i], s[j]);
        if (s[i] == '(')
            s[i] = ')';
        else if (s[j] == '(')
            s[j] = ')';
        else if (s[i] == ')')
            s[i] = '(';
        else if (s[j] == ')')
            s[j] = '(';

        i++;
        j--;
    }

    return s;
}

string infixToPrefix(string s)
{
    s = reverseWithBracket(s);
    int i = 0;
    stack<int> st;
    string ans = "";

    while (i < s.size())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            ans += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && priority(st.top()) >= priority(s[i]))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && priority(st.top()) > priority(s[i]))
                {
                    ans += st.top();
                    st.pop();
                }
            }

            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    ans = reverse(ans);
    return ans;
}

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    string s = "(A+B)*C-D+F";

    cout << infixToPrefix(s) << endl;

    return 0;
}