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
vector<ll>edj[1010];
vector<ll>rev_edj[1010];
set<ll>last_edj[1010];
bitset<1010>node_check,node_check2,color;
stack<ll>stk;
void dfs(ll node)
{
    color[node]=true;
    node_check[node]=1;
    for(ll i:edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            dfs(i);
        }
    }
    stk.push(node);
}
ll rep[1010];
vector<ll>V;
void go(ll node,ll val)
{
    rep[node]=val;
    color[node]=true;
    for(ll i:rev_edj[node])
    {
        if(color[i]==false)
        {
            color[i]=true;
            go(i,val);
        }
    }
}
ll ck;
void checking(ll node)
{
    node=rep[node];
    color[node]=true;
    ll siz=last_edj[node].size();
    if(siz<=1)
    {
        for(ll j:last_edj[node])
        {
            ll ch=rep[j];
            if(color[ch]==false)
            {
                color[ch]=true;
                checking(ch);
            }
        }
    }
    else
    {
        ck=0;
    }
}
int main()
{
   // color.set();cout<<color[2];
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    //fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for(ll i=0; i<=1000; i++)
        {
            edj[i].clear();
            rev_edj[i].clear();
            last_edj[i].clear();
            color[i]=false;
            node_check[i]=0;
            node_check2[i]=0;
        }
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll k;
            cin>>k;
            for(ll j=0; j<k; j++)
            {
                ll u,v;
                cin>>u>>v;
                edj[u].PB(v);
                rev_edj[v].PB(u);
                node_check2[u]=1;
                node_check2[v]=1;
            }
        }
        dfs(0);
        ck=1;
        for(ll i=0; i<1000; i++)
        {
            color[i]=false;
            if(node_check2[i]!=node_check[i])
            {
                ck=0;
                break;
            }
        }
        if(!ck||(ll)edj[0].size()==0)
        {
            cout<<"Case "<<test<<": NO\n";
        }
        else
        {
            set<ll>st;
            while(!stk.empty())
            {
                ll node=stk.top();
                stk.pop();
                if(color[node]==false)
                {
                    go(node,node);
                    st.insert(node);
                }
            }
            for(ll i=0; i<1000; i++)
            {
                if(node_check2[i]==1)
                {
                    ll node=rep[i];
                    for(ll j:edj[i])
                    {
                        ll ch=rep[j];
                        if(node!=ch)
                        {
                            last_edj[node].insert(ch);
                        }
                    }

                }

            }
//            for(ll i=0; i<n; i++)
//            {
//                if(last_edj[i].size()>0)
//                {
//                    cout<<i<<" : ";
//                    for(ll j:last_edj[i])
//                    {
//                        cout<<j<<" ";
//                    }
//                    cout<<"\n";
//                }
//            }
//            for(ll i=0; i<1000; i++)
//            {
//                if((ll)last_edj[rep[i]].size()>1)
//                {
//                    ck=0;
//                }
//            }
            color.reset();
            checking(0);
            for(ll i:st){
                if(color[i]==false){
                    ck=0;
                }
            }
            if(ck)
                cout<<"Case "<<test<<": YES\n";
            else
                cout<<"Case "<<test<<": NO\n";
        }
    }
    return 0;
}



