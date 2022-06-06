
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:

    vector<int> countSmaller(vector<int>& nums) {
        ordered_set st;
        vector<int>ans;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int pos=st.order_of_key(nums[i]);
            ans.push_back(pos);
            st.insert(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
