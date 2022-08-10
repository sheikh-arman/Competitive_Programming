
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
class Solution
{
public:
    void sol(TreeNode* root, int b, int e, vector<int>& nums)
    {
        if(b>=e)
        {
            if(b==e)
            {
                root->val=nums[b];
            }
            return;
        }
        int rt=(b+e)/2;
        root->val=nums[rt];
        if(b<=rt-1)
        {
            TreeNode* lft=new TreeNode();
            root->left=lft;
            sol(lft,b,rt-1,nums);
        }
        if(rt+1<=e)
        {
            TreeNode* rht=new TreeNode();
            root->right=rht;
            sol(rht,rt+1,e,nums);
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        TreeNode* root=new TreeNode();
        int n=nums.size();
        sol(root,0,n-1,nums);
        return root;
    }
};
