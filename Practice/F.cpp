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
ll s[4][30];
ll check[30];
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        for(ll j=1; j<=2; j++)
            for(ll i=0; i<=26; i++)
            {
                s[j][i]=0;

            }
        ll n;
        s[1][0]=1;
        s[2][0]=1;

        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll type,k;
            string str;
            cin>>type>>k>>str;
            for(ll j=0; str[j]!='\0'; j++)
            {
                s[type][str[j]-'a']+=k;
            }
            ll ck=0,last=0,last2=0;
            for(ll j=0; j<26; j++)
            {
                if(s[1][j])last++;
            }
            for(ll j=0; j<26; j++)
            {
                if(s[2][j])last2++;
            }
            if(last>1&&last2>1)
            {
                YES;
            }
            else
            {
                if(last==1&&last2==1)
                {
                    ck=0;
                    for(ll j=0; j<26; j++)
                    {
                        if(s[1][j]==s[2][j])continue;
                        if(s[1][j]>0&&s[2][j]>0)
                        {
                            if(s[1][j]<s[2][j])
                            {
                                ck=1;
                                break;
                            }
                            else
                            {
                                ck=0;
                                break;
                            }
                        }
                        else if(s[1][j]>0)
                        {
                            ck=1;
                            break;
                        }
                        else if(s[2][j]>0)
                        {
                            ck=0;
                            break;
                        }
                    }
                    if(ck)
                    {
                        YES;
                    }
                    else
                    {
                        NO;
                    }
                }
                else
                {

                }

            }

        }
    }
    return 0;
}





