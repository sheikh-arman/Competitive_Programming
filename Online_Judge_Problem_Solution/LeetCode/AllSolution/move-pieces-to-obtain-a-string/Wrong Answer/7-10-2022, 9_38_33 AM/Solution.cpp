// https://leetcode.com/problems/move-pieces-to-obtain-a-string

class Solution {
public:
    bool canChange(string start, string target) {
        int under_start=0,under_target=0,l_target=0,r_start=0;
        int n=start.size();
        bool ans=1;
        for(int i=0;i<n;i++){
            if(target[i]==start[i]){
                if(target[i]=='L'){
                    if(r_start>0){
                        ans=0;break;
                    }
                }
                continue;
            }
            else{
                if(target[i]=='L'){
                    l_target++;
                    if(start[i]=='_'){
                        if(r_start>0){
                            ans=0;break;
                        }
                        under_start++;
                    }
                    else{
                        ans=0;break;
                    }
                }
                else if(target[i]=='R'){
                    if(under_start==under_target&&under_start==0&&l_target==0){
                        if(start[i]=='L'){
                            ans=0;break;
                        }
                        else{
                            if(r_start>0){
                                r_start--;
                            }
                            else{
                                ans=0;break;
                            }
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    under_target++;
                    if(start[i]=='L'){
                        if(l_target>0){
                            l_target--;
                        }
                        else{
                            ans=0;break;
                        }
                    }
                    else{
                        r_start++;
                    }
                }
            }
        }
        return ans;
    }
};