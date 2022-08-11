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
    bool rec(TreeNode* root,int val,int ck){
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
                if(!ck){
                    if(left->val<=val)ans=0;
                }
                ans&=rec(left,root->val,0);
            }
        }
        if(right!=NULL){
            if(right->val<=root->val){
                ans=0;
            }
            else{
                if(!ck){
                    if(right->val>=val)ans=0;
                }
                ans&=rec(right,root->val,0);
            }
        }
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        bool ans=rec(root,0,1);
        return ans;
    }
};