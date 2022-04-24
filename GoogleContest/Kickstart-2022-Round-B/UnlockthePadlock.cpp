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
ll mem[410][410][410],n,d;
vector<ll>V;
ll dp(ll left, ll right, ll pos)
{
    if(left<0||right>=n)
    {
        return LONG_LONG_MAX;
    }
    if(left==0&&right==n-1)
    {
        ll value=min(V[pos],d-V[pos]);
        //cout<<value<<" "<<pos<<" x\n";
        return value;
    }
    if(mem[left][right][pos]!=-1)
    {
        return mem[left][right][pos];
    }
    ll res1=LONG_LONG_MAX;
    ll res2=LONG_LONG_MAX;
    if(left-1>=0&&V[left-1]==V[pos])
    {
        return mem[left][right][pos]=dp(left-1,right,pos);
    }
    else if(right+1<n&&V[right+1]==V[pos])
    {
        return mem[left][right][pos]=dp(left,right+1,pos);
    }
    else
    {
        if(left-1>=0)
        {
            ll val=V[pos];
            ll cnt1=abs(val-V[left-1]);
            ll cnt2=0;
            if(val>V[left-1])
            {
                cnt2=d-val;
                cnt2+=V[left-1];
            }
            else
            {
                cnt2=d-V[left-1];
                cnt2+=val;
            }
            res1=min(cnt1,cnt2);
            res1+=dp(left-1,right,left-1);
        }
        if(right+1<n)
        {
            ll val=V[pos];
            ll cnt1=abs(val-V[right+1]);
            ll cnt2=LONG_LONG_MAX;
            if(val>V[right+1])
            {
                cnt2=d-val;
                cnt2+=V[right+1];
            }
            else
            {
                cnt2=d-V[right+1];
                cnt2+=val;
            }
            res2=min(cnt1,cnt2);
            res2+=dp(left,right+1,right+1);
        }
        return mem[left][right][pos]=min(res1,res2);
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n>>d;
        V.clear();
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        ll ans;
        if(n==1)
        {
            ans=min(V[0],d-V[0]);
            cout<<"Case #"<<test<<": "<<ans<<"\n";
            continue;
        }
        ll pre=-1;
        vector<ll>unique_pos;
        for(ll i=0; i<n; i++)
        {
            if(pre!=V[i])
            {
                unique_pos.PB(i);
            }
            pre=V[i];
        }
        ll siz=unique_pos.size();
        ans=LONG_LONG_MAX;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                for(ll k=0; k<=n; k++)
                {
                    mem[i][j][k]=-1;
                }
            }
        }
        for(ll ii=0; ii<siz; ii++)
        {
            ll left=unique_pos[ii];
            ll right=unique_pos[ii];
            ll val=dp(left,right,left);
            ans=min(val,ans);
            //cout<<left<<" "<<val<<" "<<ans<<" x\n";
        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";

    }
    return 0;
}





