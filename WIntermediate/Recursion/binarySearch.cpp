// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool binarySearch(int arr[],int s, int e, int k){
    if (s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==k){
        return true;
    }
    if (arr[mid]<k){
        binarySearch(arr,mid+1,e,k);
    }
    else{
        binarySearch(arr,s,mid-1,k);
    }
}

int main() {
    // Write C++ code here
    cout << "Hello world!";
    int arr[5]={2,3,7,9,43};
    int k=5;
    int s=0;
    int e=4;
    
    bool ans=binarySearch(arr,s,e,k);
    
    if (ans){
        cout<<"Element Found"<<endl;
        
    }
    else{
        cout<<"Element Not Found"<<endl;
    }

    return 0;
}