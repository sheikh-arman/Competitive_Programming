// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        int cnt=1;
        do{
            if(cnt>=k){
                break;
            }
            cnt++;
        }
        while(next_permutation(nums.begin(),nums.end()));
        string s;
        for(int i=0;i<n;i++){
            s+=(nums[i]+'0');
        }
        return s;
    }
};