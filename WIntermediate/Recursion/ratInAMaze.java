// Online Java Compiler
// Use this editor to write, compile and run your Java code online
// Better Approach - Not Professional - Don't use in interview
import java.util.*;
class Solution{
    public void findPath(int row,int col,String path,int[][] maze,List<String> result,int[][] visited,int n){
        if(row==n-1 && col==n-1){
            result.add(path);
            return;
        }
        
        if(row+1<n && visited[row+1][col]==0 && maze[row+1][col]==1){
            visited[row][col]=1;
            findPath(row+1,col,path+'D',maze,result,visited,n);
            visited[row][col]=0;
        }
        
        if(col-1>=0 && visited[row][col-1]==0 && maze[row][col-1]==1){
            visited[row][col]=1;
            findPath(row,col-1,path+'L',maze,result,visited,n);
            visited[row][col]=0;
        }
        
        if(col+1<n && visited[row][col+1]==0 && maze[row][col+1]==1){
            visited[row][col]=1;
            findPath(row,col+1,path+'R',maze,result,visited,n);
            visited[row][col]=0;
        }
        
        if(row-1>=0 && visited[row-1][col]==0 && maze[row-1][col]==1){
            visited[row][col]=1;
            findPath(row-1,col,path+'U',maze,result,visited,n);
            visited[row][col]=0;
        }
        
    }
}
class Main {
    public static void main(String[] args) {
        System.out.println("Try programiz.pro");
        int[][] maze = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}
        };
        int n = maze.length;
        List<String> result=new ArrayList<>();
        String path="";
        int[][] visited=new int[n][n];
        Solution obj=new Solution();
        if(maze[0][0]==1)  obj.findPath(0,0,path,maze,result,visited,n);
        else return;
        
        System.out.println(result);
    }
}




// Optimized Approach
// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
class Solution{
    public boolean isSafe(int i, int[][] visited, int[][] maze, int nRows, int nCols,int n){
        return nCols>=0 && nCols<n && nRows>=0 && nRows<n &&  visited[nRows][nCols]==0 && maze[nRows][nCols]==1;
    }
    public void findPath(int row,int col,String path,int[][] maze,List<String> result,int[][] visited,int[] rows,int[] cols,int n){
        if(row==n-1 && col==n-1){
            result.add(path);
            return;
        }
        String[] directions={"D","L","R","U"};
        for(int i=0;i<n;i++){
            int nCols=col+cols[i];
            int nRows=row+rows[i];
            if(isSafe(i, visited, maze, nRows, nCols,n)){
                
                visited[row][col]=1;
                findPath(nRows,nCols,path+directions[i],maze,result,visited,rows,cols,n);
                visited[row][col]=0;
            }
        }
        
    }
}
class Main {
    public static void main(String[] args) {
        System.out.println("Try programiz.pro");
        int[][] maze = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}
        };
        int n = maze.length;
        List<String> result=new ArrayList<>();
        String path="";
        int[][] visited=new int[n][n];
        int [] rows={1,0,0,-1};
        int [] cols={0,-1,1,0};
        Solution obj=new Solution();
        if(maze[0][0]==1)  obj.findPath(0,0,path,maze,result,visited,rows,cols,n);
        else return;
        
        System.out.println(result);
    }
}