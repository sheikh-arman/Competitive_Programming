// https://leetcode.com/problems/max-area-of-island

class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea=0; //take maxArea is 0 initially
        int rows=grid.length;  // no of rows in grid
        int cols=grid[0].length;  // no of cols in grid
        boolean visited[][]=new boolean[rows][cols];  //creating 2d boolean array
        
        for(int row=0;row<rows;row++){    // for loop for horizontal row of array
            for(int col=0;col<cols;col++){  //for loop for cols of array
                if(grid[row][col]==1 && !visited[row][col]){   //if box is 1 and it is non visited
                    int currArea=dfs(grid,visited,row,col,rows,cols);  //then call dfs function and put that in currArea
                    maxArea=Math.max(maxArea,currArea);   //finding maximum of currArea and maxArea
                }
            }
        }
        return maxArea;
    }
    
    private int dfs(int grid[][],boolean visited[][],int row,int col,int rows,int cols){
        if(row<0 || col<0 || row>=rows || col>=cols || visited[row][col] || grid[row][col]==0) 
            return 0;  //base conditions for recursion
        
        visited[row][col]=true;  //if th box is visited return true
        
        int currArea=1;    
        //checking boxes up , down , left and right and adding in currArea
        currArea+=dfs(grid,visited,row-1,col,rows,cols);
        currArea+=dfs(grid,visited,row+1,col,rows,cols);
        currArea+=dfs(grid,visited,row,col+1,rows,cols);
        currArea+=dfs(grid,visited,row,col-1,rows,cols);
        
        return currArea;
    }
}