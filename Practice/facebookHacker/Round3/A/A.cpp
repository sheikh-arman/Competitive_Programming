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
ll ar[1000100][27];
ll ar_first[30],ar_second[30];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        cin>>s;
        ll n=s.size();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<26; j++)
            {
                ar[i][j]=0;
            }
        }
        for(ll i=0; i<n; i++)
        {
            ar[i][s[i]-'a']=1;
            if(i>0)
            {
                for(ll j=0; j<26; j++)
                {
                    ar[i][j]+=ar[i-1][j];
                }
            }
        }
        ll q;
        cin>>q;
        ll ans=0;
        for(ll i=0; i<q; i++)
        {
            ll l,r;
            cin>>l>>r;
            if(l>r)swap(l,r);
            l--;
            r--;
            if(r-l<1)
            {
                ans++;
                continue;
            }
            if((r-l)%2==0)
            {
                ll val=((r-l)+1)/2;
                for(ll j=0; j<26; j++)
                {
                    ar_first[j]=ar[(l+val)-1][j];
                }
                if(l>0)
                {
                    for(ll j=0; j<26; j++)
                    {
                        ar_first[j]-=ar[l-1][j];
                    }
                }
                for(ll j=0; j<26; j++)
                {
                    ar_second[j]=ar[r][j];
                }
                if(r-val>0)
                {
                    for(ll j=0; j<26; j++)
                    {
                        ar_second[j]-=ar[r-val][j];
                    }
                }
                ll ck=0;
                ar_first[s[l+val]-'a']++;
                for(ll j=0; j<26; j++)
                {
                    if(ar_first[j]==ar_second[j])
                    {
                        continue;
                    }
                    else if(abs(ar_first[j]-ar_second[j])==1)
                    {
                        ck++;
                    }
                    else
                    {
                        ck+=10;
                    }
                }
                if(ck==1)
                {
                    ans++;
                }
                else
                {
                    ar_first[s[l+val]-'a']--;
                    ar_second[s[l+val]-'a']++;
                    ck=0;
                    for(ll j=0; j<26; j++)
                    {
                        if(ar_first[j]==ar_second[j])
                        {
                            continue;
                        }
                        else if(abs(ar_first[j]-ar_second[j])==1)
                        {
                            ck++;
                        }
                        else
                        {
                            ck+=10;
                        }
                    }
                    if(ck==1)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";
    }
    return 0;
}





