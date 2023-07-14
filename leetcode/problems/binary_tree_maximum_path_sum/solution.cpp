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

    int ans = -1e9;

    int get_max_sum(TreeNode *root) 
    {
        if(!root)   return 0;
        int l_sum = get_max_sum(root -> left);
        int r_sum = get_max_sum(root -> right);

        ans = max(ans, root -> val + l_sum + r_sum);
        return max(0, (root -> val + max(l_sum, r_sum)));
    }

    int maxPathSum(TreeNode* root) {
        
        get_max_sum(root);
        return ans;
    }
};