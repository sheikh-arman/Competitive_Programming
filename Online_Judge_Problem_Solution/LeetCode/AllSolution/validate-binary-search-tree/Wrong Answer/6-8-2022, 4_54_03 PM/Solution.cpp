// https://leetcode.com/problems/validate-binary-search-tree

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
    bool rec(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        bool ans=1;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        if(left!=NULL){
            if(left->val>=root->val){
                ans=0;
            }
            else{
                ans&=rec(left);
            }
        }
        if(right!=NULL){
            if(right->val<=root->val){
                ans=0;
            }
            else{
                ans&=rec(right);
            }
        }
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        bool ans=rec(root);
        return ans;
    }
};