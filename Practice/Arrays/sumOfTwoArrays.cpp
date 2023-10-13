#include<iostream>
#include<vector>
using namespace std;

vector<int> reversed (vector<int> &arr){
    int i=0;
    int j=arr.size()-1;
    int temp=0;
    
    while(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        // swap(arr[i],arr[j]);


        i++;
        j--;
    }
    return arr;
}

vector<int> findArraySum(vector <int> &a,int n,vector<int>&b,int m){

    vector<int> ans;
    int i=n-1;
    int j=m-1;
    int carry=0;
    int sum=0;

    while(i>=0 && j>=0){
        sum=a[i]+b[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    

    while(i>=0){
        sum=a[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }

    while(j>=0){
        sum=b[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
    }

    while(carry!=0){
        sum=carry;
        carry=sum/10;
        
        ans.push_back(sum);
    }

    return reversed(ans);
}


int main(){

    vector<int> arr1={1,2,4,5,2};
    vector<int> arr2={3,2,5,7,1};
    int n= 4;
    int m= 4;

    vector<int> ans;

    ans=findArraySum(arr1,n,arr2,m);

    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}