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

    const int inf = 1e5 + 4;

    int maxLevelSum(TreeNode* root) {
        
        int ans_val = -inf, l = 1, ans_l = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = q.size(), curr = 0;

            for(int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                curr += node -> val;
                if(node -> left)    q.push(node -> left);
                if(node -> right)   q.push(node -> right);
            }

            if(curr > ans_val)
                ans_val = curr, ans_l = l;
            l++;
        }        

        return ans_l;
    }
};