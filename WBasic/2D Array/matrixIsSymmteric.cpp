// Source: Coding Ninjas
// https://www.codingninjas.com/codestudio/problems/matrix-is-symmetric_799361?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0


#include <bits/stdc++.h> 
bool isMatrixSymmetric(vector<vector<int>> matrix){
    // Write your code here.
    int rows=matrix.size();
    int cols=matrix[0].size();

    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            // cout<<matrix[i][j]<<matrix[j][i]<<endl;
            if (matrix[i][j]!= matrix[j][i]){
               
                return false;
                // break;
            }
        }
    }
    return true;
}