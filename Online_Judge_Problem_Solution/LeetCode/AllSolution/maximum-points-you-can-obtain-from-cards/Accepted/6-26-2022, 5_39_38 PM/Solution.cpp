// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ar[n];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
            ar[i]=sum;
        }
        int ans=0;
        for(int i=0;i<=k;i++){
            int tm=ar[n-1];
            int pos=(n-(k-i))-1;
            if(pos>=0)tm-=ar[pos];
            if(i>0)tm+=ar[i-1];
            ans=max(ans,tm);
        }
        return ans;
    }
};