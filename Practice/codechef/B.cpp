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
ll mat_fixed[10][10];
ll mat[10][10];

ll ans[10][10];
ll x,y;

void cal(ll a,ll b)
{
    for(ll k=0; k<8; k++)
    {
        ll i=a,j=b;
        while(i>0&&i<9&&j>0&&j<9)
        {
            mat_fixed[i][j]=1;
            i+=dx[k];
            j+=dy[k];
        }
    }
}
void cal2(ll a,ll b)
{
    for(ll k=0; k<8; k++)
    {
        ll i=a,j=b;
        while(i>0&&i<9&&j>0&&j<9)
        {
            mat[i][j]=2;
            i+=dx[k];
            j+=dy[k];
        }
    }
}
ll ck()
{
    for(ll k=0; k<8; k++)
    {
        ll i=x,j=y;
        i+=dx[k];
        j+=dy[k];
        if(i>0&&i<9&&j>0&&j<9)
        {
            if(mat[i][j]!=2)
            {
                return 0;
            }
        }
    }
    return 1;
}
void clr()
{
    for(ll i=1; i<=8; i++)
    {
        for(ll j=1; j<=8; j++)
        {
            mat[i][j]=0;
        }
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
        cin>>x>>y;
        for(ll i=1; i<=8; i++)
        {
            for(ll j=1; j<=8; j++)
            {
                mat[i][j]=0;
                mat_fixed[i][j]=0;
                ans[i][j]=0;
            }
        }
        mat[x][y]=1;
        mat_fixed[x][y]=1;
        ans[x][y]=1;
        cal(x,y);
        ll res=1;
        for(ll i=1; i<=8&&res; i++)
        {
            for(ll j=1; j<=8&&res; j++)
            {
                if(mat_fixed[i][j]!=1)
                {
                    clr();
                    mat[i][j]=2;
                    cal2(i,j);
                    if(ck())
                    {
                        res=0;
                        ans[i][j]=2;
                    }
                }
            }
        }
//        cout<<res<<" t\n";
//        for(ll i=1;i<=8;i++){
//            for(ll j=1;j<=8;j++){
//                cout<<mat[i][j]<<" ";
//            }
//            cout<<" x\n";
//        }
        if(res)
        {
            for(ll i=1; i<=8&&res; i++)
            {
                for(ll j=1; j<=8&&res; j++)
                {

                    if(mat_fixed[i][j]!=1)
                    {
                        mat[i][j]=2;
                        //cal2(i,j);
                        for(ll k=1; k<=8&&res; k++)
                        {
                            for(ll f=1; f<=8&&res; f++)
                            {
                                if(mat_fixed[k][f]!=1)
                                {
                                    clr();
                                    mat[i][j]=2;
                                    cal2(i,j);

                                    mat[k][f]=2;
                                    cal2(k,f);
                                    if(ck())
                                    {
                                        res=0;
                                        ans[i][j]=2;
                                        ans[k][f]=2;
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
        for(ll i=1; i<=8; i++)
        {
            for(ll j=1; j<=8; j++)
            {
                if(j>1)cout<<" ";
                cout<<ans[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}





