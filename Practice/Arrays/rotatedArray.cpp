#include <iostream>
#include <vector>
using namespace std;

void rotate(vector <int> &nums, int k){
    vector <int> arr(nums.size());
    for(int i=0;i<nums.size();i++){
        arr[i]=nums[(i+k)%nums.size()];
    }
    nums=arr;
}

int main(){

    vector <int> arr={1,2,4,5};
    int k=2;
    rotate(arr,k);

    for (int i:arr){
        cout<<i<<" ";
    }

    cout<<endl;

    return 0;
}