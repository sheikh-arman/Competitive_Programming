/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;
int main(){
    policy_set st;
    ///insert
    st.insert(2);
    st.insert(3);
    st.insert(3);
    st.insert(3);
    cout<<"Size :"<<st.size()<<"\n";
    cout<<"Smallest number :"<<*st.begin()<<"\n";
    cout<<"bigestest number :"<<*st.rbegin()<<"\n";
    cout<<"Position of 3: "<<st.order_of_key(3)<<"\n";
    cout<<"Value of position 1 is : "<<*st.find_by_order(1)<<"\n";
    ///delete
    st.erase(3);
    if(st.empty()){
        cout<<"YES\n";
    }
    //cout<<"Count : "<<st.count(3)<<"\n";
    st.clear();
    return 0;
}


