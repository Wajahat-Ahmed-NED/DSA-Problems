// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool linearSearch(int arr[],int size,int key){
    if (size==0){
        return false;
    }
    if (arr[0]==key){
        
        return true;
    }
    else{
        int remainingPart=linearSearch(arr+1,size-1,key);
       
        return remainingPart;
    }
}

int main() {
    // Write C++ code here
    int arr[5]={2,3,5,3,5};
    int key=5;
    bool ans=linearSearch(arr,5,key);
    if(ans){
        cout<<"Element Found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}