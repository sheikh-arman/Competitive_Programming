// https://leetcode.com/problems/count-vowels-permutation

typedef long long int ll;
class Solution {
public:
    ll mem[20010][7];
    ll mod=1e9+7;
    int countVowelPermutation(int n) {
        mem[0][0]=mem[0][1]=mem[0][2]=mem[0][3]=mem[0][4]=1;
        for(int i=1;i<n;i++){
            mem[i][0]=(mem[i-1][1]+mem[i-1][4]+mem[i-1][2])%mod;
            mem[i][1]=(mem[i-1][0]+mem[i-1][2])%mod;
            mem[i][2]=(mem[i-1][1]+mem[i-1][3])%mod;
            mem[i][3]=(mem[i-1][2])%mod;
            mem[i][4]=(mem[i-1][3]+mem[i-1][2])%mod;   
        }
        int ans=0;
        for(int i=0;i<5;i++){
            ans+=mem[n-1][i];
        }
        ans%=mod;
        return ans;
    }
};