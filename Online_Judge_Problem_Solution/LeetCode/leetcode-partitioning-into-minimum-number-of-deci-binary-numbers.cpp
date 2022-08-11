// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int x=0;for(int i=0;n[i]!='\0';i++){x=max(x,n[i]-'0');}return x;
    }
};