// my python solution does not work properly
// c++ works fine
// Source : Leet code
// https://leetcode.com/problems/rotate-image/submissions/971360548/
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {

//         int row=matrix.size();
//         int col=matrix[0].size();
//         cout<<row<<endl;
//         vector<int> firstRow=matrix[0];
        
        
//         int count=0;
//         int total=row*col;

//         int startingCol=0;
//         int startingRow=0;
//         int endingCol=col-1;
//         int endingRow=row-1;
//         // int firstRow=matrix[0];

//         while(count<total){
//             //traverse starting row
//             // int temp[];
//                 // temp.push_back(matrix[ind][endingCol])

//             //traverse ending col
//             for (int ind=startingRow;count<total && ind<=endingRow;ind++){
//                 firstRow.push_back(matrix[ind][endingCol]);
//                 matrix[ind][endingCol]=firstRow[count];
//                 count++;
//             }
//             endingCol--;

//             //traverse ending row
//             for (int ind=endingCol;count<total && ind>=startingCol;ind--){
//                 firstRow.push_back(matrix[endingRow][ind]);
//                 matrix[endingRow][ind]=firstRow[count];
//                 count++;
//             }
//             endingRow--;

//             //traverse starting col
//             for (int ind=endingRow;count<total && ind>=startingRow;ind--){
//                 firstRow.push_back(matrix[ind][startingCol]);
//                 matrix[ind][startingCol]=firstRow[count];
//                 count++;
//             }
//             startingCol--;

//             //traverse starting row
//             for (int ind=startingCol;count<total && ind<=endingCol;ind++){
//                 firstRow.push_back(matrix[startingRow][ind]);
//                 matrix[startingRow][ind]=firstRow[count];
//                 count++;
//             }
//             startingRow++;

//         }
//         // cout << matrix << endl;
//     }
// };

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {

        int n=mat.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                swap(mat[i][j], mat[j][i]);
            }
        }

   //Reversing each row of the matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(mat[i][j], mat[i][n-j-1]);
            }
        }

   //Print the matrix
        cout<<"Rotated Matrix :\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<mat[i][j]<<" ";
            }
                cout<<endl;
        }
}
};