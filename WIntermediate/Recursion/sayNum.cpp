// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void sayNum(int n, string arr[]){
    
    if (n==0){
        return ;
    }
    
    int digit=n%10;
    n=n/10;
    sayNum(n,arr);
    cout<<arr[digit]<<" ";
    
    
}
int main() {
    // Write C++ code here
    int n;
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    cout << "Enter Number!";
    cin>>n;
    sayNum(n,arr);

    return 0;
}