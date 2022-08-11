// https://leetcode.com/problems/root-equals-sum-of-children

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
    bool sol(TreeNode* root){
        if(root==NULL||root->left==NULL){
            return true;
        }
        int ans=1;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        
        if(root->val==(left->val+right->val)){
            ans&=sol(left);
            ans&=sol(right);
        }
        else{
            return false;
        }
        return ans;
    }
public:
    bool checkTree(TreeNode* root) {
        bool ans=sol(root);
        return ans;
    }
};