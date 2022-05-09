class Solution {
public:
    string rev(string s){
         int n=s.size();
        for(int i=0;i<n/2;i++){
            char ch=s[i];
            s[i]=s[n-i-1];
            s[n-i-1]=ch;
        }
        return s;
    }
    string reverseWords(string s) {
        string res;
        int n=s.size();
        string tm;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                tm+=s[i];
            }
            else{
                tm=rev(tm);
                res+=tm;
                res+=" ";
                tm="";
            }
        }
         tm=rev(tm);
         res+=tm;
        return res;
    }   
};