// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&](auto&& dfs, TreeNode* now, int d) {
            if (now == nullptr) return;
            if (ans.size() <= d) ans.push_back(now->val);
            dfs(dfs, now->right, d + 1);
            dfs(dfs, now->left, d + 1);
        };
        dfs(dfs, root, 0);
        return ans;
    }
};