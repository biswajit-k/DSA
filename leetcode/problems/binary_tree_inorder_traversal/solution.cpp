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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;

        while(root)
        {
            if(root -> left)
            {
                TreeNode *trav = root -> left;
                while(trav -> right && trav -> right != root)
                    trav = trav -> right;

                if(trav -> right == nullptr)
                {
                    trav -> right = root;
                    root = root -> left;
                    continue;
                }

                trav -> right = nullptr;
            }

            res.push_back(root -> val);
            root = root -> right;
        }

        return res;
    }
};