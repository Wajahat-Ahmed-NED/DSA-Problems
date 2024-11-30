
string preToInfix(string exp)
{

    int i = exp.size() - 1;
    stack<string> st;
    string top1 = "";
    string top2 = "";
    string finalString = "";

    while (i >= 0)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
            st.push(string(1, exp[i]));
        else
        {
            if (st.size() < 2)
                return "";

            top1 = st.top();
            st.pop();
            top2 = st.top();
            st.pop();

            finalString = '(' + top1 + exp[i] + top2 + ')';

            st.push(finalString);
        }
        i--;
    }

    return st.top();
}