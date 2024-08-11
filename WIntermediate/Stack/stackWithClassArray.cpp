// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (top < size)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflowed" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflowed" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty";
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // Write C++ code here
    // std::cout << "Hello world!";
    Stack s1(5);
    s1.push(23);
    s1.push(45);
    s1.push(34);
    s1.push(13);
    s1.push(12);
    s1.push(12);
    s1.push(233);

    cout << s1.peek() << endl;

    s1.pop();
    // s1.pop();
    // s1.pop();
    s1.pop();

    cout << s1.peek() << endl;
    return 0;
}