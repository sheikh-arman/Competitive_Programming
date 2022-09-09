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
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,sum=0;
        cin>>n;
        vector<ll>V,srt;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            //srt.PB(a);
        }
        //VST(srt);
        ll ck=1;
        for(ll i=0; i<n; i++)
        {
            if(V[i]>i+1)
            {
                ck=0;
                break;
            }
        }
        if(ck)
        {
            ll ar[n+2];
            ll un_match=0;
            vector<ll>V2,trac;
            ll tm_n=n;
            while(tm_n>0)
            {
                ll pos=-1;
                ll cnt=V[tm_n-1];
                for(ll i=tm_n-1; i>=0; i--)
                {
                    if(V[i]==1&&cnt<=1)
                    {
                        pos=i;
                        break;
                    }
                    else
                    {
                        cnt=max(cnt-1,V[i]-1);
                    }
                }
                srt.clear();
                if(pos!=-1)
                {
                    for(ll i=pos; i<tm_n; i++)
                    {
                        V2.PB(V[i]);
                        srt.PB(V[i]);
                    }
                }
                ll siz=V2.size();
                cnt=1;
                VST(srt);
                ll left=0,right=siz-1;
                while(left<=right)
                {
                    if(V2[right]<srt[left]){
                        right--;continue;
                    }
                    if(cnt>=V2[right])
                    {
                        trac.PB(V2[right]);
                        right--;
                    }
                    else
                    {
                        trac.PB(srt[left]);
                        left++;
                        cnt++;
                    }
                }
                tm_n-=siz;
                V2.clear();
            }
            for(ll i=0; i<n; i++)
            {
                cout<<trac[i]<<"\n";
            }

        }
        else
        {
            cout<<"-1\n";
        }

    }
    return 0;
}





