// https://leetcode.com/problems/short-encoding-of-words

class Solution {
public:
    bool static cmp(string a,string b){
        return a.size()>b.size();
    }
    int ar[10][30];
    int trie(string s){
        int ck=1;
        int n=s.size();
        for(int i=0;i<n;i++){
            int val=s[i]-'a';
            if(ar[i][val]==0){
                ck=0;
            }
            ar[i][val]=1;
        }
        int ans=0;
        if(ck==0){
            ans=s.size()+1;
        }
        return ans;
    }
    int minimumLengthEncoding(vector<string>& words) {
        for(int i=0;i<10;i++){
            for(int j=0;j<28;j++){
                ar[i][j]=0;
            }
        }
        sort(words.begin(),words.end(),cmp);
        //reverse(words.begin(),words.end());
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<words[i]<<" t\n";
            reverse(words[i].begin(),words[i].end());
            ans+=trie(words[i]);
        }
        return ans;
    }
};