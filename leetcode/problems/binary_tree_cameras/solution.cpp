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

    const int inf = 1001;
    map<TreeNode*, array<int, 3>> dp; 

    void dfs(TreeNode* x) {
        TreeNode *c1 = x -> left, *c2 = x -> right;

        if(c1)  dfs(c1);
        if(c2)  dfs(c2);

        dp[x][2] = (c1 ? dp[c1][0] : 0) + (c2 ? dp[c2][0] : 0);
        dp[x][1] = 1 + (c1 ? *min_element(begin(dp[c1]), end(dp[c1])) : 0) + (c2 ? *min_element(begin(dp[c2]), end(dp[c2])) : 0);

        dp[x][0] = inf;
        if(c1 && !c2)   dp[x][0] = min(dp[x][0], dp[c1][1]);
        if(!c1 && c2)   dp[x][0] = min(dp[x][0], dp[c2][1]);
        if(c1 && c2)    dp[x][0] = min({dp[x][0], dp[c1][1] + dp[c2][1], dp[c1][0] + dp[c2][1], dp[c1][1] + dp[c2][0]});
        
    }

    int minCameraCover(TreeNode* root) {

        dfs(root);
        return min(dp[root][0], dp[root][1]);
    }
};