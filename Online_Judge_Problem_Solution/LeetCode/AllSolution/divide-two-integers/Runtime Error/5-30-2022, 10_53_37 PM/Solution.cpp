// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int res=dividend/divisor;
        if(res>INT_MAX){
            res=INT_MAX;
        }
        if(res<INT_MIN){
            res=INT_MIN;
        }
        return res;
        
    }
};