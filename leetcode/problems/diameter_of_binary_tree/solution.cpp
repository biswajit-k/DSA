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
    
    int ans;

    int getLength(TreeNode* root)
    {
        if(!root)   return 0;
        int l = getLength(root -> left);
        int r = getLength(root -> right);
        ans = max(ans, l + r);
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        getLength(root);
        return ans;
    }
};