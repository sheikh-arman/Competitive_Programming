// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    bool mul(unsigned mid,unsigned divisor,unsigned dividend){
        unsigned num=mid;
        if(mid<divisor){
            swap(mid,divisor);
        }
        cout<<num<<" t\n";
        unsigned res=0,ck=0;
        while(divisor>0){
            if(divisor&1){
                res+=mid;
                divisor--;ck=1;
            }
            if(divisor)
            mid=mid<<1;
            if(mid<0||res>dividend)return 0;
            divisor=divisor>>1;
        }
        cout<<num<<" "<<res<<" "<<dividend<<" xf\n";
      return res<=dividend;
    }
    int divide(int dividend, int divisor) {
        if(dividend==0){
            return 0;
        }
        if(divisor==-1){
            if(dividend<=-2147483647){
                return 2147483647;
            }
            else{
                
            }
        }
        if(divisor==1){
            return dividend;
        }
        int sign=0;
        if((dividend<0||divisor<0)&&!(dividend<0&&divisor<0)){
            sign=1;
        }
        unsigned  new_dividend=abs(dividend);
        unsigned new_divisor=abs(divisor);
        unsigned left=0,right=dividend;
        while(left<=right){
            unsigned mid=left+((right-left)>>1);
            if(mul(mid,divisor,dividend)){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        int ans=right;
        if(sign&&right>0){
            ans=~ans+1;
        }
        return ans;
    }
};