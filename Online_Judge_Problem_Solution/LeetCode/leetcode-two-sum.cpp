// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int siz=nums.size();
        vector<int>V;
        for(int i=0;i<siz;i++){
            if(mp.count(target-nums[i])!=0){
                
                V.push_back(mp[target-nums[i]]);
                V.push_back(i);break;
            }
            mp[nums[i]]=i;
        }
        return V;
    }
    
};