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
map<string,ll>mp;
map<ll,string>rev_mp;
stack<ll>stk;
vector<ll>edj[20000],trans[200001],group;
bitset<200010>color;
ll n,edge;
void dfs(ll node)
{
    color[node]=1;
    for(ll i:edj[node])
    {
        if(color[i]==0)
        {
            color[i]=1;
            dfs(i);
        }
    }
    stk.push(node);
}
void dfs2(ll node)
{
    group.PB(node);
    color[node]=1;
    for(ll i:trans[node])
    {
        if(color[i]==0)
        {
            color[i]=1;
            dfs2(i);
        }
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    for(ll test=1; ; test++)
    {
        mp.clear();
        rev_mp.clear();
        cin>>n>>edge;
        if(n==0&&edge==0)
        {
            break;
        }
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            trans[i].clear();
            color[i]=0;
        }
        ll cnt=1;
        for(ll i=0; i<edge; i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            ll u,v;
            if(mp.count(s1)==0)
            {
                u=cnt;
                rev_mp[cnt]=s1;
                mp[s1]=cnt++;
            }
            else
            {
                u=mp[s1];
            }
            if(mp.count(s2)==0)
            {
                v=cnt;
                rev_mp[cnt]=s2;
                mp[s2]=cnt++;
            }
            else
            {
                v=mp[s2];
            }
            edj[u].PB(v);
            trans[v].PB(u);
        }
        for(ll i=1; i<=n; i++)
        {
            if(color[i]==0)
            {
                dfs(i);
            }
        }
        if(test>1)
        {
            cout<<"\n";
        }
        cout<<"Calling circles for data set "<<test<<":\n";
        for(ll i=0; i<=n; i++)
        {
            color[i]=0;
        }
        while(!stk.empty())
        {
            ll node=stk.top();
            stk.pop();
            if(color[node]==0)
            {
                group.clear();
                dfs2(node);
                ll ck=0;
                for(ll i:group)
                {
                    if(ck==1)
                    {
                        cout<<", ";
                    }
                    ck=1;
                    cout<<rev_mp[i];
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}




