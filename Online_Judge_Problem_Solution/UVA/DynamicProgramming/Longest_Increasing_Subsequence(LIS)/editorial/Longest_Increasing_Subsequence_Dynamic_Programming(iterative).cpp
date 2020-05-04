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
 vector<ll>V;
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1;TEST<=tcase;TEST++){
       V.clear();
        ll array_size;
        cin>>array_size;
        for(ll i=0;i<array_size;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        for(ll i=array_size-1;i>=0;i--){
            ll ans=0;
            for(ll j=i+1;j<array_size;j++){
                if(V[j]>V[i]){
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]=ans+1;
        }
        ll ans=0;
        for(ll i=0;i<array_size;i++){
            ans=max(ans,dp[i]);
        }
        cout<<ans<<"\n";
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

