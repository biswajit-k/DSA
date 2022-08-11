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
    
    vector<int> nodes;
    
    void inorder(TreeNode* root)
    {
        if(!root)   return;
        inorder(root -> left);
        nodes.push_back(root -> val);
        inorder(root -> right);
    }
    
    bool isValidBST(TreeNode* root) {
        
        inorder(root);
        vector<int> sorted(nodes);
        sort(begin(sorted), end(sorted));
        sorted.resize(unique(begin(sorted), end(sorted)) - begin(sorted));
        return (nodes == sorted);
        
    }
};