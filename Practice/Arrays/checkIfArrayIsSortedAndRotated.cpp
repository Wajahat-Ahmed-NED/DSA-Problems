#include<iostream>
#include <vector> // Include the <vector> header
using namespace std;


bool check(vector<int> nums){
    int count=0;
    for(int i=1;i<nums.size();i++){
        if (nums[i-1]>nums[i]){
            count++;
        }
    }

    if (nums[0]<nums[nums.size()-1]){
        count++;
    }

    return count<=1;
}


int main(){
    vector <int> arr={2,3,4,6,7};

    if (check(arr)){

        cout<<"Array is sorted and rotated"<<endl;
    }
    else{

        cout<<"Array is not sorted and rotated"<<endl;
    }
    return 0;
}