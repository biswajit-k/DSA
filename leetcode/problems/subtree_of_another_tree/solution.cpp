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
    
    bool preorder(TreeNode* root, TreeNode* sub_root)
    {
        if((root == nullptr) ^ (sub_root == nullptr))
            return 0;
        
        if(root)
        {
            bool check = (root -> val == sub_root -> val) && preorder(root -> left, sub_root -> left) && preorder(root -> right, sub_root -> right);
            
            return check;
        }
        
        return 1;
    }
    
    bool checkTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root)
        {
            return (preorder(root, subRoot) || checkTree(root -> left, subRoot) || checkTree(root -> right, subRoot));
        }
        
        return 0;
    }

    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return checkTree(root, subRoot);
        
    }
};