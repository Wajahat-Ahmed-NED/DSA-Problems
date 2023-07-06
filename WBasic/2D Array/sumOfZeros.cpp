// Source: Coding Ninjas
https://www.codingninjas.com/codestudio/problems/array-sum_893287?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=1

#include <bits/stdc++.h> 
int coverageOfMatrix(vector<vector<int>> &mat) {
    // Write your code here.
    int rows=mat.size();
    int cols=mat[0].size();
    int count=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (mat[i][j]==0){
                if (i-1>=0){
                    if (mat[i-1][j]==1){
                        count+=1;
                    }
                }
                if (i+1<rows){
                    if (mat[i+1][j]==1){
                        count+=1;
                    }
                }
                if (j-1>=0){
                    if (mat[i][j-1]==1){
                        count+=1;
                    }
                }
                
                if (j+1<cols){
                    if (mat[i][j+1]==1){
                        count+=1;
                    }
                }
            }
        }
    }
    return count;
}
