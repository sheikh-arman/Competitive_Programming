// https://leetcode.com/problems/maximum-number-of-points-with-cost

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int ma=0;
                for(int k=0;k<m;k++){
                    int tm=points[i-1][k]-abs(k-j);
                    ma=max(ma,tm);
                }
                points[i][j]+=ma;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,points[n-1][i]);
        }
        return ans;
    }
};