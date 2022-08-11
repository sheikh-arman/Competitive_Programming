// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int sign=(x<0);
        if(sign)x*=-1;
        unsigned int num=0;
        int cnt=0,last=0;
        while(x){
            num=(num*10)+x%10;if(cnt==0)last=x%10;x/=10;cnt++;
        }
        unsigned ans=num;
        if(sign){
            ans*=-1;
            if(num-1>INT_MAX||(cnt>9&&last>2))ans=0;
        }
        else{
            if(num>INT_MAX||((cnt>9&&last>2)))ans=0;
        }
        return ans;
    }
};