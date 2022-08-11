// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    bool mul(int mid,int divisor,int dividend){
        int num=mid;
        int res=0;
        while(divisor>0){
            if(divisor&1){
                res+=mid;
                divisor--;
            }
            mid=mid<<1;
            divisor=divisor>>1;
            if(res<=0){
                return 0;
            }
        }
        //cout<<mid<<" "<<res<<" "<<dividend<<" xf\n";
      return res<=dividend;
    }
    int divide(int dividend, int divisor) {
        if(dividend==0){
            return 0;
        }
        int sign=0;
        if((dividend<0||divisor<0)&&!(dividend<0&&divisor<0)){
            sign=1;
        }
       dividend=abs(dividend);
        divisor=abs(divisor);
        int left=0,right=dividend;
        while(left<=right){
            cout<<left<<" "<<right<<" x\n";
            int mid=left+((right-left)>>1);
            if(mul(mid,divisor,dividend)){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        if(sign&&right>0){
            right=~right+1;
        }
        return right;
    }
};