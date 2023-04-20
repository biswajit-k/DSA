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
    typedef pair<long, TreeNode*> pin;
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pin> q;
        q.push({0, root});

        long ans = 0;
        while(!q.empty())
        {
            ans = max(ans, q.back().first - q.front().first + 1);
            int sz = q.size(), start = q.front().first;

            for(int i = 0; i < sz; i++)
            {
                auto [c_id, node] = q.front();
                c_id -= start;
                q.pop();

                if(node -> left)
                    q.push({c_id * 2, node -> left});
                if(node -> right)
                    q.push({2 * c_id + 1, node -> right});
            }

        }
        return ans;
    }
};