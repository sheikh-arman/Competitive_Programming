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
    TreeNode* ans;
    void sol(TreeNode* root, TreeNode* target)
    {
        if(root->val==target->val)
        {
            ans=root;
            return;
        }
        if(root->left!=NULL)
        {
            sol(root->left);
        }
        if(root->right!=NULL)
        {
            sol(root->right);
        }
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        return sol(orginal,target);
    }
};
