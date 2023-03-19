/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
    Date:
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define sf(n) scanf("%lld",&n);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define nl cout<<"\n";
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
#define T(n) printf("test : %d\n",n);
ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};
ll knx[]= {2,2,1,-1,-2,-2,1,-1};
ll kny[]= {1,-1,2,2,1,-1,-2,-2};
ll in_deg[30];
ll out_deg[30];
vector<pair<ll,string>>edj[30];
ll ans=0,n;
vector<string>res;
void dfs(ll node){
    for(auto i:edj[node]){
        ll u=i.first;
        cout<<node<<" "<<u<<" "<<in_deg[u]<<" "<<out_deg[u]<<" x\n";
        if(in_deg[u]>0&&out_deg[u]>0&&out_deg[u]>=in_deg[u]){
            ans++;
            res.PB(i.second);
            in_deg[u]--;
            out_deg[node]--;
            if(out_deg[u]>0){
                dfs(u);
            }
            break;
        }
        else if(in_deg[u]>out_deg[u]){
            if(ans==n-1){
                ans++;
                res.PB(i.second);
                in_deg[u]--;
                out_deg[node]--;
            }
            else{
                ans++;
                res.PB(i.second);
                in_deg[u]--;
                out_deg[node]--;
                dfs(u);break;
            }
        }
    }
}
int main()
{
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n;
        ll start;
        for(ll i=0;i<=26;i++){
            in_deg[i]=0;
            out_deg[i]=0;
            edj[i].clear();
        }
        vector<string>V;
        for(ll i=0;i<n;i++){
            string s;
            cin>>s;
            ll siz=s.size();
            out_deg[s[0]-'a']++;
            in_deg[s[siz-1]-'a']++;
            start=s[0]-'a';
            edj[s[0]-'a'].PB({s[siz-1]-'a',s});
        }
        cout<<"Case "<<test<<": ";
        ll cnt=0;
        ans=0;
        for(ll i=0;i<26;i++){
            if(out_deg[i]>in_deg[i]){
                   start=i;break;
            }
        }
        res.clear();
        dfs(start);
        cout<<res.size()<<" x\n";
        if(res.size()==n){
            cout<<"Yes\n";
            for(ll i=0;i<n;i++){
                if(i>0)cout<<" ";
                    cout<<res[i];
            }
            cout<<"\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
 ///*****************************  ALHAMDULILLAH  *****************************/
}





