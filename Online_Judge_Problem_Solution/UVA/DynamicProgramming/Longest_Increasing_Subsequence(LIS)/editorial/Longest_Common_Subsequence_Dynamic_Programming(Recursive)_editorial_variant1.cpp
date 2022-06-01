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
 ll lis(ll pos){
    ll siz=V.size();
    if(pos>=siz){
        return 1;
    }
    if(dp[pos]!=-1){
        return dp[pos];
    }
    ll ans=0,ans2=0;
    ans2=lis(pos+1);
    if(pos+1<siz&&V[pos+1]>V[pos]){
        ans=1+lis(pos+1);
    }
    dp[pos]=max(ans,ans2);
    return dp[pos];
 }
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
            dp[i]=-1;
        }
        ll ans=0;
        //for(ll i=0;i<array_size;i++){
              //  if(dp[i]==-1)
            ans=max(ans,lis(0));
       // }

        cout<<ans<<"\n";
    }
    ///************************Alhamdulillah*************//
    return 0;
 }
 //ref:shafaetsplanet.com
 /*
1
7
5 3 6 2 7 8 9
 */


