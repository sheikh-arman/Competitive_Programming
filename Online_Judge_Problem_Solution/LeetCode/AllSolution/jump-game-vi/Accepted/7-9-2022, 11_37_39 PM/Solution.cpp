// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(dq.size()==0){
                dq.push_back({nums[i],i});
            }
            else{
                int siz=dq.size();
                while(siz>0){
                    if(dq[siz-1].second>i+k){
                        dq.pop_back();siz--;
                    }
                    else{
                        break;
                    }
                }
                siz=dq.size();
                nums[i]+=dq[siz-1].first;
                while(siz>0){
                    if(dq[0].first<=nums[i]){
                        dq.pop_front();siz--;
                    }
                    else{
                        break;
                    }
                }
                dq.push_front({nums[i],i});
            }
        }
        return nums[0];
    }
};