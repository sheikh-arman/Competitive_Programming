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
ll ar1[300];
ll ar2[300];
int main()
{
    string s1="SELISE";
    string s2="Digital Platforms";
    
   // cout<<"hjg\n";
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    cin.ignore();
    for(ll test=1; test<=tcase; test++)
    {
        string s1="SELISE";
        string s2="SELISE Digital Platforms";
        for(ll i=0;i<290;i++){
            ar1[i]=0;
            ar2[i]=0;
        }
        for(ll i=0;s1[i]!='\0';i++){
            ar1[(int)s1[i]]++;
        }
        for(ll i=0;s2[i]!='\0';i++){
            ar2[(int)s2[i]]++;
        }
        ll n,sum=0;
        string s;
        getline(cin,s);
        ll ck1=1;
        ll ck2=1;
        for(ll i=0;s[i]!='\0';i++){
            ar1[(int)s[i]]--;
            ar2[(int)s[i]]--;
        }
        for(ll i=0;i<290;i++){
            if(ar1[i]>0){
                ck1=0;
            }
            if(ar2[i]>0){
                ck2=0;
            }
        }
        cout<<"Case "<<test<<": ";
        if(ck1&&ck2){
            cout<<"BOTH\n";
        }
        else if(ck1){
            cout<<"SELISE\n";
        }
        else if(ck2){
            cout<<"SELISE Digital Platforms\n";
        }
        else{
            cout<<"NONE\n";
        }
    }
    return 0;
}





