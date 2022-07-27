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
    
    TreeNode* flatter(TreeNode* node) {

        TreeNode *end = node;
        TreeNode *temp = node -> right;
        
        if(node -> left)
        {
            node -> right = node -> left;
            end = flatter(node -> left);
            node -> left = nullptr;
        }
        if(temp)
        {
            end -> right = temp;
            end = flatter(temp);
        }
        
        return end;
    }
    
    void flatten(TreeNode* root) {
        if(root)
            flatter(root);
    }
};