// https://leetcode.com/problems/binary-tree-cameras

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
typedef long long int ll;
class Solution {
public:
    ll rec(TreeNode* root,ll status){
        if(root==NULL){
            return 0;
        }
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        ll ans=(status==1);
        ans+=rec(left,1-status);
        ans+=rec(right,1-status);
        return ans;
    }
    int minCameraCover(TreeNode* root) {
        ll ans=rec(root,0);
        ans=min(ans,rec(root,1));
        if(root->left==NULL&&root->right==NULL)ans=1;
        return (int)ans;
    }
};