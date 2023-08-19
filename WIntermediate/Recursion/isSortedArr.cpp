// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isSorted(int arr[],int size){
    if (size==0 || size==1){
        return true;
    }
    if (arr[0]>arr[1]){
        return false;
    }
    else{
        int remainingPart=isSorted(arr+1,size-1);
        return remainingPart;
    }
}

int main() {
    // Write C++ code here
    int arr[5]={2,3,5,5,5};
  
    bool ans=isSorted(arr,5);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}