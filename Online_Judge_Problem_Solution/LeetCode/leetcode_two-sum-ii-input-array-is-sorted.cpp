class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
     int n=numbers.size();
     int l=0,r=n-1;
     while(l<r){
         int sum=numbers[l]+numbers[r];
         if(sum==target){
             break;
         }
         else if(sum>target){
             r--;
         }
         else{
             l++;
         }
     }
    vector<int>V;
    V.push_back(l+1);
    V.push_back(r+1);
    return V;
    }
};