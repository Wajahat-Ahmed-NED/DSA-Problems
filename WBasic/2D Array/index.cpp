// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isPrime(int arr[][4],int search, int row, int col){
    for (int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            if (arr[row][col]==search){
                return 1;
            }
        }
    }
    return 0;
}

void rowWiseSum(int arr[][4]){
    int sum=0;
    for (int row=0;row<3;row++){
        sum=0;
        for (int col=0;col<4;col++){
            sum+=arr[row][col];
        }
        cout<<row<<" Row Sum is "<<sum;
        cout<<endl;
    }
    
}

void colWiseSum(int arr[][4]){
    int sum=0;
    for (int row=0;row<4;row++){
        sum=0;
        for (int col=0;col<3;col++){
            sum+=arr[col][row];
        }
        cout<<row<<" Col Sum is "<<sum;
        cout<<endl;
    }
    
}


void largestRowSum(int arr[][4]){
    int max=0;
    int rowIndex=-1;
    for (int row=0;row<3;row++){
        int sum=0;
        for (int col=0;col<4;col++){
            sum+=arr[row][col];
        }
        if (sum>max){
            max=sum;
            rowIndex=row;
        }
    }
    cout<<"Largest Sum row is "<<rowIndex<<endl;
    cout<<"Largest Sum is "<<max<<endl;
    
}

void wavePrint(int arr[][4]){
     for (int col=0;col<4;col++){
        //int sum=0;
        if (col%2==0){
            
            for (int row=0;row<3;row++){
                cout<<arr[row][col];
            }
            
        }
        else{
            for (int row=3-1;row>=0;row--){
                cout<<arr[row][col];
            }
        cout<<endl;
        }
        
    }
}

int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    int arr[3][4];
    for (int row=0; row<3;row++){
        for (int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    for (int row=0; row<3;row++){
        for (int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    int search;
    cin>>search;
    if (isPrime(arr,search,3,4)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    rowWiseSum(arr);
    colWiseSum(arr);
    largestRowSum(arr);
    wavePrint(arr);
    // cout<<arr;
    return 0;
}