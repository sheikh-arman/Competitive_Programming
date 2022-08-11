// https://leetcode.com/problems/match-substring-after-replacement

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int ar[220][202];
        for(int i=0;i<200;i++){
            for(int j=0;j<200;j++){
                ar[i][j]=0;
            }
        }
        int n= mappings.size();
        for(int i=0;i<n;i++){
            int u=(int)mappings[i][0];
            int v=(int)mappings[i][1];
            ar[u][v]=1;
        }
        int sizs=s.size();
        int siz_sub=sub.size();
        for(int i=0;i<sizs-siz_sub;i++){
            int cnt=0;
            for(int j=0;j<siz_sub;j++){
                if(s[i+j]==sub[j]){
                    cnt++;
                }
                else {
                    int u=(int)sub[j];
                    int v=(int)s[i+j];
                    if(ar[u][v]==1){
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
            }
            if(cnt>=siz_sub){
                return 1;
            }
        }
        return 0;
    }
};