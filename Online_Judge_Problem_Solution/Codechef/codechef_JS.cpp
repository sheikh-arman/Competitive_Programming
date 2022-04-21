#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

ll pre_odd[10010];
ll pre_even[10010];
ll sup_odd[10010];
ll sup_even[10010];
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
        vector<ll>V,odd,even,cumulative,pos,status;
        ll pre=-1,cnt=1;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            a%=2;
            V.PB(a%2);
            if(a==0)
            {
                even.PB(i);
            }
            else
            {
                odd.PB(i);
            }
            if(a!=pre)
            {
                if(i!=0)
                {
                    cumulative.PB(cnt);
                    status.PB(pre);
                    pos.PB(i-1);
                }
                pre=a;
                cnt=1;
            }
            else
            {
                cnt++;
            }
        }

        if(n==2)
        {
            cout<<"1\n";
            continue;
        }
        for(ll i=0; i<n; i++)
        {
            pre_odd[i]=0;
            pre_even[i]=0;
            if(V[i]==0)
            {
                pre_even[i]+=1;
            }
            else
            {
                pre_odd[i]+=1;
            }
            if(i>0)
            {
                pre_odd[i]+=pre_odd[i-1];
                pre_even[i]+=pre_even[i-1];
            }
        }
        for(ll i=n-1; i>=0; i--)
        {
            sup_odd[i]=0;
            sup_even[i]=0;
            if(V[i]==0)
            {
                sup_even[i]+=1;
            }
            else
            {
                sup_odd[i]+=1;
            }
            if(i<n-1)
            {
                sup_odd[i]+=sup_odd[i+1];
                sup_even[i]+=sup_even[i+1];
            }

        }
//        for(ll i=0; i<n; i++)
//        {
//            cout<<pre_even[i]<<" "<<pre_odd[i]<<" "<<sup_even[i]<<" "<<sup_odd[i]<<" x\n";
//        }
        ll ans=LONG_LONG_MAX;
        if(V[0]==V[n-1])
        {
            if(V[0]==0)
            {
                ans=even.size();
            }
            else
            {
                ans=odd.size();
            }
            ans-=1;
            cout<<ans<<"\n";
            continue;
        }
        else
        {
            ll val=V[0];
            ll siz=cumulative.size();
            for(ll i=0; i<siz; i++)
            {
               // cout<<cumulative[i]<<" "<<status[i]<<" "<<pos[i]<<" v\n";
                if(status[i]==val)
                {
                    ll pos1=0;
                    ll pos2=0;
                    if(val==0)
                    {
                        pos1=pre_even[pos[i]]-cumulative[i];

                        pos2=sup_odd[pos[i]];
                    }
                    else
                    {
                        pos1=pre_odd[pos[i]]-cumulative[i];

                        pos2=sup_even[pos[i]];
                    }
                    ll res=pos1+pos2;
                    ans=min(ans,res);

                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}





