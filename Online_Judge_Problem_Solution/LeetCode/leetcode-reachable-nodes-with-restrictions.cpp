// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
public:
    int color[100010];
    vector<int>edj[100010];
    void dfs(int node){
        color[node]=true;
        for(int i:edj[node]){
            if(color[i]==false){
                color[i]=true;
                dfs(i);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(int i=0;i<=n;i++){
            color[i]=false;
            edj[i].clear();
        }
            int siz=edges.size();
            for(int i=0;i<siz;i++){
                int u=edges[i][0];
                int v=edges[i][1];
                edj[u].push_back(v);
                edj[v].push_back(u);
            }
            for(int i:restricted){
                color[i]=true;
            }
            dfs(0);
            int cnt=0;
            for(int i=0;i<n;i++){
                if(color[i]==true)cnt++;
            }
            cnt-=restricted.size();
            return cnt;
        
    }
};