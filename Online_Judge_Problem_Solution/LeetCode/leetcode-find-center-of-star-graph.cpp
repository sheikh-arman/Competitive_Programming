// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        int degree[n+2];
        for(int i=0;i<=n;i++){
            degree[i]=0;
        }
        for(int i=0;i<n-1;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            degree[v]++;
            degree[u]++;
            
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(degree[i]==n-1){
                ans=i;break;
            }
        }
        return ans;
    }
};