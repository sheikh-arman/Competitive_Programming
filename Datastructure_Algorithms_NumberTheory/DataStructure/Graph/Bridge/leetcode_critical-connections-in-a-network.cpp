class Solution {
public:
    vector<vector<int>>ans;
    vector<int>edj[100010];
    int start[100010],en[1000010],cnt;
    bitset<100010>color;
    void dfs(int node,int parent){
        start[node]=en[node]=cnt++;
        color[node]=true;
        for(int i:edj[node]){
            if(color[i]==false){
                color[i]=true;
                dfs(i,node);
                en[node]=min(en[i],en[node]);
                if(en[i]>start[node]){
                    vector<int>tm;
                    tm.push_back(node);
                    tm.push_back(i);
                    ans.push_back(tm);
                }

            }
            else if(i!=parent){
                en[node]=min(start[i],en[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        color.reset();
        int siz=connections.size();
        for(int i=0;i<siz;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            edj[u].push_back(v);
            edj[v].push_back(u);
        }
        cnt=1;
        dfs(0,-1);
        return ans;
    }
};
