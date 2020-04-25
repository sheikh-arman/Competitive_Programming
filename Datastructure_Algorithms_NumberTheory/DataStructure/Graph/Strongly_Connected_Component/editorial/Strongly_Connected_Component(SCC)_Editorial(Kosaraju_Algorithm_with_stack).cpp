/*
    Sk arman Hossain
    University of Barisal

    Problem name : spoj_CLFLARR_Colorful_Array
    Solution : segment tree
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 200010
vector<ll>edj[N+10],trans_edj[N+10];
stack<ll>st;
bitset<N+10>color;
void dfs(ll node){

    color[node]=true;
    for(ll i:edj[node]){
        if(color[i]==false){
            color[i]=true;
            dfs(i);
        }
    }
    st.push(node);
}
void dfs2(ll node){
    color[node]=true;
    for(ll i:trans_edj[node]){
        if(color[i]==false){
            color[i]=true;
            dfs2(i);
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            color[i]=false;
            edj[i].clear();
            trans_edj[i].clear();
        }
        //st.clear();
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            edj[u].push_back(v);
            trans_edj[v].push_back(u);
        }
        for(ll i=1;i<=n;i++){
            if(color[i]==false){
                dfs(i);
            }
        }
        for(ll i=0;i<=n;i++)color[i]=false;
        ll ans=0;
        while(!st.empty()){
            ll tm=st.top();
            st.pop();
            if(color[tm]==false){
                dfs2(tm);
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
