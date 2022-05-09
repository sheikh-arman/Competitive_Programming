class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>V;
        int len=nums.size();
        k=k%len;
        int part=len-k;
        for(int i=part;i<len;i++){
            V.push_back(nums[i]);
        }
        for(int i=0;i<part;i++){
            V.push_back(nums[i]);
        }
        nums=V;
    }
};