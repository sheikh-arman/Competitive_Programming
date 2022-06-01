/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : Minimum Spanning Tree(kruskal)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll rep[110];
ll fin(ll n){
    return (rep[n]==n?n:rep[n]=fin(rep[n]));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1in.txt","r",stdin);
    //freopen("2out.txt","w",stdout);
    ll tcase;
    //scanf("%lld",&tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        map<string,ll>mp;
        vector<pair<pair<ll,ll>,ll>>V;
        ll n,cnt=1,ans=0;
        //scanf("%lld",&n);
        cin>>n;
        for(ll i=0;i<=2*n;i++)rep[i]=i;
        for(ll i=0;i<n;i++){
            string s1,s2;
            ll w;
            cin>>s1>>s2>>w;
            if(mp.count(s1)==0){
                mp[s1]=cnt++;
            }
            if(mp.count(s2)==0){
                mp[s2]=cnt++;
            }
            V.push_back({{w,mp[s1]},mp[s2]});
        }
        sort(V.begin(),V.end());
        for(ll i=0;i<n;i++){
            ll u=fin(V[i].first.second);
            ll v=fin(V[i].second);
            if(u!=v){
                ans+=V[i].first.first;
                rep[u]=v;
            }
        }
        set<ll>st;
        for(ll i=1;i<cnt;i++){
            st.insert(fin(i));
        }
        if((ll)st.size()>1){
            cout<<"Case "<<test<<": Impossible"<<endl;
        }
        else
           cout<<"Case "<<test<<": "<<ans<<endl;
    }
    return 0;
}
