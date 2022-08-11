// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) {
        int ar[n+3];
        ar[0]=0;
        ar[1]=1;
        int ma=0;
        for(int i=1;i<=n;i++){
            int ne=i*2;
            int ne2=ne+1;
            if(ne<=n)ar[ne]=ar[i];
            if(ne2<=n){
                ar[ne2]=ar[i]+ar[i+1];
            }
        }
        for(int i=0;i<=n;i++){
            ma=max(ma,ar[i]);
        }
        return ma;
    }
};