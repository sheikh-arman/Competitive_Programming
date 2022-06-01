/*
    Sk arman Hossain
    University of Barisal
    Problem name : E. Tree Queries
    Algorithm : DFS
 */

#include<bits/stdc++.h>
using namespace std;
#define PB push_back
int label[200010];
int parent[200010];
int starting[200010];
int ending[200010],cnt;
vector<int>V,edj[200010];
void dfs(int node)
{
    starting[node]=cnt++;
    int siz=edj[node].size();
    for(int i=0; i<siz; i++)
    {
        int child=edj[node][i];
        if(label[child]==-1)
        {
            label[child]=label[node]+1;
            parent[child]=node;
            dfs(child);
        }
    }
    ending[node]=cnt++;
}
bool cmp(int a,int b)
{
    if(label[a]<label[b])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    memset(label,-1,sizeof(label));
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        edj[u].PB(v);
        edj[v].PB(u);
    }
    cnt=1;
    label[1]=0;
    parent[1]=1;
    dfs(1);
    for(int i=0; i<k; i++)
    {
        V.clear();
        int a;
        cin>>a;
        for(int j=0; j<a; j++)
        {
            int b;
            cin>>b;
            V.PB(parent[b]);
            ///ll pos=lower_bound(V.begin(),V.end(),label)-V.begin();
        }
        sort(V.begin(),V.end(),cmp);
        bool ans=0;
        for(int j=1; j<a; j++)
        {
            if(starting[V[j-1]]>starting[V[j]]||ending[V[j-1]]<ending[V[j]])
            {
                ans=true;
                break;
            }
        }
        if(ans)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }
    return 0;

    ///******************Alhamdulillah*******************///
}
