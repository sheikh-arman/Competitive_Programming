// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>V;
        for(int i=0;i<=n;i++){
            int num=i;
            int cnt=0;
            while(num>0){
                if(num%2)cnt++;
                num/=2;
            }
            V.push_back(cnt);
        }
        return V;
    }
};