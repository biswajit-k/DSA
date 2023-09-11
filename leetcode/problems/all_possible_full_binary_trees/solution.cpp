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

    // think about how would it test this code

    unordered_map<int, vector<TreeNode*>> full_tree_cache;

    vector<TreeNode*> allPossibleFBT(int n) {

        if(full_tree_cache.find(n) != full_tree_cache.end())
            return full_tree_cache[n];

        vector<TreeNode*> trees;

        // base case when n is 1
        if(n == 1)
            trees.push_back(new TreeNode());
        else
        {
            for(int i = 1; i <= n - 2; i += 2)
            {       
                for(auto& left_root: allPossibleFBT(i))
                {
                    for(auto& right_root: allPossibleFBT(n - 1 - i))
                    {
                        TreeNode *root = new TreeNode();
                        root -> left = left_root;
                        root -> right = right_root;
                        trees.push_back(root);
                    }
                }
            }
        }
        
        return full_tree_cache[n] = trees;
    }
};