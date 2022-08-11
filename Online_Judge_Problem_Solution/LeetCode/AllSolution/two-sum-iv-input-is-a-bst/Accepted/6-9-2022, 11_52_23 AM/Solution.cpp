// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int>mp;
     bool rec(TreeNode* root,int k){
        if(root==NULL){
            return 0;
        }
        if(mp.count(k-root->val)==0){
            mp[root->val]=1;
        }
         else{
             return 1;
         }
        bool ans=0;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        if(left!=NULL){
            ans|=rec(left,k);
        }
        if(right!=NULL){
               ans|=rec(right,k);
        }
        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans=rec(root,k);
        return ans;
    }
};