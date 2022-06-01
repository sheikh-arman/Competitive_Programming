
/*
    Author : SK Arman Hossain
    University of Barishal
    Problem: EAGLE1 - Eagle and Dogs
    Solution: DFS
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100010
bitset<N>color;
vector<pair<ll,ll> >edj[N];
ll distance1[N],distance2[N],ma,max_node;
void dfs(ll node,ll status)
{
    color[node]=true;
    ll siz=edj[node].size();
    for(ll i=0; i<siz; i++)
    {
        ll child=edj[node][i].first;
        ll weight=edj[node][i].second;
        if(color[child]==false)
        {

            color[child]=true;
            if(status==1)
            {
                distance1[child]=distance1[node]+weight;
                //finding longest node
                if(distance1[child]>ma)
                {
                    ma=distance1[child];
                    max_node=child;
                }
            }
            else if(status==2)
            {
                distance2[child]=distance2[node]+weight;
            }
            dfs(child,status);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1; TEST<=tcase; TEST++)
    {
        ll n,e;
        cin>>n;
        for(ll i=0; i<=n; i++)edj[i].clear(),color[i]=false,distance1[i]=distance2[i]=0;
        for(ll i=0; i<n-1; i++)
        {
            ll a,b,w;
            cin>>a>>b>>w;
            edj[a].push_back({b,w});
            edj[b].push_back({a,w});
        }
        ma=0;
        dfs(1,1);

        for(ll i=1; i<=n; i++)color[i]=false,distance1[i]=0;
        ma=0;
        dfs(max_node,1);

        for(ll i=1; i<=n; i++)color[i]=false;
        dfs(max_node,2);

        cout<<max(distance1[1],distance2[1]);
        for(ll i=2;i<=n;i++){
            cout<<" "<<max(distance1[i],distance2[i]);
        }
        cout<<"\n";
    }
    return 0;
}

