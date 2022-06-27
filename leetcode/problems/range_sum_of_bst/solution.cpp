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
    
    int ans = 0;
    
    void inorder(TreeNode* root, int low, int high)
    {
        if(root)
        {
            int x = root -> val;
            if(x <= high and x >= low)
                ans += x;
            if(x >= low)    inorder(root -> left, low, high);
            if(x <= high)   inorder(root -> right, low, high);
            
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root, low, high);
        return ans;
    }
};