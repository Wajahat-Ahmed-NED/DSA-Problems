// Source LeetCode
// https://leetcode.com/problems/spiral-matrix/description/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();

        int count=0;
        int total=row*col;

        int startingCol=0;
        int startingRow=0;
        int endingRow=row-1;
        int endingCol=col-1;

        while(count<total){
            //print starting row
            for (int ind=startingCol;count<total && ind<=endingCol;ind++){
                ans.push_back(matrix[startingRow][ind]);
                count++;
            }
            startingRow++;

            //print ending col
            for (int ind=startingRow;count<total && ind<=endingRow;ind++){
                ans.push_back(matrix[ind][endingCol]);
                count++;
            }
            endingCol--;

            //print ending row
            for (int ind=endingCol;count<total && ind>=startingCol;ind--){
                ans.push_back(matrix[endingRow][ind]);
                count++;
            }
            endingRow--;

            //print starting col
            for (int ind=endingRow;count<total && ind>=startingRow;ind--){
                ans.push_back(matrix[ind][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};