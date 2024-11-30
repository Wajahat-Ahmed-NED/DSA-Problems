// TC O(N)+O(N)
// SC O(N) + O(N)

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

string infixToPostfix(string s)
{

    string ans = "";
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
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
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}
