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
ll ar[12];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll sum=0,ma=0,ma_val=-1;
        for(ll i=0; i<10; i++)
        {
            cin>>ar[i];
            sum+=ar[i];
            if(ar[i]>=ma)
            {
                ma=ar[i];
                ma_val=i;
            }
        }
        ll baki=(sum-ma);
        if(ma>baki+1)
        {
            cout<<"-1\n";
            continue;
        }
        if(ma_val==0)
        {
            if(sum==1)
            {
                cout<<"0\n";
                continue;
            }
            if(ma>baki)
            {
                cout<<"-1\n";
                continue;
            }
        }
        string s;
        ll ck=1;
        ll first=1,pre=-1;
        ll cnt=0;
        while(cnt<sum+100)
        {
            cnt++;
            if((ll)s.size()==sum)
            {
                break;
            }
            for(ll i=0+first; i<10; i++)
            {
                ll total=0,val=-1;
                ma=0;
                if(ar[i]>0&&i!=pre)
                {
                    for(ll j=0; j<10; j++)
                    {

                        if(i!=j)
                        {
                            total+=ar[j];
                            if(ma<=ar[j])
                            {
                                ma=ar[j];
                                val=j;
                            }
                        }
                        else
                        {
                            total+=(ar[j]-1);
                            if(ma<ar[j]-1)
                            {
                                ma=ar[j]-1;
                                val=j;
                            }
                        }
                    }
                    ll baki=total-ma;
                    if(val==i)
                    {
                        if(baki>=ma)
                        {
                            s+=(i+'0');
                            pre=i;
                            first=0;
                            ar[i]--;
                            break;
                        }
                    }
                    else
                    {
                        if(baki>=ma-1)
                        {
                            s+=(i+'0');
                            pre=i;
                            first=0;
                            ar[i]--;
                            break;
                        }
                    }
                }
                //cout<<s<<" "<<i<<" x\n";
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}




