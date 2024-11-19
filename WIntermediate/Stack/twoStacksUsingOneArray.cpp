
// Practice by me
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class TwoStack
{
    int *arr;
    int size;
    int top1;
    int top2;

public:
    TwoStack(int size)
    {
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        this->arr = new int[size];
    }

    void push1(int val)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = val;
        }
    }

    void push2(int val)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = val;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
            return -1;
    }

    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
            return -1;
    }

    int peek1()
    {
        return arr[top1];
    }

    int peek2()
    {
        return arr[top2];
    }
};

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    TwoStack *s = new TwoStack(12);
    cout << s->peek2() << endl;

    return 0;
}