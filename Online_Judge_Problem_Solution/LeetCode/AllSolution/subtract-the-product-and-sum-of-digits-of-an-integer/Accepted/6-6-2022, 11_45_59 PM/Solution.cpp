// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul=1,sum=0;
        while(n){
            int mod=n%10;
            n/=10;
            mul*=mod;
            sum+=mod;
        }
        return mul-sum;
    }
};