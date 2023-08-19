// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void reversed(string& name,int i, int n){
    if(i>=n-i-1){
        return;
    }
    swap(name[i],name[n-i-1]);
  
    i++; 
    reversed(name,i,n);
}
int main() {
    // Write C++ code here
    cout << "Hello world!";
    string name="wajahat";
    reversed(name,0,name.length());
    cout<<"Reversed Name is "<<name<<endl;
    return 0;
}