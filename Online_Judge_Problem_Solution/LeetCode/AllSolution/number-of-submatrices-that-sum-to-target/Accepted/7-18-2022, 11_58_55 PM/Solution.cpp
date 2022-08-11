// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
public:

int subarraySum(vector<int>& nums, int k){ // 560. Subarray Sum Equals K
    int cnt = 0, sum = 0;
    int n = nums.size();
    unordered_map<int, int>mp;
    mp.insert({0, 1});
    for(int i = 0; i < n; i++){
        sum += nums[i];
        int rem_sum = sum - k;
        if(mp.count(rem_sum))
            cnt += mp[rem_sum];
        mp[sum]++;
    }
    return cnt;
}

int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
    int count = 0;
    for(int i = 0; i < mat.size(); i++){
        
        vector<int> temp(mat[0].size(), 0); // temp.size() = size of columns
        
        for(int j = i; j < mat.size(); j++){
            for(int k = 0; k < mat[0].size(); k++){ // go for all columns
                temp[k] += mat[j][k];
            }
            count += subarraySum(temp, target);
        }
        
    }
    return count;
}
};