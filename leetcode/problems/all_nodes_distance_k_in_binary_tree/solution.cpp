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
    
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, bool> vis;
    
    void setParent(TreeNode* root, TreeNode* target)
    {
        if(!root || root == target)
            return;
        if(root -> left)
        {
            parent[root -> left] = root;
            setParent(root -> left, target);
        }
        if(root -> right)
        {
            parent[root -> right] = root;
            setParent(root -> right, target);
        }
    }
    
    void dfs(TreeNode* curr, int depth)
    {
        if(curr && !vis[curr])
        {
            vis[curr] = 1;
            
            if(depth == 0)
            {
                ans.push_back(curr -> val);
                return;
            }
            
            dfs(curr -> left, depth - 1);
            dfs(curr -> right, depth - 1);
            
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        parent[root] = nullptr;
        setParent(root, target);
        
        TreeNode* curr = target;
        
        while(k > -1 && curr)
        {
            dfs(curr, k); 
            curr = parent[curr];
            k--;
        }
        
        return ans;
    }
};