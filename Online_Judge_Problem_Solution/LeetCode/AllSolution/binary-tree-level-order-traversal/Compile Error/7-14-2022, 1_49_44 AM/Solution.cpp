// https://leetcode.com/problems/binary-tree-level-order-traversal

class Solution {
public:
vector<vector> levelOrder(TreeNode* root) {
vector<vector> ans;
if(!root) return ans;
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
vector level;
int size = q.size();
for(int i=0;i<size;i++){
TreeNode* node = q.front();
q.pop();
if(node->left!=NULL) q.push(node->left);
if(node->right!=NULL)q.push(node->right);
level.push_back(node->val);
}
ans.push_back(level);
}
return ans;
}
};