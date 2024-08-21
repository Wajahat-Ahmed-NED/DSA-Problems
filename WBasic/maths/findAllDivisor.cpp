// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    cout << "Try programiz.pro";
    
    int n;
    cin>>n;
    
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<i<<" ";          
        }
    }
    
    
    return 0;
}


// More Optimized Approach

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    cout << "Try programiz.pro";
    
    int n;
    cin>>n;
    
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if(n%i!=i){
                cout<<n/i<<" ";
            }
        }
    }
    
    
    return 0;
}