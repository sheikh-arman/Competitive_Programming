// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
//APPROACH
//**first go to every node and call the dfs if its value is equal to 1;
//dfs will visit the all adjacent nodes and increase the area;
//Atlast put the area equal to max of the ans and area;
//Please note I have passed area as referance.

//Time complexity O(N*M)  since time complexity of dfs(consist of inner for loop and recursion) is O(V+E) in general here it will be O(M+M-1)
//and outer loop will run for N time.
//Space(N*M)
//
void dfs(int i,int j,vector<vector<int>>&vis, vector<vector<int>>& grid,int &ans,int &area){
   //Base case
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()  || grid[i][j]==0 ){
        return ;
    }
    if(vis[i][j]==1)return;
  
    //if node is not visited mark it visit and travel the four adjacent sites
    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()  && grid[i][j]==1 && vis[i][j]==0){
       
        vis[i][j]=1;
       
        area++;
      dfs(i,j+1,vis,grid,ans,area);
      dfs(i-1,j,vis,grid,ans,area);
      dfs(i,j-1,vis,grid,ans,area);
      dfs(i+1,j,vis,grid,ans,area);
        // put ans equal to max of area obtained and ans
        ans=max(area,ans);
    }
    
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    
    
    int ans=0;
   //intialise the vector to store the visited nodes
    vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
    
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
           
            if(vis[i][j]==0  && grid[i][j]==1){
               //call for dfs 
                int area=0;
                dfs(i,j,vis,grid,ans,area);
                
                
                
            }
        }
    }

    return ans;
}
};