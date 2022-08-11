// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=1;i<n;i++){
            int siz=triangle[i].size();
            for(int j=0;j<siz;j++){
                if(j==0){
                    triangle[i][j]+=triangle[i-1][j];
                }
                else{
                    if(j<siz-1)
                    triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
                    else
                    triangle[i][j]+=triangle[i-1][j-1];
                }
            }
        }
        int ma=99999999;
        for(int i:triangle[n-1]){
            ma=min(ma,i);
        }
        return ma;
    }
};