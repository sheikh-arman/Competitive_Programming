/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_ADACOINS-Ada_and_Coins
    Solution : bitset + prefix sum
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    bitset<100010>bit;
    bit[0]=1;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        bit|=bit<<a;
    }
    ll ar[100010];
    ar[0]=0;
    for(ll i=1;i<=100000;i++){
        ar[i]=ar[i-1]+(bit[i]==true);
    }
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        cout<<ar[b]-ar[a-1]<<"\n";
    }
     ///**************************  ALHAMDULILLAH  *****************************/
}

