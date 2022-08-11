// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        int n=sentences.size();
        for(int i=0;i<n;i++){
            int tm=0,ck=0;
            for(int j=0;sentences[i][j]!='\0';j++){
                if(sentences[i][j]==' '){
                    tm++;
                }
                ck=1;
            }
            tm+=ck;
            ans=max(ans,tm);
        }
        return ans;
    }
};