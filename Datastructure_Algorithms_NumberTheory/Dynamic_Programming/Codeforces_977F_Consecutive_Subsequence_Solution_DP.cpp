/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define PB push_back
typedef long long int ll;
using namespace std;
map<ll,ll>mp;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,a,mx=0,pos,val;
        cin>>n;
        vector<ll>V,ans;
        for(ll i=0; i<n; i++)
        {
            cin>>a;
            V.PB(a);
            ll tm;
            tm=mp[a]=max(mp[a],mp[a-1]+1);
            if(tm>mx)
            {
                mx=tm;
                val=a;
            }
        }
        cout<<mx<<"\n";

        for(ll i=n-1;i>=0;i--){
            if(V[i]==val){
                ans.PB(i+1);val--;
            }
        }
        for(ll i=mx-1; i>=0; i--)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
test
 8
 3 4 5 6 7 1 2 3
 ans
 5
 1 2 3 4 5

*/
