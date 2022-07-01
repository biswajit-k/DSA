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
    
    TreeNode* getNode(int x)
    {
        TreeNode* node = new TreeNode(x);
        return node;
    }
    
    vector<TreeNode*> helper(int l, int r)
    {
        if(l > r)
            return {nullptr};
        if(l == r)
            return {getNode(l)};
        
        vector<TreeNode*> res;
        
        for(int i = l; i <= r; i++)
        {
            auto left = helper(l, i - 1);
            auto right = helper(i + 1, r);
            
            for(auto& l_node: left)
                for(auto& r_node: right)
                {
                    auto root = getNode(i);
                    root -> left = l_node;
                    root -> right = r_node;
                    res.push_back(root);
                }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};