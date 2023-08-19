// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool checkPalindrome(string& name,int i, int n){
    if(i>=n-i-1){
        return true;
    }
    // swap(name[i],name[n-i-1]);
    if (name[i]!=name[n-i-1]){
        return false;
    }
  
    i++; 
    checkPalindrome(name,i,n);
}
int main() {
    // Write C++ code here
    cout << "Hello world!";
    string name="ab";
    bool ans=checkPalindrome(name,0,name.length());
    if (ans){
        cout<<"String is Palindrome "<<endl;
    }
    else{
        cout<<"String is not Palindrome"<<endl;
    }
    return 0;
}