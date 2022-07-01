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
    
    TreeNode* helper(vector<int>& nums, int l, int r)
    {
        if(l > r)   return nullptr;
        
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        if(l == r)
            return node;
        
        node -> left = helper(nums, l, mid - 1);
        node -> right = helper(nums, mid + 1, r);
        
        return node;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, size(nums) - 1);
    }
};