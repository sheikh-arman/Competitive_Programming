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
ll par[200010];
vector<ll>edj[200010],V;
bitset<200010>color;
bitset<200010>status;
ll cnt_dis=0,ma=0;
void dfs(ll node)
{
    if(status[par[node]]==0)
    {
        status[par[node]]=1;
        cnt_dis++;
        //  cout<<node<<" x\n";
    }
    color[node]=1;
    ma=max(ma,(ll)edj[node].size());
    V.PB((ll)edj[node].size());
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=1;
            dfs(i);
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        ll n;
        cin>>n;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=0;
            status[i]=0;
            par[i]=0;
        }
        for(ll i=2; i<=n; i++)
        {
            ll a;
            cin>>a;
            edj[a].PB(i);
            //edj[i].PB(a);
            par[i]=a;
        }
        cnt_dis=0;
        ma=0;
        dfs(1);
        if(cnt_dis>=ma)
        {
            cout<<cnt_dis<<"\n";
        }
        else
        {
            ll ar[n+5];
            VST(V);
            ll sum=0;
            for(ll i=0; i<n; i++)
            {
                sum+=V[i];
                ar[i]=sum;
            }
            ll left=cnt_dis;
            ll right=ma;
            ll ans=ma;
            while(left<=right)
            {
                ll mid=(left+right)/2;
                if(cnt_dis<mid)
                {
                    ll pos=upper_bound(V.begin(),V.end(),mid)-V.begin();
                    ll bade=0;
                    ll node=n-pos;
                    if(pos>0)
                    {
                        bade=ar[pos-1];
                    }
                    ll need=(ar[n-1]-bade)-(node*mid);
                    ll extra=mid-cnt_dis;
                    if(extra>=need)
                    {
                        ans=mid;
                        right=mid-1;
                    }
                    else
                    {
                        left=mid+1;
                    }
                }
                else
                {
                    left=mid+1;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}





