// https://leetcode.com/problems/match-substring-after-replacement

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int ar[320][302];
        for(int i=0;i<300;i++){
            for(int j=0;j<300;j++){
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
        for(int i=0;i<sizs;i++){
            int cnt=0;
            for(int j=0;j<siz_sub;j++){
                if(i+j>=sizs)break;
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
                        cnt=0;
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