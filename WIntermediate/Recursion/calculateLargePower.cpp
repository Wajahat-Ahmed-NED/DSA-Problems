// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int power(int a, int b){
    if (b==0){
        return 1;
    }
    if (b==1){
        return a;
    }
    
    int ans=power(a,b/2);
    
    if(b%2==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}

int main() {
    // Write C++ code here
    cout << "Hello world!";
    int a=3;
    int b=11;
    int ans=power(a,b);
    cout<<"The ans is found to be "<<ans<<endl;
    return 0;
}