// https://leetcode.com/problems/stone-game-vii

class Solution {
public:
    int mem[1010][1010],cum[1010];
    int dp(int i,int j,vector<int>& stones){
        if(i>=j){
            return 0;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        int ans=0;
        int cost1=cum[j]-cum[i];
        int cost2=cum[j-1];
        if(i>0)cost2-=cum[i-1];
        ans=max(cost1-dp(i+1,j,stones),cost2-dp(i,j-1,stones));
        return mem[i][j]=ans;
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
            cum[i]=sum;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,n-1,stones);
        return ans;
    }
};