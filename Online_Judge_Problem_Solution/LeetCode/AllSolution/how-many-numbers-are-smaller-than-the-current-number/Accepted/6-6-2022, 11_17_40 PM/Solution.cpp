// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int ar[110];
        for(int i=0;i<=100;i++)ar[i]=0;
        for(int i:nums){
            ar[i]++;
        }
        int sum=0;
        for(int i=0;i<=100;i++){
            sum+=ar[i];
            ar[i]=sum;
        }
        vector<int>V;
        for(int i:nums){
            if(i>0){
                V.push_back(ar[i-1]);
            }
            else{
                V.push_back(0);
            }
        }
        return V;
    }
};