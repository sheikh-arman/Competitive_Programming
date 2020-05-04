/*
    Sk arman Hossain
    University of Barisal

    Problem : Longest Increasing Subsequence(LIS)
    Solution : Dynamic Programming(Recursive)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define N 2000000
ll dp[N+10];
ll path[N+10];
vector<ll>V;
ll lis(ll pos)
{
    if(dp[pos]!=-1)
    {
        return dp[pos];
    }
    ll ans=0;
    ll siz=V.size();
    for(ll j=pos+1; j<siz; j++)
    {
        if(V[j]>V[pos])
        {
            ll tm=lis(j);
            if(ans<tm)
            {
                ans=tm;
                path[pos]=j;
            }
        }
    }
    return dp[pos]=ans+1;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1; TEST<=tcase; TEST++)
    {
        V.clear();
        ll array_size;
        cin>>array_size;
        for(ll i=0; i<array_size; i++)
        {
            ll a;
            cin>>a;
            V.push_back(a);
            dp[i]=-1;
            path[i]=-1;
        }
        ll ans=0,start_index;
        for(ll i=0; i<array_size; i++)
        {
            ll tm=lis(i);
            if(ans<tm){
                ans=tm;
                start_index=i;
            }
        }
        cout<<"Size of Lis is: "<<ans<<"\nPath :";
        while(start_index!=-1){
            cout<<V[start_index]<<" ";
            start_index=path[start_index];
        }
        cout<<"\n";
    }
    ///************************Alhamdulillah*************//
    return 0;
}
//ref:shafaetsplanet.com
/*
1
7
5 0 9 2 7 3 4
*/

