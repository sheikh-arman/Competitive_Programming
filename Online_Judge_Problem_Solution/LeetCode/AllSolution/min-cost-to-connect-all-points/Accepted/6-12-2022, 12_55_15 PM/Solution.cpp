// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {
public:
    int rep[1000010];
    int Find(int node){
        return (node==rep[node]?node:rep[node]=Find(rep[node]));
    }
    bool joint(int u,int v){
        u=Find(u);
        v=Find(v);
        if(u!=v){
            rep[u]=v;
            return 1;
        }
        else{
            return 0;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>>V;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int disx=abs(points[i][0]-points[j][0]);
                int disy=abs(points[i][1]-points[j][1]);
                V.push_back({disx+disy,{i,j}});
            }
        }
        sort(V.begin(),V.end());
        int sum=0;
        n=V.size();
        for(int i=0;i<=n;i++){
            rep[i]=i;
        }
        for(int i=0;i<n;i++){
            if(joint(V[i].second.first,V[i].second.second)){
                sum+=V[i].first;
            }   
        }
        return sum;
    }
};