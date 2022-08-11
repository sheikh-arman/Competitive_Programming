// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode* ans=new TreeNode();
    void sol(TreeNode* root, TreeNode* target)
    {
        if(root->val==target->val)
        {
            ans=root;
            return;
        }
        if(root->left!=NULL)
        {
            sol(root->left,target);
        }
        if(root->right!=NULL)
        {
            sol(root->right,target);
        }
    }
     void sol2(TreeNode* root, TreeNode* target)
    {
        if(root->val==target->val)
        {
            ans=root;
            return;
        }
        if(root->left!=NULL)
        {
            sol2(root->left,target);
        }
        if(root->right!=NULL)
        {
            sol2(root->right,target);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        sol(cloned,target);
        //sol2(cloned,target);
        return ans;
    }
};
