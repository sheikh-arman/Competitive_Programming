#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N];
int parent[N];
int siz[N];
void make(int v)
{
    parent[v]=v;
    siz[v]=1;
}
int find(int v)
{
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    parent[b]=a;
    siz[a]+=siz[b];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int l=t;
    while(t--)
    {
        int n,k;
        cin>>n;
        map<int,int>m;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            make(i);
            m[a[i]]=i;
        }
        cin>>k;
        while(k--)
        {
            int x,u,v,i;
            cin>>x>>u;
            if(x==1)
            {
                cin>>v;
                if(a[u]==a[v] || a[u]==0 ||a[v]==0) continue;
                if(a[u]>a[v])
                {
                    Union(u,v);
                    a[u]+=a[v];
                    a[v]=0;
                }
                else if(a[u]<a[v])
                {
                    Union(v,u);
                    a[v]+=a[u];
                    a[u]=0;
                }
                //cout<<u<<" "<<parent[u]<<" "<<v<<" "<<parent[v]<<endl;
            }
            else if(x==2)
            {
                if(u==find(u)) cout<<siz[u]<<"\n";
                else cout<<"0\n";
            }
            else cout<<find(u)<<"\n";
        }
    }
    return 0;
}
