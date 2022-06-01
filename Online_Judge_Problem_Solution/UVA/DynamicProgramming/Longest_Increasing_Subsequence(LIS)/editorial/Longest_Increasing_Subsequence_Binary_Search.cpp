/*
    Sk arman Hossain
    University of Barisal

    Problem : Longest Increasing Subsequence(LIS)
    Solution : Binary Search
 */
 ///Note:we can find size of LIS using binary search .but we can't print LIS path using binary search .
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long int ll ;
 int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tcase=1;
    cin>>tcase;
    for(ll TEST=1;TEST<=tcase;TEST++){
        vector<ll>V;
        ll array_size;
        cin>>array_size;
        for(ll i=0;i<array_size;i++){
            ll a;
            cin>>a;
            ll pos=lower_bound(V.begin(),V.end(),a)-V.begin();
            if(pos==(ll)V.size())
                V.push_back(a);
            else
                V[pos]=a;
        }
        ll ans=V.size();
        ///note: V is not LIS path.
        cout<<ans<<"\n";
    }
    ///************************Alhamdulillah*************//
    return 0;
 }

