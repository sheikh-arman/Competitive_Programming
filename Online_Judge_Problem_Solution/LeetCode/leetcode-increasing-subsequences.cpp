// https://leetcode.com/problems/increasing-subsequences

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        for(int i=3;i<(1<<n);i++){
            int num=i;
            vector<int>V;
            int cnt=0;
            while(num){
                if(num%2){
                    V.push_back(nums[cnt]);
                }
                num/=2;cnt++;
            }
            int siz=V.size();
            if((int)V.size()>1){
                int ck=1;
                for(int i=1;i<siz;i++){
                    if(V[i-1]>V[i]){
                        ck=0;break;
                    }
                }
                if(ck){
                    st.insert(V);
                }
            } 
        }
        vector<vector<int>>ans;
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};