// https://leetcode.com/problems/swap-for-longest-repeated-character-substring

class Solution {
public:
    int maxRepOpt1(string text) {
        int ar[30];
        for(int i=0;i<26;i++){
            ar[i]=0;
        }
        for(int i=0;text[i]!='\0';i++){
            ar[text[i]-'a']++;
            
        }
        int cnt=0;
        int n=text.size();
        vector<pair<int,int>>V[30];
        for(int i=0;i<n;i++){
            int cur=i;
            int last=i+1;
            while(last<n&&text[last]==text[i])
            {
                last++;
            }     
            V[text[i]-'a'].push_back({i,last-i});
            i=last-1;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            int siz=V[i].size();
            if(siz>0){
                ans=max(ans,V[i][0].second+(ar[i]>V[i][0].second));
                for(int j=1;j<siz;j++){
                    ans=max(ans,V[i][j].second+(ar[i]>V[i][j].second));
                    int dif=V[i][j].first-(V[i][j-1].second+V[i][j-1].first);
                    //cout<<i<<" "<<j<<" "<<dif<<" x\n";
                    if(dif==1){
                        int total=V[i][j].second+V[i][j-1].second;
                       // cout<<i<<" "<<total<<" "<<ar[i]<<" \n";
                        if(ar[i]==total)total-=1;
                        total++;
                        ans=max(ans,total);
                    }
                }
            }
        }
        return ans;
    }
};
//"aaabbaaa"