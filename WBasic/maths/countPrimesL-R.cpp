#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> getSieve(int n) {
        
        vector<int> arr(n+1, true);
        arr[0]=arr[1]=false;
        int cnt=0;

        for(int i=2;i*i<=n;i++){
            if(arr[i]){
                for(int j=i*i; j<=n; j= i==2 ? j+i : 2*i+j){
                    arr[j]=false;
                }
            }
        }
      return arr;
    }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    //write code to take input also
    int max_int=1000000;
    vector<int> prime=getSieve(max_int);
    int cnt=0;
    for(int i=2;i<max_int;i++){
        cnt=cnt+prime[i];
        prime[i]=cnt;        
    }
    
    int q;
    cin >> q;

    // Process each query
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        // Handle edge case when l is 1
        cout << prime[r-1] - prime[l] << endl;
    }
    
    
//     for(int i=0;i<q.size();i++){
//         int l=q[i][0];
//         int r=q[i][1];
        
//         cout<<prime[r]-prime[l-1]<<endl;
//     }
    
    return 0;
}
