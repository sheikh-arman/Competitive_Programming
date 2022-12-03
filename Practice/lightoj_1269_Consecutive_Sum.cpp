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
vector<ll>V_xor;
struct node
{
    int endmark;
    node* next[3];
    node()
    {
        endmark = 0;
        for (int i=0; i<2; i++)
            next[i] = NULL;
    }
}*root;
void insrt(vector<ll> str, int len)
{
    node* curr = root;
    for (int i=0; i<len; i++)
    {
        int id = str[i];
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
}
ll srch_max(vector<ll> str, int len)
{
    node* curr = root;
    vector<ll>V;
    ll ans=0,ck=0;
    for (int i=0; i<len; i++)
    {
        int id = str[i];
        ll val=0;
        if(curr->next[1-id]!=NULL)
        {
            val=1;
            curr = curr->next[1-id];
        }
        else
        {
            val=0;
            curr = curr->next[id];
        }
        if(val==1)ck=1;
        if(ck)
        {
            V.PB(val);
        }
    }
    for(ll i:V)
    {
        ans=(ans*2)+i;
    }
    return ans;
}
ll srch_min(vector<ll> str, int len)
{
    node* curr = root;
    vector<ll>V;
    ll ans=0,ck=0;
    for (int i=0; i<len; i++)
    {
        int id = str[i];
        ll val=0;
        if(curr->next[id]!=NULL)
        {
            val=0;
            curr = curr->next[id];
        }
        else
        {
            val=1;
            curr = curr->next[1-id];
        }
        if(val==1)ck=1;
        if(ck)
        {
            V.PB(val);
        }
    }
    for(ll i:V)
    {
        ans=(ans*2)+i;
    }
    return ans;
}
void del(node* cur)
{
    for (int i=0; i<2; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
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
        root=new node();
        vector<ll>V(33,0);
        insrt(V,V.size());
        ll n;
        cin>>n;
        ll ans=0,mi=LONG_LONG_MAX;
        ll Xor=0;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            Xor^=a;

            V_xor.clear();
            a=Xor;
            while(a)
            {
                V_xor.PB(a%2);
                a/=2;
            }
            while((ll)V_xor.size()<33)
            {
                V_xor.PB(0);
            }
            reverse(V_xor.begin(),V_xor.end());

            ll val_max=srch_max(V_xor,V_xor.size());
            ll val_min=srch_min(V_xor,V_xor.size());
            val_min=min(Xor,val_min);

            ans=max(ans,val_max);
            mi=min(mi,val_min);
            insrt(V_xor,V_xor.size());
        }
        cout<<"Case "<<test<<": "<<ans<<" "<<mi<<"\n";
        del(root);
    }
    return 0;
}





