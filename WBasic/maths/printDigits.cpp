// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    
    while(n!=0){
        cout<<n%10;
        n=n/10;
    }
    return 0;
}

// or

#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    // Write C++ code here
    cout << "Try programiz.pro"<<endl;
    
    int n;
    cin>>n;
    
    n=(int)(log10(n)+1);
    
    cout<<n;

    return 0;
}