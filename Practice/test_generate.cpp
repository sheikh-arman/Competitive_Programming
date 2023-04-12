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
ll ck(string s){
    ll n=s.size();
    for(ll i=1;i<n;i++){
        if(s[i]==s[i-1]&&s[i]!='W')return 0;
    }
    return 1;
}
int main()
{
    map<int,char>mp;
    mp[0]='R'; mp[1]='G';mp[2]='B';mp[3]='W';
    //freopen("1input.txt","r",stdin);
    freopen("1input.txt","w",stdout);
    fast;
    ll tcase=1000;
    //cin>>tcase;
    cout<<tcase<<"\n";
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        while(1){
            s.clear();
            ll pre=-1;
            while(s.size()<100000){
                ll val=(rand()+1919)%4;
                if(val==3){s+=mp[val];}
                else{
                    if(pre!=val){
                        s+=mp[val];
                    }
                }
                pre=val;
            }
            if(ck(s)){
                break;
            }
        }
        cout<<s<<"\n";
    }
    return 0;
 ///*****************************  ALHAMDULILLAH  *****************************/
}





