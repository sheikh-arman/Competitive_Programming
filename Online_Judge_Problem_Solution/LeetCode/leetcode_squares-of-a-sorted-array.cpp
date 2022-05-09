class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>V;
        for(int i:nums){
            V.push_back(i*i);
        }
        sort(V.begin(),V.end());
        return V;
    }
};