// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
   vector<vector<int>>V;
    int n;
    void rec(int node,vector<int> path,vector<vector<int>>& graph){
        if(node==n-1){
            path.push_back(node);
            V.push_back(path);
            return;
        }
        path.push_back(node);
        for(int i:graph[node]){
            rec(i,path,graph);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int>v;
        rec(0,v,graph);
        return V;
    }
};