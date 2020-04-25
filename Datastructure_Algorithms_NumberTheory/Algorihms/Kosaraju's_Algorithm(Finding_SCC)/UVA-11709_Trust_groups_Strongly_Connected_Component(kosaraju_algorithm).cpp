/*
    Sk arman Hossain
    University of Barisal

    Problem name : UVA-11709_Trust_groups
    Solution : Kosaraju's SCC finding Algorithm
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
    //ios_base::sync_with_stdio(false);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //cin>>tcase;
     ll n,m;
    while(cin>>n>>m&&(n||m))
    {
        for(ll i=0;i<=n;i++){
            color[i]=false;
            edj[i].clear();
            trans_edj[i].clear();
        }
        getchar();
        map<string ,ll>mp;
        for(ll i=1;i<=n;i++){
            string s;
            getline(cin,s);
            mp[s]=i;
        }
        for(ll i=0;i<m;i++){
            string s1,s2;
            getline(cin,s1);
            getline(cin,s2);
            ll tm=mp[s1];
            ll tm2=mp[s2];
            edj[tm].push_back(tm2);
            trans_edj[tm2].push_back(tm);
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
/*
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0
*/
