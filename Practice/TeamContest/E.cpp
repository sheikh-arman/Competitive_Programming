class Solution
{
public:
    vector<int>edj[410];
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions)
    {
        int deg[410];
        int color[410];
        vector<vector<int>>ans;
        for(int i=0; i<k; i++)
        {
            vector<int>tm;
            for(int j=0; j<k; j++)
            {
                tm.push_back(0);
            }
            ans.push_back(tm);
        }
        for(int i=0; i<=k; i++)
        {
            deg[i]=0;
            edj[i].clear();
        }
        int n=rowConditiopns.size();
        for(int i=0; i<n; i++)
        {
            int a,b;
            a=rowConditions[i][0];
            b=rowConditions[i][1];
            edj[a].push_back(b);
            deg[b]++;
        }
        queue<int>pq;
        for(int i=1; i<=k; i++)
        {
            if(deg[i]==0)
            {
                pq.push(i);
            }
        }
        vector<int>V,pos(k+1);
        int cnt=0;
        while(!pq.empty())
        {
            int node=pq.front();
            V.push_back(node);
            pos[node]=cnt++);
            pq.pop();
for(int i:edj[node])
            {
                deg[i]--;
                if(deg[i]==0)
                {
                    pq.push(i);

                }
            }
        }
        int ck=1;
        for(int i=1; i<=k; i++)
        {
            if(deg[i]!=0)
            {
                ck=0;
            }
        }
        if(ck)
        {
            for(int i=0; i<=k; i++)
            {
                deg[i]=0;
                edj[i].clear();
            }
            n=colConditiopns.size();
            for(int i=0; i<n; i++)
            {
                int a,b;
                a=colConditions[i][0];
                b=colConditions[i][1];
                edj[a].push_back(b);
                deg[b]++;
            }
            for(int i=1; i<=k; i++)
            {
                if(deg[i]==0)
                {
                    pq.push(i);
                }
            }
            cnt=0;
            while(!pq.empty())
            {
                int node=pq.front();
                ans[pos[node]][cnt]]=node;
                cnt++;
                pq.pop();
for(int i:edj[node])
                {
                    deg[i]--;
                    if(deg[i]==0)
                    {
                        pq.push(i);
                    }
                }
            }
        }
    }
};
