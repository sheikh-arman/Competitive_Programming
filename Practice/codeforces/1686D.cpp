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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

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
int main()
{
    freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll cnta=0,cntb=0;
        string s;
        cin>>s;
        for(ll i=0; s[i]!='\0'; i++)
        {
            if(s[i]=='A')cnta++;
            else cntb++;
        }
        if(a+c+d!=cnta||b+c+d!=cntb)
        {
            NO;
            continue;
        }
        string tm_s=s;
        ll tm_c=c,tm_d=d;
        ll n=s.size();
        ll cnt=0;
        vector<pair<ll,ll>>V;
        for(ll i=0; i<n-1; i++)
        {
            if(tm_s[i]=='A'&&tm_s[i+1]=='B')
            {

                cnt+=2;
            }
            else
            {
                if(cnt>0)
                {
                    V.PB({cnt,i-1});
                }
                cnt=0;
            }
        }
        if(cnt)
        {
            V.PB({cnt,n-1});
        }
        ll siz=V.size();
        for(ll i=0; i<siz&&tm_c; i++)
        {
            ll pos=V[i].second;
            ll cn=V[i].first;
            for(ll j=pos; cn>0&&tm_c; j-=2)
            {
                tm_s[j]='#';
                cn-=2;
                tm_c-=1;
            }
        }
        for(ll i=0; i<n-1&&tm_d; i++)
        {
            if(tm_s[i]=='B'&&tm_s[i+1]=='A')
            {
                i++;
                tm_d--;
            }
        }
        if(tm_d||tm_c)
        {
            tm_s=s;
            tm_c=c;
            tm_d=d;
            V.clear();
            cnt=0;
            for(ll i=0; i<n-1; i++)
            {
                if(tm_s[i]=='B'&&tm_s[i+1]=='A')
                {

                    cnt+=2;
                }
                else
                {
                    if(cnt>0)
                    {
                        V.PB({cnt,i-1});
                    }
                    cnt=0;
                }
            }
            if(cnt)
            {
                V.PB({cnt,n-1});
            }
            siz=V.size();
            for(ll i=0; i<siz&&tm_d; i++)
            {
                ll pos=V[i].second;
                ll cn=V[i].first;
                for(ll j=pos; cn>0&&tm_d; j-=2)
                {
                    tm_s[j]='#';
                    cn-=2;
                    tm_d-=1;
                }
            }
            for(ll i=0; i<n-1&&tm_c; i++)
            {
                if(tm_s[i]=='A'&&tm_s[i+1]=='B')
                {
                    i++;
                    tm_c--;
                }
            }
            if(tm_d||tm_c)
            {
                NO;
            }
            else
            {
                YES;
            }
        }
        else
        {
            YES;
        }



    }
    return 0;
}





