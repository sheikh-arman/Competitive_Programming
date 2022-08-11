// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    long long mem[100010];
    string s;
    int n,mod=1e9+7;
    vector<string>V;
    map<pair<int,int>,string>mp;
    void dp(int i,string s1) {
        if (i>=n){
            V.push_back(s1);return;
        } 
        s1+=mp[{s[i]-'0',0}];
        for(int j=0;j<3;j++){
            int siz=s1.size();
            s1.erase(s1.end()-1);
            s1+=mp[{s[i]-'0',j}];
            dp(i+1,s1);
        }
        if(s[i]=='7'||s[i]=='9'){
            int siz=s1.size();
            s1.erase(s1.end()-1);
            s1+=mp[{s[i]-'0',3}];
            dp(i+1,s1);
        }     
    }
    vector<string> letterCombinations(string digits) {
        for(int i=2;i<=6;i++){
            for(int j=0;j<3;j++){
                string x;
                x+=(char)((((i-2)*3)+j)+'a');
                mp[{i,j}]=x;
            }
        }
        mp[{7,0}]="p";
        mp[{7,1}]="q";
        mp[{7,2}]="r";
        mp[{7,3}]="s";
        mp[{8,0}]="t";
        mp[{8,1}]="u";
        mp[{8,2}]="v";
        mp[{9,0}]="w";
        mp[{9,1}]="x";
        mp[{9,2}]="y";
        mp[{9,3}]="z";
        s=digits;
        n=s.size();
        string tm;
        dp(0,tm);
        return V;
    }
};