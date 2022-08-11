// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]=1;
        }
        int ma=0,curr=0;
        for(int i:nums){
            if(mp.count(i-1)){
                continue;
            }
            else{
                int cnt=1;
                curr=i+1;
                while(mp.count(curr)){
                    cnt++;
                    curr++;
                }
                ma=max(ma,cnt);
            }
        }
        return ma;
    }
};