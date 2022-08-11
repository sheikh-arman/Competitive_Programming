// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

class Solution {
private:
    TreeNode* preOrderFlatten(TreeNode *node, TreeNode *appendum){
        if(node==nullptr)
            return appendum;
        
        TreeNode *left_subtree = node->left;
        TreeNode *right_subtree = node->right;
        
        node->left = nullptr;
        TreeNode *flatright = preOrderFlatten(right_subtree, appendum);
        node->right = preOrderFlatten(left_subtree, flatright);
        return node;
    }
public:
    void flatten(TreeNode* root) {
        preOrderFlatten(root, nullptr);
    }
};