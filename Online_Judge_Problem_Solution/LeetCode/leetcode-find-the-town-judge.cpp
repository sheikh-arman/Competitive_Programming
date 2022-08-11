// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int indegree[n+2];
        int outdegree[n+2];
        for(int i=0;i<=n;i++){
            indegree[i]=0;
            outdegree[i]=0;
        }
        int siz=trust.size();
        for(int i=0;i<siz;i++){
            int u=trust[i][0];
            int v=trust[i][1];
            indegree[v]++;
            outdegree[u]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(outdegree[i]==0&&indegree[i]==n-1){
                ans=i;break;
            }
        }
        return ans;
    }
};