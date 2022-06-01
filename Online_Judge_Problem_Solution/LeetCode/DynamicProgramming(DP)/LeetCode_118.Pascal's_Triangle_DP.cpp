/*
    Sk arman Hossain
    University of Barisal

    Problem: 118. Pascal's Triangle
    Solution : dp(ittreative)
 */

class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>V;
        if(numRows==0)return V;
        V.push_back({1});
        if(numRows==1)return V;
        V.push_back({1,1});
        if(numRows==2)return V;
        for(int i=2;i<numRows;i++){
                V.push_back({1});
            for(int j=1;j<i;j++){
                V[i].push_back(V[i-1][j-1]+V[i-1][j]);
            }
            V[i].push_back(1);
        }
        return V;
    }
};
