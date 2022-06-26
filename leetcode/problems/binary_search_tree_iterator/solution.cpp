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
class BSTIterator {
public:
    
    vector<int> tree;
    int idx;
    
    void inorder(TreeNode * root)
    {
        if(root)
        {
            inorder(root -> left);
            tree.push_back(root -> val);
            inorder(root -> right);
        }
    }
    
    BSTIterator(TreeNode* root) {
        tree.push_back(-1);
        inorder(root);
        idx = 0;
    }
    
    int next() {
        idx++;
        return tree[idx];
    }
    
    bool hasNext() {
        if(idx + 1 < tree.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */