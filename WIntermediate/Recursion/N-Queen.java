// BruteForce Approach
class Solution {
    public boolean isSafe(int row, int col, char[][] board,int n){
        int dupCol=col;
        int dupRow=row;

        col--;
        row--;
        while(col>=0 && row>=0) {
            if(board[row][col]=='Q') return false;
            col--;
            row--;
        }

        col=dupCol;
        row=dupRow;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        col=dupCol;
        while(col>=0 && row<n){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        
        return true;
    }
    public void solve(int col, char[][] board, List<List<String>> result, int n){
        if(col==n){
            List<String> temp=new ArrayList<>();
            for(int i=0;i<n;i++){
                temp.add(new String(board[i]));
            }   
            result.add(temp);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,result,n);
                board[row][col]='.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result=new ArrayList<>();
        char[][] board=new char[n][n];

        for(int i=0;i<n;i++){
            Arrays.fill(board[i],'.');
        }

        solve(0,board,result,n);

        return result;
    }
}


// Optimized Approach

class Solution {
    
    public void solve(int col, char[][] board, List<List<String>> result,int[] left,int[] upperDiagonal,
    int[] lowerDiagonal, int n){
        if(col==n){
            List<String> temp=new ArrayList<>();
            for(int i=0;i<n;i++){
                temp.add(new String(board[i]));
            }   
            result.add(temp);
            return;
        }

        for(int row=0;row<n;row++){
            if(left[row] == 0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 + (col-row)]==0){
                board[row][col]='Q';

                left[row] = 1; 
                lowerDiagonal[row+col]=1; 
                upperDiagonal[n-1 + (col-row)]=1;

                solve(col+1,board,result,left,
upperDiagonal,
lowerDiagonal,n);

                left[row] = 0; 
                lowerDiagonal[row+col]=0; 
                upperDiagonal[n-1 + (col-row)]=0;
                board[row][col]='.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result=new ArrayList<>();
        char[][] board=new char[n][n];
        int[] left=new int[n];
        int[] upperDiagonal= new int[2*n-1];
        int[] lowerDiagonal= new int[2*n-1];

        for(int i=0;i<n;i++){
            Arrays.fill(board[i],'.');
        }

        solve(0,board,result,left,
upperDiagonal,
lowerDiagonal,n);

        return result;
    }
}