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

ll randval(ll _begin, ll _end){
    unsigned seed=chrono::system_clock::now().time_since_epoch().count();
    mt19937_64 generator(seed);
    uniform_int_distribution<ll> distribution(_begin,_end);
    return distribution(generator);
}

int main(){
    freopen("input.txt","w",stdout);
}


















