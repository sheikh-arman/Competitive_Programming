// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits

class Solution {
public:
    int minimumSum(int num) {
        vector<int>V;
        while(num){
            V.push_back(num%10);
            num/=10;
        }
        sort(V.begin(),V.end());
        int num1=0,num2=0;
        num1=(V[0]*10)+V[3];
        num2=(V[1]*10)+V[2];
        return num1+num2;
    }
};