// https://leetcode.com/problems/max-area-of-island

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