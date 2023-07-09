// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;
int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    stack<int> a;
    a.push(2);
    a.push(4);
    
    a.pop();
    cout<<"Top Element is "<<a.top()<<endl;
    cout<<"Size is "<<a.size()<<endl;
    if(a.empty()){
        cout<<"Stack is empty "<<endl;
    }
    else{
        cout<<"Stack is Not Empty "<<endl;
    }
    
    return 0;
}