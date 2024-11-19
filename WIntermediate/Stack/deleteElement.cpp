// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void deleteMiddle(stack<int> &s, int count, int size)
{
    if (count == size / 2)
    {
        s.pop();
        return;
    }

    int top = s.top();
    s.pop();
    deleteMiddle(s, count + 1, size);
    s.push(top);
};

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    vector<int> values = {1, 2, 56, 7, 4};
    stack<int> s;

    for (int value : values)
    {
        s.push(value);
    }

    int count = 0;
    deleteMiddle(s, count, s.size());
    cout << endl;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}