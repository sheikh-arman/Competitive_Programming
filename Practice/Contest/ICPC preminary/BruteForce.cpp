#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FasrIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 1000000000000000000

template<typename T>
using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using min_heap=priority_queue<ll,vector<ll>,greater<ll>>;

vector<ll> maincode_res;
void getOutput(ll t){
    freopen("output.txt","r",stdin);
    string Case,Case_no;
    ll ans;
    for(ll i=0;i<t;i++){
        cin>>Case>>Case_no>>ans;
        maincode_res.pb(ans);
    }
    fclose(stdin);
}

bool chk_equality(ll i, ll val){
    if(val==maincode_res[i]) return 0;
    else return 1;
}

void bruteforce(){
    //Code starts here.
    ll test_case_no=0,ans=0;

    if(chk_equality(test_case_no,ans)){
        //Wrong answer. So, print test case.
    }
}

int main(){
    getOutput(0);
    freopen("input.txt","r",stdin);
    bruteforce();
}


















