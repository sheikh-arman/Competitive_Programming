// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ma=0;
        int n=triangle.size();
        for(int i=0;i<n;i++){
            int new_ma=INT_MAX;
            for(int j:triangle[i]){
                new_ma=min(new_ma,j+ma);
            }
            ma=new_ma;
        }
        return ma;
    }
};