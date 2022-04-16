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
ll mem[210][20010],n,sum,ck,ferry,port,mi;
ll nxt[210][20010];
vector<ll>car;
ll dp(ll pos, ll val, ll siz)
{
    if(pos>=siz)
    {
        //cout<<sum<<" "<<val<<" x\n";
        ll another_cost=sum-val;
        ll res=abs(another_cost-val);
        //cout<<another_cost<<" "<<val<<" "<<sum<<" "<<ferry<<" hi\n";
        if(another_cost<=ferry&&val<=ferry)
        {
            // cout<<another_cost<<" "<<val<<" "<<sum<<" hi\n";
            ck=1;
            if(mi>res)
            {
                mi=res;
                port=val;
            }
        }
        return res;
    }
    if(mem[pos][val]!=-1)
    {
        return mem[pos][val];
    }
    ll cost=dp(pos+1,val,siz);
    ll cost2=dp(pos+1,val+car[pos],siz);
    return mem[pos][val]=min(cost,cost2);
}
ll dp_result(ll pos, ll val,ll siz)
{
    if(pos>=siz)
    {
        //cout<<val<<" hi\n";
        if(val==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(mem[pos][val]!=-1)
    {
        return mem[pos][val];
    }
    ll with_current=0;
    if(val-car[pos]>=0)
    {
        with_current=dp_result(pos+1,val-car[pos],siz);
    }
    ll without_current=dp_result(pos+1,val,siz);
    if(with_current==1)
    {
        nxt[pos][val]=pos;
    }
    else
    {
        nxt[pos][val]=pos+1;
    }
    return mem[pos][val]=(without_current|with_current);

}

int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    // fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        car.clear();
        ll a;
        sum=0;
        cin>>ferry;
        ferry*=100;
        ll validity=1;
        while(1)
        {
            cin>>a;
            if(a==0)break;
            if(sum+a>ferry*2)
            {
                validity=0;
            }
            if(validity)
            {
                sum+=a;
                car.PB(a);
            }
        }
        n=car.size();
        ll ans=n;
        for(ll i=n; i>=1; i--)
        {
            ck=0;
            mi=LONG_MAX;
            for(ll k=0; k<=n; k++)
            {
                for(ll j=0; j<=ferry; j++)
                {
                    mem[k][j]=-1;
                    nxt[k][j]=-1;
                }
            }
            ll mi=dp(0,0,i);
            if(ck)
            {
                ans=i;
                break;
            }
            sum-=car[i-1];
        }
        if(test>1)
        {
            cout<<"\n";
        }
        if(n==0||car[0]>ferry)
        {
            cout<<"0\n";
            continue;
        }
        cout<<ans<<"\n";
        for(ll k=0; k<=ans; k++)
        {
            for(ll j=0; j<=ferry; j++)
            {
                mem[k][j]=-1;
                nxt[k][j]=-1;
            }
        }
        ll nothing=dp_result(0,port,ans);
        ll index=0;
        ll path[ans+2];
        for(ll i=0; i<ans; i++)
        {
            path[i]=0;
        }
        while(index<ans)
        {
            if(index==nxt[index][port])
            {
                path[index]=1;
                port-=car[index];
                index++;
            }
            else
            {
                index++;
            }
        }
        for(ll i=0; i<ans; i++)
        {
            if(path[i]==0)
            {
                cout<<"port\n";
            }
            else
            {
                cout<<"starboard\n";
            }
        }
    }
    return 0;
}
