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
    int longestZigZag(TreeNode* root) {
        
        auto node = root;
        int ans = 0;
        map<TreeNode*, int> dp[2];

        function<int(TreeNode*, int)> dfs = [&](TreeNode* root, int dir) {

            if(!root)   return 0;

            auto it = dp[dir].find(root);

            if(it != dp[dir].end())
                return it -> second;
            
            int nodes = dir ? dfs(root -> right, 0) : dfs(root -> left, 1);
            return dp[dir][root] = 1 + nodes;
        };

        function<void(TreeNode*)> inorder = [&](TreeNode* root) {

            if(!root)   return;

            inorder(root -> left);

            int l = 1 + dfs(root -> left, 1);
            int r = 1 + dfs(root -> right, 0);
            ans = max({ans, l, r});

            inorder(root -> right);
        };
        inorder(node);

        return ans - 1;
    }
};