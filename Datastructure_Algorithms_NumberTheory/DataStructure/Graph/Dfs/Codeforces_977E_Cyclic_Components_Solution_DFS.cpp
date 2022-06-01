/*
    Sk arman Hossain
    University of Barisal

    Problem : Codeforces 977F
    Solution : DFS
 */
#include<bits/stdc++.h>
#define PB push_back
typedef long long int ll;
using namespace std;
vector<ll>edj[200010];
bitset<200010>color;
ll cnt;
void dfs(ll n){
    if((ll)edj[n].size()!=2){
        cnt=0;
    }
    color[n]=true;
    for(ll i:edj[n]){
        if(color[i]==false){
            color[i]=true;
            dfs(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,e,ans=0;
        cin>>n>>e;
        for(ll i=0;i<e;i++){
            ll u,v;
            cin>>u>>v;
            edj[u].PB(v);
            edj[v].PB(u);
        }
        for(ll i=1;i<=n;i++){
            if(color[i]==false){
                cnt=1;
                dfs(i);
                ans+=cnt;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}
