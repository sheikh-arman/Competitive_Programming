/*
    Sk arman Hossain
    University of Barisal

    Problem : spoj_spoj_ANARC05B-The Double HeLiX_
    Algorithm : DP(itterative)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1,n,m;
    while(cin>>n&&n)
    {
        ll ar1[10020],ar2[10020];
        vector<ll>V,V2;
        ar1[0]=ar2[0]=0;
        V.push_back(-999999);
        V2.push_back(-999999);//for equaling index with ar1,ar2
        for(ll i=1;i<=n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
            ar1[i]=ar1[i-1]+a;
        }
        cin>>m;
        for(ll i=1;i<=m;i++){
            ll a;
            cin>>a;
            V2.push_back(a);
            ar2[i]=ar2[i-1]+a;
        }
        ll ans=0;
        ll preV=n+1,preV2=m+1;
        for(ll i=n;i>=0;i--){
            ll pos=lower_bound(V2.begin(),V2.end(),V[i])-V2.begin();
            if(pos>m){
                continue;
            }
            if(V2[pos]==V[i]){
                ll tm=ar1[preV-1]-ar1[i-1];
                tm=max(tm,ar2[preV2-1]-ar2[pos-1]);
                ans+=tm;
                preV=i;
                preV2=pos;
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
/*
1 1
2 4 7
*/
