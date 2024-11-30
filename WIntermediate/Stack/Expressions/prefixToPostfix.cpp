
string preToPost(string exp)
{
    int i = exp.size() - 1;
    stack<string> st;
    string top1 = "";
    string top2 = "";

    while (i >= 0)
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z'))
            st.push(string(1, exp[i]));
        else
        {
            top1 = st.top();
            st.pop();
            top2 = st.top();
            st.pop();

            st.push(top1 + top2 + exp[i]);
        }
        i--;
    }

    return st.top();
}