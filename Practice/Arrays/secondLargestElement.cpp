#include <iostream>
#include <vector>
// #include <climit>
#include <algorithm>
using namespace std;

int firstMax(vector<int> &nums){
    int fmax=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>fmax){
            fmax=nums[i];
        }

    }
    return fmax;
}

int secondMax(vector<int> &nums,int fmax){
    int secmax=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>secmax && nums[i]!=fmax){
            secmax=nums[i];
        }

    }
    return secmax;
}

int main(){


    vector <int> arr={1,2,4,6,7};
    int fmax=firstMax(arr);
    int secmax=secondMax(arr,fmax);
    cout<<"First Max element is "<<fmax<<endl;
    cout<<"Second Max element is "<<secmax<<endl;

    return 0;
}