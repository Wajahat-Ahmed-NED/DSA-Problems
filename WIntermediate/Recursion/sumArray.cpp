// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int isSum(int arr[],int size){
    if (size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    
    int sum=arr[0]+arr[1];
    return sum+isSum(arr+2,size-2);
}

int main() {
    // Write C++ code here
    int arr[6]={2,1,5,100,5,3};
  
    int ans=isSum(arr,6);
    
     cout<<"Sum of Array is "<<ans<<endl;
    
    return 0;
}