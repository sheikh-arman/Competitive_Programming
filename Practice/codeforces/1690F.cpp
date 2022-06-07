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
bitset<260>color;
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<=n+10; i++)
        {
            color[i]=false;
        }
        string s;
        cin>>s;
        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            a--;
            V.PB(a);
        }
        vector<ll>ans;
        for(ll i=0; i<n; i++)
        {
            if(color[i]==false)
            {
                color[i]=true;
                ll tm=V[i];
                string str;
                str+=s[i];
                while(color[tm]==false)
                {
                    color[tm]=true;
                    str+=s[tm];
                    tm=V[tm];
                }
                ll siz=str.size();
                reverse(str.begin(),str.end());
                string tm_s=str;
                ll cnt=0;
                while(cnt<siz)
                {
                    tm_s+=tm_s[0];
                    tm_s.erase(tm_s.begin());
                    cnt++;
                    if(tm_s==str)
                    {
                        break;
                    }
                }
                if(cnt>1)
                {
                    ans.PB(cnt);
                }
            }
        }
        if((ll)ans.size()==0)
        {
            cout<<"1\n";
        }
        else
        {
            ll si=ans.size();
            if(si==1)
            {
                cout<<ans[0]<<"\n";
            }
            else
            {
                VST(ans);
                ll gcd=ans[0];
                for(ll i=0; i<si; i++)
                {
                    gcd=__gcd((ll)min(ans[i],gcd),(ll)max(ans[i],gcd));
                }
                for(ll i=0; i<si; i++)
                {
                    ans[i]/=gcd;
                }
                unsigned long long res=gcd;
                for(ll i=0; i<si; i++)
                {
                    res*=(unsigned long long int)ans[i];
                }
                cout<<res<<"\n";
            }
        }
    }
    return 0;
}




