// https://leetcode.com/problems/count-vowel-substrings-of-a-string

class Solution {
public:
    int countVowelSubstrings(string word) {
        vector<int>V;
        V.push_back('a'-'a');
        V.push_back('e'-'a');
        V.push_back('i'-'a');
        V.push_back('o'-'a');
        V.push_back('u'-'a');
        int n=word.size();
        int ar[n+3][30];
        for(int i=0;i<=n;i++){
            for(int j=0;j<26;j++){
                ar[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            ar[i][word[i]-'a']++;
            if(i>0){
                for(int j=0;j<26;j++){
                    ar[i][j]+=ar[i-1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+4;j<n;j++){
                int ck=1,sum=0;
                for(int k:V){
                    int cnt=ar[j][k];
                    if(i>0){
                        cnt-=ar[i-1][k];
                    }
                    if(cnt<=0){
                        ck=0;
                    }
                    sum+=cnt;
                }
                int sum_tm=0;
                for(int k=0;k<26;k++){
                    int cnt=ar[j][k];
                    if(i>0){
                        cnt-=ar[i-1][k];
                    }
                    sum_tm+=cnt;
                }
                sum_tm-=sum;
                if(sum_tm>0){
                    ck=0;
                }
                if(ck)ans++;
            }
        }
        return ans;
        
    }
};