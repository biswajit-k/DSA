/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* traversal(TreeNode* root, int x)
    {
        if(root == NULL)
            return root;
        if(root -> val == x)
            return root;
        TreeNode* now = traversal(root -> left, x), then = NULL, fi;
        fi = then;
        if(!now)
            now = traversal(root -> right, x);
        return now;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        return traversal(cloned, target -> val);
        
    }
};