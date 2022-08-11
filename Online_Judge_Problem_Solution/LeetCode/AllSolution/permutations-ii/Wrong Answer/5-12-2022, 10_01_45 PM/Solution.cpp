// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>V;
        do{
            vector<int>tm;
            for(int i:nums){
                tm.push_back(i);
            }
            V.push_back(tm);
        }
        while(next_permutation(nums.begin(),nums.end()));
        return V;
    }  
};