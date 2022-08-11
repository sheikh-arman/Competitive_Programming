// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int sign=(x<0);
        if(sign)x*=-1;
        unsigned int num=0;
        while(x){
            num=(num*10)+x%10;x/=10;
        }
        unsigned ans=num;
        if(sign){
            ans*=-1;
            if(num-1>INT_MAX)ans=0;
        }
        else{
            if(num>INT_MAX)ans=0;
        }
        return ans;
    }
};