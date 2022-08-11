// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>mp;
        for(int i:nums){
            mp.insert(i);
        }
        int ma=0,curr=0;
        for(int i:nums){
            if(mp.find(i-1)!=mp.end()){
                continue;
            }
            else{
                int cnt=1;
                curr=i+1;
                while(mp.find(curr)!=mp.end()){
                    cnt++;
                    curr++;
                }
                ma=max(ma,cnt);
            }
        }
        return ma;
    }
};