// https://leetcode.com/problems/maximum-total-importance-of-roads

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int deg[n+10];
        for(int i=0;i<=n;i++)deg[i]=0;
        int siz=roads.size();
        for(int i=0;i<siz;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            deg[u]++;
            deg[v]++;
        }
        vector<long long>V;
        for(long long i=0;i<n;i++){
            V.push_back((long long)deg[i]);
        }
        sort(V.begin(),V.end());
        long long ans=0;
        for(long long i=1;i<=n;i++){
            ans+=(i*V[i-1]);
            //cout<<ans<<" "<<V[i-1]<<" x\n";
        }
        return ans;
    }
};