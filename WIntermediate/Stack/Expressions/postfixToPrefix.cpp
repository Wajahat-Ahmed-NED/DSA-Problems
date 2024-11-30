
string postToPre(string exp)
{
    int i = 0;
    stack<string> st;
    string top1 = "";
    string top2 = "";
    string result = "";

    while (i < exp.size())
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z'))
            st.push(string(1, exp[i]));
        else
        {
            top1 = st.top();
            st.pop();
            top2 = st.top();
            st.pop();

            result = exp[i] + top2 + top1;

            st.push(result);
        }
        i++;
    }

    return st.top();
}