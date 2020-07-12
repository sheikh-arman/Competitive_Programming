/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : Bridge (DFS)
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
vector<ll>edj[100010];
vector<pair<ll,ll>>V;
bitset<100010>color;
ll start[100010],en[100010];
ll cnt;
void bridge(ll node,ll parent){
    color[node]=true;
    start[node]=cnt;
    en[node]=cnt++;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            bridge(i,node);
            start[node]=min(start[node],start[i]);
            if(en[node]<start[i]){
                    ll a=node,b=i;
            if(a>b)swap(a,b);
                V.push_back({a,b});
            }
        }
        else{
            if(parent!=i)
            start[node]=min(start[node],en[i]);
        }
    }
}
int main()
{
    ll tcase=1;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n;cnt=1;
        scanf("%lld",&n);
        for(ll i=0;i<=n;i++){
            edj[i].clear();
            color[i]=false;
        }
        V.clear();
        for(ll i=0;i<n;i++){
            ll u,x;
            scanf("%lld (%lld)",&u,&x);
            for(ll j=0;j<x;j++){
                ll v;
                scanf("%lld",&v);
                edj[u].push_back(v);
                edj[v].push_back(u);
            }
        }
        for(ll i=1;i<=n;i++){
            if(color[i]==false){
                bridge(i,-1);
            }
        }
        printf("Case %lld:\n",test);
        ll siz=V.size();
        sort(V.begin(),V.end());
        printf("%lld critical links\n",siz);
        for(ll i=0;i<siz;i++){
            printf("%lld - %lld\n",V[i].first,V[i].second);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}

