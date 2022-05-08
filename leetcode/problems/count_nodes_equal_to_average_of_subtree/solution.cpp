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
	int cnt = 0;
	pair<int, int> doit(TreeNode* root) {

		if(root == NULL)
			return {0, 0};

		// if(root -> left == NULL && root -> right == NULL)
		// 	return {root -> val, 1};
		
		auto i1 = doit(root -> left), i2 = doit(root -> right);

		int sum = root -> val + i1.first + i2.first, tot = i1.second + i2.second + 1;
		
		if(sum / tot == root -> val)
			cnt++;

		return {sum, tot};
	}

    int averageOfSubtree(TreeNode* root) {
		auto it = doit(root);

		return cnt;
    }
};