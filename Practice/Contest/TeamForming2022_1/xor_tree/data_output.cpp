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

ll ar[100010];
vector<ll>edj[100010];
ll xo,ans;
void dfs(ll node,ll tm,ll parent)
{
    tm^=ar[node];
    ans=max(ans,tm^xo);
    for(ll i:edj[node])
    {
        if(parent!=i)
        {
            dfs(i,tm,node);
        }
    }
}
void solve()
{
    ll n;
    cin>>n;
    for(ll i=0;i<=n;i++){
        edj[i].clear();
    }
    xo=0;
    for(ll i=1; i<=n; i++)
    {
        cin>>ar[i];
        xo^=ar[i];
    }
    for(ll i=0; i<n-1; i++)
    {
        ll u,v;
        cin>>u>>v;
        edj[u].PB(v);
        edj[v].PB(u);
    }
    ans=xo;
    dfs(1,0,-1);
    cout<<ans<<"\n";
}



int main ()

{

    //char s[66]="input/input13.txt";

    ll t=10;

    char s1[122] = "C:/AllFile/code/Competitive_Programming/Competitive_Programming/Practice/Contest/TeamForming2022_1/data/input/input31.txt";

    char s2[124] = "C:/AllFile/code/Competitive_Programming/Competitive_Programming/Practice/Contest/TeamForming2022_1/data/output/output31.txt";





    while(t--)
    {

        freopen(s1,"r",stdin);

        freopen(s2,"w",stdout);



        solve();



        fclose(stdin);

        fclose(stdout);

        if(s1[116]=='9')
        {

            s1[115]++;

            s1[116]='0';

        }

        else s1[116]++;



        if(s2[118]=='9')
        {

            s2[117]++;

            s2[118]='0';

        }

        else s2[118]++;

    }



    /*

        precedence : ! * / % + - << >>

        < > <= >= == != & ^ | && ||

        always check the limit and make sure that is correct.

        lcm of first 40 numbers  can be calculated.

        sqrt of 10^9 is 31622.

        always usee 1LL while doing binary operations.

    */



    return (0 - 0 + 1 -  1 * 1);

}


