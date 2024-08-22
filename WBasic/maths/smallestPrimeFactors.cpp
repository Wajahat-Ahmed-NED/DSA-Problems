// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;


int main() {
    // Write C++ code here
    cout << "Try programiz.pro";
    vector<int> spf(100000+1,0);
    
    for(int i=0;i<=100000;i++){
        spf[i]=i;
    }
    
    for(int i=2;i*i<=100000;i++){
        
        for(int j=i*i; j<=100000;j+=i){
            if(spf[j]==j){
                spf[j]=i;
            }
        }
    }
    
    int n;
    cin>>n;
    
    while(n!=1){
        cout<<spf[n]<<" "; 
        n=n/spf[n];
    }
    return 0;
}


// /tmp/4t4Bdizb1p.o
// Try programiz.pro17
// 17 

// === Code Execution Successful ===