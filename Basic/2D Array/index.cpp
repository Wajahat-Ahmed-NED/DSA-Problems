// Online C++ compiler to run C++ program online
// Just for practicing
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    // cout << "Hello world!";
    int arr[3][4];
    // int arr[3][4]={1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 ,11 ,12};//memory ma ayesy store hota ha but visualize matrix ki tarah krengy
    // formula for putting memory elements into matrix is col*i+j where col= total cols, i=row index, j= col index
    
    // int arr[3][4]={{1 ,2 ,3 ,4} ,{5 ,6 ,7 ,8} ,{9 ,10 ,11 ,12}}; is tarah bhi krskty han
    //taking column wise input
    // for (int row=0;row<4;row++){
    //     for (int col=0;col<3;col++){
    //         cin>>arr[col][row];
    //     }
    // }
    
    // taking row wise input
    for (int row=0;row<3;row++){
        for (int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    
    // cout<<arr
    for (int row=0;row<3;row++){
        for (int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    return 0;
}