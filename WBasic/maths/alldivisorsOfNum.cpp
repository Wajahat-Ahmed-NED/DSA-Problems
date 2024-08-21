#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> arr;

    for(int i=2;i<n;i++){
        if(n%i==0){
            arr.push_back(i);
        }
    }

    for(const c:arr){
        cout<<c<<endl;
    }


    return 0;
}