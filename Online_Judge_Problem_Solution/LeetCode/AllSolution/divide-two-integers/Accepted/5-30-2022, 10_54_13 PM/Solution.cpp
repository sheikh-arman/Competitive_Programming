// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int res=(long long)dividend/(long long)divisor;
        if(res>INT_MAX){
            res=INT_MAX;
        }
        if(res<INT_MIN){
            res=INT_MIN;
        }
        return (int)res;
        
    }
};