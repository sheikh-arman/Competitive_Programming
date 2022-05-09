class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        vector<int>V;
        int cnt=0;
        for(int i:nums){
         if(i==0){
             cnt++;
         }   
        else{
            V.push_back(i);
        }
        }
        for(int i=0;i<cnt;i++){
            V.push_back(0);
        }
        nums=V;
    }
};