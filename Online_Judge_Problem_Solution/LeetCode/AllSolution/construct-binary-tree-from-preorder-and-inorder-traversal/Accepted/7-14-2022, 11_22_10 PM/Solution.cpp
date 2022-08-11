// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

class Solution {
public:
	TreeNode *func(vector<int> &pre, vector<int> &in , unordered_map<int,int> &m, int ind, int leftind, int rightind){
		if(ind>=pre.size() or leftind>rightind) return NULL;// when preorder is fully travered or left ind > right index
    
		TreeNode *root=new TreeNode(pre[ind]);// created new root node where pre[ind] is value of it
    
		int x=m[root->val];//pivot
    
		root->left= func(pre, in, m, ind+1, leftind, x-1);// forming left subtree
		root->right= func(pre, in, m, ind+x-leftind+1, x+1, rightind);// forming right subtree
		return root;
	}

	TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
		int n=pre.size();
		unordered_map<int,int>m;// HashMap increasing by time complexity to O(n)
		for(int i=0;i<n;i++){
			m[in[i]]=i;
		}
		TreeNode *ans=func(pre, in , m, 0, 0, n-1);
		return ans;
	}
};