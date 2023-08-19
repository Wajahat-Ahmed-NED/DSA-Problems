// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void isSorted(int *arr,int n){
    if (n==0 || n==1){
        return;
    }
    
    for (int i=0;i<n-1;i++){
        if (arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    isSorted(arr,n-1);
}

int main() {
    // Write C++ code here
    cout << "Hello world!"<<endl;;
    int arr[6]={3,5,3,6,8,0};
    int size=6;
    isSorted(arr,size);
    
    for( int i=0; i<size;i++){
    cout<<arr[i]<<endl;
        
    }

    return 0;
}